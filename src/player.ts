/** Copyright 2017 Sean Kasun */

class Player {
  private es5503: ES5503;
  private ctx?: AudioContext;
  private audioNode?: ScriptProcessorNode;
  private stereo: boolean = true;

  private timer: number = 0;
  private tempo: number = 0;
  private curRow: number = 0;
  private curPat: number = 0;
  private orders: number[] = [];
  private volTable: number[] = [];
  private rowOffset: number = 0;
  private numInst: number = 0;
  private ticksLeft: number = 0;
  private notes: Uint8Array;
  private effects1: Uint8Array;
  private effects2: Uint8Array;
  private instruments: Uint8Array[] = [];
  private compactTable: Uint16Array = new Uint16Array(16);
  private stereoTable: Uint16Array = new Uint16Array(16);
  private curInst: Uint8Array = new Uint8Array(16);
  private arpeggio: Uint8Array = new Uint8Array(16);
  private tone: Uint8Array = new Uint8Array(16);
  private notice: (pat: number, max: number) => void;
  private frequencies: number[] = [
    0x0000, 0x0016, 0x0017, 0x0018, 0x001a, 0x001b, 0x001d, 0x001e,
    0x0020, 0x0022, 0x0024, 0x0026, 0x0029, 0x002b, 0x002e, 0x0031,
    0x0033, 0x0036, 0x003a, 0x003d, 0x0041, 0x0045, 0x0049, 0x004d,
    0x0052, 0x0056, 0x005c, 0x0061, 0x0067, 0x006d, 0x0073, 0x007a,
    0x0081, 0x0089, 0x0091, 0x009a, 0x00a3, 0x00ad, 0x00b7, 0x00c2,
    0x00ce, 0x00d9, 0x00e6, 0x00f4, 0x0102, 0x0112, 0x0122, 0x0133,
    0x0146, 0x015a, 0x016f, 0x0184, 0x019b, 0x01b4, 0x01ce, 0x01e9,
    0x0206, 0x0225, 0x0246, 0x0269, 0x028d, 0x02b4, 0x02dd, 0x0309,
    0x0337, 0x0368, 0x039c, 0x03d3, 0x040d, 0x044a, 0x048c, 0x04d1,
    0x051a, 0x0568, 0x05ba, 0x0611, 0x066e, 0x06d0, 0x0737, 0x07a5,
    0x081a, 0x0895, 0x0918, 0x09a2, 0x0a35, 0x0ad0, 0x0b75, 0x0c23,
    0x0cdc, 0x0d9f, 0x0e6f, 0x0f4b, 0x1033, 0x112a, 0x122f, 0x1344,
    0x1469, 0x15a0, 0x16e9, 0x1846, 0x19b7, 0x1b3f, 0x1cde, 0x1e95,
    0x2066, 0x2254, 0x245e, 0x2688,
  ];

  constructor(music: Handle, wavebank: Handle,
              notice: (pat: number, max: number) => void) {
    this.notice = notice;
    this.es5503 = new ES5503((osc: number): void => { this.irq(osc); });

    this.loadWavebank(wavebank);

    music.seek(6);
    const blockLen: number = music.r16();
    this.tempo = music.r16();
    this.es5503.setFrequency(30, 0xfa);
    this.es5503.setVolume(30, 0);
    this.es5503.setPointer(30, 0);
    this.es5503.setSize(30, 0);
    this.es5503.setEnabled(0x3c);
    this.es5503.setControl(30, 8);  // freerun + interrupts - halt

    music.seek(0x2c);
    for (let i: number = 0; i < 15; i++) {
      this.volTable.push(music.r16());
      music.skip(0x1c);
    }

    music.seek(0x1d6);
    const songLen: number = music.r16() & 0xff;
    for (let i: number = 0; i < songLen; i++) {
      this.orders.push(music.r8() * 64 * 14);
    }

    music.seek(0x258);
    this.notes = music.read(blockLen);
    this.effects1 = music.read(blockLen);
    this.effects2 = music.read(blockLen);
    for (let i: number = 0; i < 16; i++) {
      this.stereoTable[i] = music.r16();
    }

    this.rowOffset = this.orders[this.curPat];
    this.notice(this.curPat + 1, this.orders.length);
  }

