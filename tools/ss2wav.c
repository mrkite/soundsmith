/** Copyright 2017 Sean Kasun
 * A very hacked together Soundsmith 2 wave converter.
 * */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FreeRun 0
#define OneShot 1
#define Sync 2
#define Swap 3

typedef struct {
  uint32_t pointer;
  uint32_t frequency;
  uint8_t size;
  uint8_t control;
  double volume;
  double data;
  uint8_t resolution;
  uint32_t accumulator;
  uint32_t ptr;
  uint8_t shift;
  uint16_t max;
} Oscillator;

static inline uint16_t r16(uint8_t *p) {
  uint16_t r = *p++;
  r |= *p << 8;
  return r;
}

static inline void w32(uint8_t *p, uint32_t v) {
  *p++ = v & 0xff;
  *p++ = (v >> 8) & 0xff;
  *p++ = (v >> 16) & 0xff;
  *p = (v >> 24) & 0xff;
}

static int loadMusic(char *filename);
static int loadWavebank(char *filename);
static void setFrequency(int osc, uint32_t freq);
static void setVolume(int osc, uint8_t vol);
static void setPointer(int osc, uint8_t ptr);
static void setSize(int osc, uint8_t size);
static void setControl(int osc, uint8_t ctl);
static void tick();
static void render(int16_t *left, int16_t *right);

static double *ram;
static uint8_t enabled;
static uint16_t numInst;
static uint8_t *instruments;
static uint16_t compactTable[16];
static uint16_t volTable[15];
static uint16_t timer;
static uint16_t tempo;
static uint16_t songLen;
static int *orders;
static int rowOffset;
static int curPat, curRow, stopped;
static uint8_t *notes, *effects1, *effects2;
static uint16_t stereoTable[16];
static Oscillator oscillators[32];
static uint8_t curInst[16];
static uint8_t arpeggio[16];
static uint8_t tone[16];
static uint16_t waveSizes[] = {
  0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000
};
static uint32_t waveMasks[] = {
  0x1ff00, 0x1fe00, 0x1fc00, 0x1f800, 0x1f000, 0x1e000, 0x1c000, 0x18000
};
static uint16_t frequencies[] = {
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
  0x2066, 0x2254, 0x245e, 0x2688
};
uint8_t wavetpl[] = {
  0x52, 0x49, 0x46, 0x46,  // "RIFF"
  0x00, 0x00, 0x00, 0x00,  // 36 + subchunk2 size
  0x57, 0x41, 0x56, 0x45,  // "WAVE"
  0x66, 0x6d, 0x74, 0x20,  // subchunk1 ID "fmt "
  0x10, 0x00, 0x00, 0x00,  // subchunk1 size
  0x01, 0x00, 0x02, 0x00,  // PCM | numchannels
  0xd0, 0x66, 0x00, 0x00,  // samplerate 26320 Hz
  0x40, 0x9b, 0x01, 0x00,  // samplerate * numchannels * bitspersample / 8
  0x04, 0x00, 0x10, 0x00,  // numchannels * bitspersample / 8 | bitspersample
  0x64, 0x61, 0x74, 0x61,  // subchunk2 ID "data"
  0x00, 0x00, 0x00, 0x00   // subchunk2 size
};

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <songfile> <wavebank> <output.wav>\n", argv[0]);
    return -1;
  }
  if (!loadMusic(argv[1]))
    return -1;

  if (!loadWavebank(argv[2]))
    return -1;

  for (int i = 0; i < 32; i++) {
    oscillators[i].control = 1;  // halt
    oscillators[i].data = 0.0f;  // 0
  }

  setFrequency(30, 0xfa);
  setVolume(30, 0);
  setPointer(30, 0);
  setSize(30, 0);
  enabled = 0x3c >> 1;
  setControl(30, 8);  // freerun + interrupts - halt

  FILE *sndf = tmpfile();

  int soundLen = 0x10000;
  uint8_t *soundData = malloc(0x10000);
  int pos = 0;

  int16_t left, right;
  timer = tempo - 1;

  curPat = curRow = 0;
  rowOffset = orders[curPat];
  stopped = 0;
  while (!stopped) {
    tick();
    render(&left, &right);
    soundData[pos++] = left & 0xff;
    soundData[pos++] = left >> 8;
    soundData[pos++] = right & 0xff;
    soundData[pos++] = right >> 8;
    if (pos >= soundLen) {
      fwrite(soundData, 1, pos, sndf);
      pos = 0;
    }
  }

  // create wav header

  size_t datalen = ftell(sndf);
  uint8_t *header = malloc(44);
  memcpy(header, wavetpl, 44);
  w32(header + 4, datalen + 36);
  w32(header + 40, datalen);
  FILE *f = fopen(argv[3], "wb");
  fwrite(header, 1, 44, f);
  fseek(sndf, 0, SEEK_SET);
  while (datalen > 0) {
    size_t len = datalen > 0x10000 ? 0x10000 : datalen;
    fread(soundData, 1, len, sndf);
    fwrite(soundData, 1, len, f);
    datalen -= len;
  }
  fclose(sndf);
  fclose(f);

  return 0;
}

