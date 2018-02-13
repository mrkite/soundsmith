/** Copyright 2017 Sean Kasun */

interface Note {
  freq: number;
  time: number;
}

class Channel {
  public ticks: number = 1;
  public offset: number = 0;
  public pos: number = 0;
  public notes: Note[] = [];
  public osc: number = 0;
  // instrument
  public pointer: number = 0;
  public size: number = 0;
  public volume: number = 0;
  public panning: number = 0;
  public control: number = 0;
  public freq: number = 0;
}

class FTAPlayer {
  private stereo: boolean = true;
  private es5503: ES5503;
  private ctx?: AudioContext;
  private audioNode?: ScriptProcessorNode;
  private ticksLeft: number = 0;
  private channels: Channel[] = [];
  private active: number[] = [];

  constructor(music: Handle, wavebank: Handle, inst: Handle, delta: number) {
    this.es5503 = new ES5503((osc: number): void => { this.irq(osc); });

    wavebank.seek(0);
    this.es5503.setRam(wavebank.read(wavebank.length));
    this.es5503.setEnabled(0x3e);

    for (let i: number = 0; i < 32; i++) {
      this.channels.push(new Channel());
    }

    inst.seek(0);
    let base: number = inst.r16();
    while (base != 0xffff) {
      const ch: number = inst.r8();
      this.active.push(ch);
      this.channels[ch].osc = ch;
      this.channels[ch].pointer = inst.r8();
      this.channels[ch].size = inst.r8();
      this.channels[ch].volume = inst.r8();
      this.channels[ch].panning = inst.r8();
      this.channels[ch].control = inst.r8();
      music.seek(base - delta);
      const channelLen: number = music.r16();
      for (let i: number = 0; i < channelLen; i++) {
        const freq: number = music.r16();
        const time: number = music.r8();
        this.channels[ch].notes.push({freq, time});
      }
      base = inst.r16();
    }

    inst.seek(0x46);
    this.es5503.setFrequency(31, inst.r16());
    this.es5503.setControl(31, 8);  // freerun + interrupt - halt
  }

  public play(): void {
    try {
      this.ctx = new ((<any>window).AudioContext || (<any>window).webkitAudioContext)();
      if (this.ctx == undefined) {
        throw new Error("No audio support!");
      }
    } catch (e) {
      alert(e.message);
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
    if (osc != 31) {  // not a timer
      const ch: Channel = this.channels[osc & 0xfc];
      this.noteOff(ch);
      this.noteOn(ch);
    } else {
      for (const c of this.active) {
        const ch: Channel = this.channels[c];
        ch.ticks--;
        if (ch.ticks == 0) {
          this.noteOff(ch);
          ch.ticks = ch.notes[ch.pos].time;
          ch.freq = ch.notes[ch.pos].freq;
          ch.pos++;
          if (ch.pos >= ch.notes.length) {
            ch.pos = 0;
          }
          this.noteOn(ch);
          ch.osc ^= 2;  // swap oscillator pairs
        }
      }
    }
  }

  private noteOn(ch: Channel): void {
    this.es5503.setFrequency(ch.osc, ch.freq * 2);
    this.es5503.setFrequency(ch.osc + 1, ch.freq * 2);  // pair
    const vol: number = ch.volume & 0xf;
    this.es5503.setVolume(ch.osc, vol << 3);  // scale to ch.master
    this.es5503.setVolume(ch.osc + 1, vol << 3);  // scale to ch.master
    this.es5503.setVolume(ch.osc ^ 2, vol << 3);
    this.es5503.setVolume((ch.osc ^ 2) + 1, vol << 3);
    this.es5503.setPointer(ch.osc, ch.pointer);
    this.es5503.setPointer(ch.osc + 1, ch.pointer);
    this.es5503.setSize(ch.osc, ch.size);
    this.es5503.setSize(ch.osc + 1, ch.size);
    let a: number = 2;  // one shot left
    let b: number = 0x12;  // one shot right
    if (ch.panning == 0) {  // pan left
      b = 2;
    } else if (ch.panning == 1) {  // pan right
      a = 0x12;
    }
    this.es5503.setControl(ch.osc, a | ch.control);
    this.es5503.setControl(ch.osc + 1, b | ch.control);
  }

  private noteOff(ch: Channel): void {
    this.es5503.setControl(ch.osc, 7);  // halt + swap - interrupt
    this.es5503.setControl(ch.osc + 1, 7);  // pair
  }
}
