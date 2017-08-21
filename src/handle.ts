/** Copyright 2017 Sean Kasun */

class Handle {
  public length: number;
  private data: Uint8Array;
  private pos: number = 0;

  constructor(data: Uint8Array) {
    this.data = data;
    this.length = data.length;
  }
  public eof(): boolean {
    return this.pos >= this.length;
  }
  public r8(): number {
    return this.data[this.pos++];
  }
  public r16(): number {
    let v: number = this.data[this.pos++];
    v |= this.data[this.pos++] << 8;
    return v;
  }
  public r24(): number {
    let v: number = this.data[this.pos++];
    v |= this.data[this.pos++] << 8;
    v |= this.data[this.pos++] << 16;
    return v;
  }
  public r32(): number {
    let v: number = this.data[this.pos++];
    v |= this.data[this.pos++] << 8;
    v |= this.data[this.pos++] << 16;
    v |= this.data[this.pos++] << 24;
    return v >>> 0;  // force 32-bit unsigned
  }
  public r4(): string {
    let r: string = '';
    for (let i: number = 0; i < 4; i++) {
      r += String.fromCharCode(this.data[this.pos++]);
    }
    return r;
  }
  public seek(pos: number): void {
    this.pos = pos;
  }
  public skip(len: number): void {
    this.pos += len;
  }
  public tell(): number {
    return this.pos;
  }
  public read(len: number): Uint8Array {
    const oldpos: number = this.pos;
    this.pos += len;
    return this.data.subarray(oldpos, this.pos);
  }
}