  public play(): void {
    try {
      this.ctx = new AudioContext();
    } catch (e) {
      alert('No audio support');
      return;
    }
    this.audioNode = this.ctx.createScriptProcessor(0, 0, 2);
    this.audioNode.onaudioprocess = (evt: AudioProcessingEvent) => {
      this.render(evt);
    };
    this.audioNode.connect(this.ctx.destination);
  }

  public stop(): void {
    if (this.audioNode) {
      this.audioNode.disconnect();
    }
    this.audioNode = undefined;
    if (this.ctx) {
      this.ctx.close();
    }
    this.ctx = undefined;
  }

  private loadWavebank(wavebank: Handle): void {
    wavebank.seek(0);
    if (wavebank.r4() == 'GSWV') {  // gswv wavebank
      const ofs: number = wavebank.r16();
      this.numInst = wavebank.r8();
      wavebank.skip(this.numInst * 10);  // skip instrument names
      for (let i: number = 0; i < this.numInst; i++) {
        const instLen: number = (wavebank.r8() + wavebank.r8()) * 6;
        this.instruments.push(wavebank.read(instLen));
      }
      wavebank.seek(ofs);
      const tbl: Uint8Array = new Uint8Array(0x10000);
      tbl.set(wavebank.read(wavebank.length - ofs));
    } else {  // regular wavebank
      wavebank.seek(0);
      this.numInst = wavebank.r16() & 0xff;
      this.es5503.setRam(wavebank.read(0x10000));

      wavebank.seek(0x10022);
      for (let i: number = 0; i < this.numInst; i++) {
        this.instruments.push(wavebank.read(12));
        wavebank.skip(0x50);
      }
      wavebank.skip(0x3c);
      for (let i: number = 0; i < 16; i++) {
        this.compactTable[i] = wavebank.r16();
      }
    }
  }

  private render(evt: AudioProcessingEvent): void {
    const sampleRate: number = evt.outputBuffer.sampleRate;
    const leftBuf: Float32Array = evt.outputBuffer.getChannelData(0);
    const rightBuf: Float32Array = evt.outputBuffer.getChannelData(1);

    for (let i: number = 0; i < evt.outputBuffer.length; i++) {
      // Oscillators update at 26320 Hz
      this.ticksLeft -= 26320;
      if (this.ticksLeft <= 0) {
        this.ticksLeft += sampleRate;
        this.es5503.tick();
      }

      const [left, right] = this.es5503.render();
      if (!this.stereo) {  // mix down to mono
        leftBuf[i] = (left + right) * 0.707;
        rightBuf[i] = leftBuf[i];
      } else {
        leftBuf[i] = left;
        rightBuf[i] = right;
      }
    }
  }

