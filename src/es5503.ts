/** Copyright 2017 Sean Kasun */

enum Mode {
  freeRun = 0,
  oneShot = 1,
  sync = 2,
  swap = 3,
}

class Oscillator {
  public pointer: number = 0;
  public frequency: number = 0;
  public size: number = 0;
  public control: number = 1;
  public volume: number = 0;
  public data: number = 0;
  public resolution: number = 0;
  public accumulator: number = 0;
  public ptr: number = 0;
  public shift: number = 9;
  public max: number = 0xff;
}

class ES5503 {
  private waveTable: Float32Array = new Float32Array(0x10000);
  private oscillators: Oscillator[] = [];
  private irq: (osc: number) => void;
  private enabled: number = 0;
  private waveSizes: number[] = [
    0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000,
  ];
  private waveMasks: number[] = [
    0x1ff00, 0x1fe00, 0x1fc00, 0x1f800, 0x1f000, 0x1e000, 0x1c000, 0x18000,
  ];

  constructor(irq: (osc: number) => void) {
    this.irq = irq;
    for (let i: number = 0; i < 32; i++) {
      this.oscillators.push(new Oscillator());
    }
  }

  public setEnabled(enabled: number): void {
    this.enabled = enabled >> 1;
  }

  public setRam(bank: Uint8Array): void {
    for (let i: number = 0; i < bank.length; i++) {
      this.waveTable[i] = (bank[i] - 128) / 128;
    }
  }

  public setFrequency(osc: number, freq: number): void {
    this.oscillators[osc].frequency = freq;
  }

  public setVolume(osc: number, vol: number): void {
    this.oscillators[osc].volume = vol / 127;
  }

  public setPointer(osc: number, ptr: number): void {
    this.oscillators[osc].pointer = ptr << 8;
    this.recalc(osc);
  }

  public setSize(osc: number, size: number): void {
    this.oscillators[osc].size = (size >> 3) & 7;
    this.oscillators[osc].resolution = size & 7;
    this.recalc(osc);
  }

  public setControl(osc: number, ctl: number): void {
    const prev: number = this.oscillators[osc].control & 1;
    this.oscillators[osc].control = ctl;
    const mode: Mode = (ctl >> 1) & 3;
    // newly triggered?
    if (!(ctl & 1) && prev) {
      if (mode == Mode.sync) {  // trigger pair?
        this.oscillators[osc ^ 1].control &= ~1;
        this.oscillators[osc ^ 1].accumulator = 0;
      }
      this.oscillators[osc].accumulator = 0;
    }
  }

  // halt oscillator without triggering interrupt
  public stop(osc: number): void {
    this.oscillators[osc].control &= 0xf7;  // clear interrupt bit
    this.oscillators[osc].control |= 1;
    this.oscillators[osc].accumulator = 0;
  }

  // unhalt oscillator without triggering swap
  public go(osc: number): void {
    this.oscillators[osc].control &= ~1;
  }

  public tick(): void {
    for (let osc: number = 0; osc <= this.enabled; osc++) {
      const cur: Oscillator = this.oscillators[osc];
      if (!(cur.control & 1)) {  // running?
        const base: number = cur.accumulator >> cur.shift;
        const ofs: number = (base & cur.max) + cur.ptr;
        cur.data = this.waveTable[ofs] * cur.volume;

        cur.accumulator += cur.frequency;
        if (this.waveTable[ofs] == -1) {  // same as 0 in the data
          this.halted(osc, true);
        } else if (base >= cur.max) {
          this.halted(osc, false);
        }
      }
    }
  }

  public render(): [number, number] {
    let left: number = 0;
    let right: number = 0;
    for (let osc: number = 0; osc <= this.enabled; osc++) {
      const cur: Oscillator = this.oscillators[osc];
      if (!(cur.control & 1)) {
        if (cur.control & 0x10) {
          right += cur.data;
        } else {
          left += cur.data;
        }
      }
    }
    const spread: number = (this.enabled - 2) / 4;
    return [left / spread, right / spread];
  }

  private recalc(osc: number): void {
    const cur: Oscillator = this.oscillators[osc];
    cur.shift = (cur.resolution + 9) - cur.size;
    cur.ptr = cur.pointer & this.waveMasks[cur.size];
    cur.max = this.waveSizes[cur.size] - 1;
  }

  private halted(osc: number, interrupted: boolean) {
    const cur: Oscillator = this.oscillators[osc];
    const mode: Mode = (cur.control >> 1) & 3;
    if (interrupted || mode != Mode.freeRun) {
      cur.control |= 1;  // halt oscillator
    } else {
      const base: number = (cur.accumulator >> cur.shift) - cur.max;
      cur.accumulator = Math.max(base, 0) << cur.shift;
    }
    if (mode == Mode.swap) {
      const swap: Oscillator = this.oscillators[osc ^ 1];
      swap.control &= ~1;  // enable pair
      swap.accumulator = 0;
    }
    if (cur.control & 8) {  // should we interrupt?
      this.irq(osc);
    }
  }
}