static int loadMusic(char *filename) {
  FILE *f = fopen(filename, "rb");
  if (!f) {
    fprintf(stderr, "Couldn't open %s\n", filename);
    return 0;
  }
  fseek(f, 0, SEEK_END);
  size_t len = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *data = malloc(len);
  fread(data, 1, len, f);
  fclose(f);

  uint8_t *p = data + 6;
  uint16_t blockLen = r16(p);
  p += 2;
  tempo = r16(p);
  p = data + 0x2c;
  for (int i = 0; i < 15; i++) {
    volTable[i] = r16(p);
    p += 0x1e;
  }
  p = data + 0x1d6;
  songLen = p[0];
  p += 2;
  orders = malloc(songLen * sizeof(int));
  for (int i = 0; i < songLen; i++) {
    orders[i] = *p++ * 64 * 14;
  }

  notes = malloc(blockLen);
  memcpy(notes, data + 0x258, blockLen);
  effects1 = malloc(blockLen);
  memcpy(effects1, data + 0x258 + blockLen, blockLen);
  effects2 = malloc(blockLen);
  memcpy(effects2, data + 0x258 + blockLen * 2, blockLen);
  p = data + 0x258 + blockLen * 3;
  for (int i = 0; i < 16; i++) {
    stereoTable[i] = r16(p);
    p += 2;
  }

  return 1;
}

static int loadWavebank(char *filename) {
  FILE *f = fopen(filename, "rb");
  if (!f) {
    fprintf(stderr, "Couldn't open %s\n", filename);
    return 0;
  }
  fseek(f, 0, SEEK_END);
  size_t len = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *data = malloc(len);
  fread(data, 1, len, f);
  fclose(f);

  numInst = data[0];
  ram = calloc(1, 0x10000 * sizeof(double));
  for (int i = 0; i < 0x10000; i++) {
    ram[i] = (((double)data[2 + i]) - 128.0) / 128.0;
  }

  instruments = malloc(12 * numInst);
  uint8_t *p = data + 0x10022;
  for (int i = 0; i < numInst; i++) {
    memcpy(instruments + i * 12, p, 12);
    p += 0x50 + 12;
  }
  p += 0x3c;
  for (int i = 0; i < 16; i++) {
    compactTable[i] = r16(p);
    p += 2;
  }

  return 1;
}

static void irq(int osc) {
  if (osc != 30) {  // not a timer
    oscillators[osc].control &= ~1;
    return;
  }
  timer++;
  if (timer == tempo) {
    timer = 0;
    for (int ch = 0; ch < 14; ch++) {
      uint8_t semitone = notes[rowOffset];
      if (semitone == 0 || (semitone & 0x80)) {
        rowOffset++;
        if (semitone == 0x80) {
          setControl(ch * 2, 1);  // halt
          setControl(ch * 2 + 1, 1);  // halt pair
        } else if (semitone == 0x81) {
          curRow = 0x3f;
        }
      } else {
        uint8_t fx = effects1[rowOffset];
        if (fx & 0xf0) {  // change instrument
          curInst[ch] = (fx >> 4) - 1;
        }
        uint8_t inst = curInst[ch];
        uint8_t volume = volTable[inst] >> 1;
        fx &= 0xf;
        if (fx == 0) {
          arpeggio[ch] = effects2[rowOffset];
          tone[ch] = semitone;
        } else {
          arpeggio[ch] = 0;
          if (fx == 3) {
            volume = effects2[rowOffset] >> 1;
            setVolume(ch * 2, volume);
            setVolume(ch * 2 + 1, volume);
          } else if (fx == 6) {
            volume -= effects2[rowOffset] >> 1;
            if (volume < 0) volume = 0;
            setVolume(ch * 2, volume);
            setVolume(ch * 2 + 1, volume);
          } else if (fx == 5) {
            volume += effects2[rowOffset] >> 1;
            if (volume > 0x7f) volume = 0x7f;
            setVolume(ch * 2, volume);
            setVolume(ch * 2 + 1, volume);
          } else if (fx == 0xf) {
            tempo = effects2[rowOffset];
          }
        }

        oscillators[ch * 2].control &= 0xf7; // clear interrupt
        oscillators[ch * 2].control |= 1;  // halt
        oscillators[ch * 2].accumulator = 0;
        oscillators[ch * 2 + 1].control &= 0xf7;
        oscillators[ch * 2 + 1].control |= 1;
        oscillators[ch * 2 + 1].accumulator = 0;

        if (inst < numInst) {
          int x = 0;
          while (instruments[inst * 12 + x] < semitone) {
            x += 6;
          }
          uint8_t oscAptr = instruments[inst * 12 + x + 1];
          uint8_t oscAsiz = instruments[inst * 12 + x + 2];
          uint8_t oscActl = instruments[inst * 12 + x + 3] & 0xf;
          if (stereoTable[ch]) {
            oscActl |= 0x10;
          }
          while (instruments[inst * 12 + x] != 0x7f) {
            x += 6;
          }
          x += 6;  // skip last
          while (instruments[inst * 12 + x] < semitone) {
            x += 6;
          }
          uint8_t oscBptr = instruments[inst * 12 + x + 1];
          uint8_t oscBsiz = instruments[inst * 12 + x + 2];
          uint8_t oscBctl = instruments[inst * 12 + x + 3] & 0xf;
          if (stereoTable[ch]) {
            oscBctl |= 0x10;
          }
          uint16_t freq = frequencies[semitone] >> compactTable[inst];
          setFrequency(ch * 2, freq);
          setFrequency(ch * 2 + 1, freq);
          setVolume(ch * 2, volume);
          setVolume(ch * 2 + 1, volume);
          setPointer(ch * 2, oscAptr);
          setPointer(ch * 2 + 1, oscBptr);
          setSize(ch * 2, oscAsiz);
          setSize(ch * 2 + 1, oscBsiz);
          setControl(ch * 2, oscActl);
          setControl(ch * 2 + 1, oscBctl);
        }
        rowOffset++;
      }
    }
    curRow++;
    if (curRow < 0x40) {
      return;
    }
    curRow = 0;
    curPat++;
    if (curPat < songLen) {
      rowOffset = orders[curPat];
      return;
    }
    stopped = 1;
    return;
  } else {  // between notes. Apply arpeggio
    for (int ch = 0; ch < 14; ch++) {
      uint8_t a = arpeggio[ch];
      if (a) {
        switch (timer % 6) {
          case 1: case 4:
            tone[ch] += a >> 4;
            break;
          case 2: case 5:
            tone[ch] += a & 0xf;
            break;
          case 0: case 3:
            tone[ch] -= a >> 4;
            tone[ch] -= a & 0xf;
            break;
        }
        uint16_t freq = frequencies[tone[ch]] >> compactTable[ch];
        setFrequency(ch * 2, freq);
        setFrequency(ch * 2 + 1, freq);
      }
    }
  }
}

