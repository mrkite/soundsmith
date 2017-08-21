#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <memory.h>

static inline uint32_t fourcc(const char *p) {
  return (p[0] << 24) | (p[1] << 16) | (p[2] << 8) | p[3];
}

static inline uint16_t r16(uint8_t *p) {
  uint16_t r = *p++;
  r |= *p++ << 8;
  return r;
}

static inline void w16(uint8_t *p, uint16_t v) {
  *p++ = v & 0xff;
  *p++ = (v >> 8) & 0xff;
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

static void copyOps(uint8_t **to, uint8_t **from, uint16_t num) {
  uint8_t *dest = *to - num;
  uint8_t *src = *from - num;
  while (num > 0) {
    num--;
    dest[num] = src[num];
  }
  *to = dest;
  *from = src;
}

static uint8_t adjustPage(uint64_t pos, uint16_t delta, uint8_t page) {
  uint64_t adjusted = (pos - delta) & ~0xff;
  uint64_t orig = pos & ~0xff;
  if (adjusted != orig)
    page += (orig - adjusted) >> 8;
  return page;
}

static uint32_t decrunch(uint8_t **data) {
  uint8_t *ptr = *data;
  uint32_t opsOfs = r24(ptr);
  uint8_t *ops = ptr + opsOfs;

  w16(ptr, r16(ops));   // overwrite offset to opcodes
  w16(ptr + 2, r16(ops + 2));
  uint16_t numCopy = ops[4];
  uint8_t totalPages = ops[5];
  uint32_t outlen = r16(ops + 6) * 256;
  *data = realloc(*data, outlen);
  ptr = *data + outlen;
  ops = *data + opsOfs;
  uint8_t page = 0;
  if (page < totalPages)
    page = adjustPage(ptr - *data, numCopy, page);
  if (page > totalPages)
    page = totalPages;
  copyOps(&ptr, &ops, numCopy);

  do {
    uint8_t op = *--ops;
    if (op == 0) {
      numCopy = 0x100;
    } else {
      uint16_t moveOfs, numMove;
      if (op & 0x80) {
        if (op & 0x40) {
          numMove = op & 0x3f;
          if (numMove < 5) {
            numMove <<= 8;
            numMove |= *--ops;
          }
          numCopy = *--ops;
        } else {
          numMove = 4;
          numCopy = op & 0x3f;
          if (numCopy == 0x3f)
            numCopy = *--ops;
        }
        moveOfs = *--ops;
        if (moveOfs <= page) {
          moveOfs <<= 8;
          moveOfs |= *--ops;
        } else {
          moveOfs -= page;
        }
      } else {
        if (op & 0x40) {
          moveOfs = *--ops;
          numMove = 3;
          numCopy = op & 0x3f;
        } else {
          numCopy = 0;
          numMove = 2;
          moveOfs = op & 0x3f;
        }
      }
      uint8_t *from = ptr + moveOfs;
      if (page < totalPages)
        page = adjustPage(ptr - *data, numMove, page);
      if (page > totalPages)
        page = totalPages;
      copyOps(&ptr, &from, numMove);
    }
    if (numCopy) {
      if (page < totalPages)
        page = adjustPage(ptr - *data, numCopy, page);
      if (page > totalPages)
        page = totalPages;
      copyOps(&ptr, &ops, numCopy);
    }
  } while (ops > *data);

  return outlen;
}


int main(int argc, char **argv) {
  if (argc < 5) {
    fprintf(stderr, "Usage: %s <filename.2mg> block numblocks <outfile.dat> [raw]\n", argv[0]);
    fprintf(stderr,"   raw is optional, and just saves the block without decrunching\n");
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
  uint8_t is2mg = 1;
  if (len < 0x16 || r4(data) != fourcc("2IMG") || r32(data + 0xc) != 1)
    is2mg = 0;

  uint32_t numBlocks = is2mg ? r32(data + 0x14) : len / 512;
  uint32_t diskofs = is2mg ? r32(data + 0x18) : 0;

  int block = atoi(argv[2]);
  if (block >= numBlocks) {
    fprintf(stderr, "Block too large\n");
    return -1;
  }
  int num = atoi(argv[3]);
  if (block + num > numBlocks) {
    fprintf(stderr, "Too many blocks\n");
    return -1;
  }

  uint8_t *raw = data;
  if (is2mg) {
    raw = malloc(num * 512);
    memcpy(raw, data + diskofs + block * 512, num * 512);
    free(data);
  }

  if (argc == 6 && strcmp(argv[5], "raw") == 0) {
    f = fopen(argv[4], "wb");
    fwrite(raw, 512, num, f);
    fclose(f);
    return 0;
  }

  uint32_t outlen = decrunch(&raw);

  f = fopen(argv[4], "wb");
  fwrite(raw, 1, outlen, f);
  fclose(f);
  return 0;
}