  private irq(osc: number): void {
    if (osc != 30) {  // not a timer
      this.es5503.go(osc);
      return;
    }

    this.timer++;
    if (this.timer == this.tempo) {
      this.timer = 0;
      for (let oscillator: number = 0; oscillator < 14; oscillator++) {
        const semitone: number = this.notes[this.rowOffset];
        if (semitone == 0 || (semitone & 0x80)) {
          this.rowOffset++;
          if (semitone == 0x80) {
            this.es5503.setControl(oscillator * 2, 1);  // halt
            this.es5503.setControl(oscillator * 2 + 1, 1);  // halt pair
          } else if (semitone == 0x81) {
            this.curRow = 0x3f;
          }
        } else {
          let fx: number = this.effects1[this.rowOffset];
          if (fx & 0xf0) {  // change instrument?
            this.curInst[oscillator] = (fx >> 4) - 1;
          }
          const inst: number = this.curInst[oscillator];
          let volume: number = this.volTable[inst] >> 1;
          fx &= 0xf;
          if (fx == 0) {
            this.arpeggio[oscillator] = this.effects2[this.rowOffset];
            this.tone[oscillator] = semitone;
          } else {
            this.arpeggio[oscillator] = 0;
            if (fx == 3) {
              volume = this.effects2[this.rowOffset] >> 1;
              this.es5503.setVolume(oscillator * 2, volume);
              this.es5503.setVolume(oscillator * 2 + 1, volume);
            } else if (fx == 6) {
              volume -= this.effects2[this.rowOffset] >> 1;
              volume = Math.max(volume, 0);
              this.es5503.setVolume(oscillator * 2, volume);
              this.es5503.setVolume(oscillator * 2 + 1, volume);
            } else if (fx == 5) {
              volume += this.effects2[this.rowOffset] >> 1;
              volume = Math.min(volume, 0x7f);
              this.es5503.setVolume(oscillator * 2, volume);
              this.es5503.setVolume(oscillator * 2 + 1, volume);
            } else if (fx == 0xf) {
              this.tempo = this.effects2[this.rowOffset];
            }
          }

          const addr: number = oscillator * 2;
          this.es5503.stop(addr);
          this.es5503.stop(addr + 1);
          if (inst < this.numInst) {
            let x = 0;
            while (this.instruments[inst][x] < semitone) {
              x += 6;
            }
            const oscAptr: number = this.instruments[inst][x + 1];
            const oscAsiz: number = this.instruments[inst][x + 2];
            let oscActl: number = this.instruments[inst][x + 3] & 0xf;
            if (this.stereoTable[oscillator]) {
              oscActl |= 0x10;
            }
            while (this.instruments[inst][x] != 0x7f) {
              x += 6;
            }
            x += 6;  // skip last
            while (this.instruments[inst][x] < semitone) {
              x += 6;
            }
            const oscBptr: number = this.instruments[inst][x + 1];
            const oscBsiz: number = this.instruments[inst][x + 2];
            let oscBctl: number = this.instruments[inst][x + 3] & 0xf;
            if (this.stereoTable[oscillator]) {
              oscBctl |= 0x10;
            }
            const freq: number = this.frequencies[semitone] >>
                this.compactTable[inst];
            this.es5503.setFrequency(addr, freq);
            this.es5503.setFrequency(addr + 1, freq);  // pair
            this.es5503.setVolume(addr, volume);
            this.es5503.setVolume(addr + 1, volume);  // pair
            this.es5503.setPointer(addr, oscAptr);
            this.es5503.setPointer(addr + 1, oscBptr);  // pair
            this.es5503.setSize(addr, oscAsiz);
            this.es5503.setSize(addr + 1, oscBsiz);  // pair
            this.es5503.setControl(addr, oscActl);
            this.es5503.setControl(addr + 1, oscBctl);  // pair
          }
          this.rowOffset++;
        }
      }
      this.curRow++;
      if (this.curRow < 0x40) {
        return;
      }
      // advance pattern
      this.curRow = 0;
      this.curPat++;
      if (this.curPat < this.orders.length) {
        this.notice(this.curPat + 1, this.orders.length);
        this.rowOffset = this.orders[this.curPat];
        return;
      }
      // stopped
      this.notice(0, 0);
      this.stop();
      return;
    } else {  // between notes.  Apply arpeggio
      for (let oscillator: number = 0; oscillator < 14; oscillator++) {
        const a: number = this.arpeggio[oscillator];
        if (a) {
          switch (this.timer % 6) {
            case 1: case 4:
              this.tone[oscillator] += a >> 4;
              break;
            case 2: case 5:
              this.tone[oscillator] += a & 0xf;
              break;
            case 0: case 3:
              this.tone[oscillator] -= a >> 4;
              this.tone[oscillator] -= a & 0xf;
              break;
          }
          const freq: number = this.frequencies[this.tone[oscillator]] >>
              this.compactTable[oscillator];
          const addr: number = oscillator * 2;
          this.es5503.setFrequency(addr, freq);
          this.es5503.setFrequency(addr + 1, freq);  // pair
        }
      }
    }
  }
}
