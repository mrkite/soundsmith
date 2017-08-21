#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>
#include "65816.h"
#include "addresses.h"
#include "tools.h"
#include "prodos8.h"
#include "prodos16.h"
#include "smartport.h"

static inline uint32_t fourcc(const char *p) {
  return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

static inline uint16_t r16(uint8_t *p) {
  uint16_t r = *p++;
  r |= *p++ << 8;
  return r;
}

static inline uint32_t r24(uint8_t *p) {
  uint32_t r = *p++;
  r |= *p++ << 8;
  r |= *p++ << 16;
  return r;
}

static inline uint32_t r32(uint8_t *p) {
  uint32_t r = *p++;
  r |= *p++ << 8;
  r |= *p++ << 16;
  r |= *p++ << 24;
  return r;
}

static inline uint32_t r4(uint8_t *p) {
  uint32_t r = *p++ << 24;
  r |= *p++ << 16;
  r |= *p++ << 8;
  r |= *p++;
  return r;
}

static void disasm(uint8_t *ptr, uint32_t addr, int len) {
  uint8_t *end = ptr + len;

  uint8_t emu = 0;
  uint8_t flags = 0x30;
  uint16_t x = 0;
  uint32_t val;
  int8_t delta;
  int16_t delta16;
  uint32_t d6;
  uint8_t smart = 0, dos8 = 0, dos16 = 0;

  while (ptr < end) {
    printf("%02x/%04x:", addr >> 16, addr & 0xffff);
    uint8_t *start = ptr;
    uint8_t opcode = *ptr++;

    const char *inst = opcodes[opcode].inst;
    Address mode = opcodes[opcode].address;

    if (smart == 1 || dos8 == 1) {
      mode = DB;
      inst = "db";
    }
    if (smart == 2 || dos8 == 2 || dos16 == 1) {
      mode = DW;
      inst = "dw";
      smart = 0;
      dos8 = 0;
    }
    if (smart == 3 || dos16 == 2) {
      mode = DD;
      inst = "dd";
      smart = 0;
      dos16 = 0;
    }


    if (start + addressSizes[mode] > end) {
      inst = "db";
      mode = DB;
    }
    uint16_t width = addressSizes[mode];
    if (mode == IMMM && (emu || (flags & 0x20)))
      width--;
    if (mode == IMMX && (emu || (flags & 0x10)))
      width--;
    addr += width;

    for (int i = 0; i < width; i++) {
      printf(" %02x", start[i]);
    }
    for (int i = 0; i < 4 - width; i++) {
      printf("   ");
    }

    printf(" %s", inst);
    for (int i = strlen(inst); i < 8; i++)
      printf(" ");

    const char *comments = NULL;

    switch (mode) {
      case IMP:
        break;
      case IMM:
        val = *ptr++;
        printf("#$%02x", val);
        if (opcode == 0xe2)
          flags |= val;
        else if (opcode == 0xc2)
          flags &= ~val;
        break;
      case IMMM:
        if ((flags & 0x20) || emu)
          printf("#$%02x", *ptr++);
        else {
          printf("#$%04x", r16(ptr)); ptr += 2;
        }
        break;
      case IMMX:
        if ((flags & 0x10) || emu) {
          x = *ptr++;
          printf("#$%02x", x);
        } else {
          x = r16(ptr); ptr += 2;
          printf("#$%04x", x);
        }
        break;
      case IMMS:
        printf("#$%04x", r16(ptr)); ptr += 2;
        break;
      case ABSO:
        val = r16(ptr); ptr += 2;
        printf("$%04x", val);
        comments = addressLookup(val);
        if (comments)
          printf("   ; %s", comments);
        break;
      case ABL:
        val = r24(ptr); ptr += 3;
        printf("$%02x/%04x", val >> 16, val & 0xffff);
        comments = addressLookup(val);
        if (comments)
          printf("   ; %s", comments);
        break;
      case ABX:
        printf("$%04x, x", r16(ptr)); ptr += 2;
        break;
      case ABY:
        printf("$%04x, y", r16(ptr)); ptr += 2;
        break;
      case ABLX:
        val = r24(ptr); ptr += 3;
        printf("$%02x/%04x, x", val >> 16, val & 0xffff);
        break;
      case AIX:
        printf("($%04x, x)", r16(ptr)); ptr += 2;
        break;
      case ZP:
        printf("$%02x", *ptr++);
        break;
      case ZPX:
        printf("$%02x, x", *ptr++);
        break;
      case ZPY:
        printf("$%02x, y", *ptr++);
        break;
      case ZPS:
        printf("$%02x, s", *ptr++);
        break;
      case IND:
        printf("($%04x)", r16(ptr)); ptr += 2;
        break;
      case INZ:
        printf("($%02x)", *ptr++);
        break;
      case INL:
        printf("[$%02x]", *ptr++);
        break;
      case INX:
        printf("($%02x, x)", *ptr++);
        break;
      case INY:
        printf("($%02x), y", *ptr++);
        break;
      case INLY:
        printf("[$%02x], y", *ptr++);
        break;
      case INS:
        printf("($%02x, s), y", *ptr++);
        break;
      case REL:
        delta = *ptr++;
        d6 = delta + addr;
        printf("$%04x", d6 & 0xffff);
        break;
      case RELL:
        delta16 = r16(ptr); ptr += 2;
        d6 = delta16 + addr;
        printf("$%02x/%04x", d6 >> 16, d6 & 0xffff);
        break;
      case BANK:
        val = *ptr++;
        printf("$%02x, $%02x", *ptr++, val);
        break;
      case DB:
        printf("$%02x", opcode);
        break;
      case DW:
        val = opcode | (*ptr++ << 8);
        printf("$%04x", val);
        break;
      case DD:
        printf("%08x", opcode | r24(ptr) << 8); ptr += 3;
        break;
    }

    if (smart == 1) {
      comments = smartportLookup(opcode);
      if (comments)
        printf("   ; %s", comments);
      if (opcode >= 0x40) {
        smart++;
      }
      smart++;
    }

    if (dos8 == 1) {
      comments = prodos8Lookup(opcode);
      if (comments)
        printf("   ; %s", comments);
      dos8++;
    }

    if (dos16 == 1) {
      comments = prodos16Lookup(val);
      if (comments)
        printf("   ; %s", comments);
      dos16++;
    }

    if (opcode == 0x18 && ptr[0] == 0xfb) { // clc xce
      emu = 0;
      printf("   ; 16bit mode");
    }
    if (opcode == 0x38 && ptr[0] == 0xfb) { // sec xce
      emu = 1;
      printf("   ; 8bit mode");
    }

    if (opcode == 0xa2) {  // ldx
      if (ptr[0] == 0x22) {  // jsl
        if (r24(ptr + 1) == 0xe10000) { // jsl e1:0000
          comments = toolLookup(x);
          if (comments)
            printf("   ; %s", comments);
        }
      }
    }

    if (opcode == 0x20) {  // JSR
      if (val == 0xc50d || val == 0xc70d)
        smart = 1;
      if (val == 0xbf00)
        dos8 = 1;
    }

    if (opcode == 0x22) {  // JSL
      if (val == 0xe100a8)
        dos16 = 1;
    }

    printf("\n");

  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <file> <startaddr> [block] [num]\n", argv[0]);
    fprintf(stderr, "  startaddr should be in hex\n");
    fprintf(stderr, "  block is optional, 0 = default\n");
    fprintf(stderr, "  num is number of blocks, optional\n");
    fprintf(stderr,"   If file isn't a 2mg, block and num are bytes\n");
    return -1;
  }
  FILE *f = fopen(argv[1], "rb");
  if (!f) {
    fprintf(stderr, "Couldn't open %s\n", argv[1]);
    return -1;
  }

  fseek(f, 0, SEEK_END);
  int len = ftell(f);
  fseek(f, 0, SEEK_SET);
  uint8_t *data = malloc(len);
  fread(data, 1, len, f);
  fclose(f);

  uint32_t addr = strtol(argv[2], NULL, 16);

  int block = 0;
  if (argc > 3)
    block = strtol(argv[3], NULL, 10);

  int num = 0;
  if (argc > 4)
    num = strtol(argv[4], NULL, 10);

  // if it's a 2img,  find appropriate block
  if (len > 0x16 && r4(data) == fourcc("2IMG") && r32(data + 0xc) == 1) {
    uint32_t numBlocks = r32(data + 0x14);
    uint32_t diskofs = r32(data + 0x18);
    if (block >= numBlocks) {
      fprintf(stderr, "Block too large\n");
      return -1;
    }
    if (num == 0)
      num = numBlocks - block;
    if (block + num > numBlocks) {
      fprintf(stderr, "Too many blocks\n");
      return -1;
    }
    disasm(data + diskofs + block * 512, addr, num * 512);
  } else {
    // not a 2img, just a raw file..
    if (num == 0)
      num = len - block;
    if (block + num > len) {
      fprintf(stderr, "num is too long\n");
      return -1;
    }
    disasm(data + block, addr, num);
  }
}