static void recalc(int osc) {
  Oscillator *o = &oscillators[osc];
  o->shift = (o->resolution + 9) - o->size;
  o->ptr = o->pointer & waveMasks[o->size];
  o->max = waveSizes[o->size] - 1;
}

static void setFrequency(int osc, uint32_t freq) {
  oscillators[osc].frequency = freq;
}

static void setVolume(int osc, uint8_t vol) {
  oscillators[osc].volume = (double)vol / 127.0;
}

static void setPointer(int osc, uint8_t ptr) {
  oscillators[osc].pointer = ptr << 8;
  recalc(osc);
}

static void setSize(int osc, uint8_t size) {
  oscillators[osc].size = (size >> 3) & 7;
  oscillators[osc].resolution = size & 7;
  recalc(osc);
}

static void setControl(int osc, uint8_t ctl) {
  uint8_t prev = oscillators[osc].control & 1;
  oscillators[osc].control = ctl;
  uint8_t mode = (ctl >> 1) & 3;
  // newly triggered?
  if (!(ctl & 1) && prev) {
    if (mode == Sync) {  // trigger pair?
      oscillators[osc ^ 1].control &= ~1;
      oscillators[osc ^ 1].accumulator = 0;
    }
    oscillators[osc].accumulator = 0;
  }
}

static void halted(int osc, int interrupted) {
  Oscillator *cur = &oscillators[osc];
  int mode = (cur->control >> 1) & 3;
  if (interrupted || mode != FreeRun) {
    cur->control |= 1;  // halt
  } else {
    int32_t base = (cur->accumulator >> cur->shift) - cur->max;
    cur->accumulator = (base < 0 ? 0 : base) << cur->shift;
  }
  if (mode == Swap) {
    oscillators[osc ^ 1].control &= ~1;  // enable
    oscillators[osc ^ 1].accumulator = 0;
  }
  if (cur->control & 8) {
    irq(osc);
  }
}

static void tick() {
  for (int osc = 0; osc <= enabled; osc++) {
    Oscillator *cur = &oscillators[osc];
    if (!(cur->control & 1)) {  // running?
      uint32_t base = cur->accumulator >> cur->shift;
      uint32_t ofs = (base & cur->max) + cur->ptr;
      cur->data = ram[ofs] * cur->volume;
      cur->accumulator += cur->frequency;
      if (ram[ofs] == -1.0) {  // same as 0 in raw data
        halted(osc, 1);
      } else if (base >= cur->max) {
        halted(osc, 0);
      }
    }
  }
}

static void render(int16_t *left, int16_t *right) {
  double l = 0.0, r = 0.0;
  for (int osc = 0; osc <= enabled; osc++) {
    Oscillator *cur = &oscillators[osc];
    if (!(cur->control & 1)) {
      if (cur->control & 0x10) {
        r += cur->data;
      } else {
        l += cur->data;
      }
    }
  }
  double spread = (enabled - 2) / 4.0;
  *left = (l / spread) * 32000.0;
  *right = (r / spread) * 32000.0;
}
