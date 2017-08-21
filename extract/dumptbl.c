#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

static inline uint16_t r16(uint8_t *p) {
  uint16_t r = *p++;
  r |= *p++ << 8;
  return r;
}

static inline uint32_t r32(uint8_t *p) {
  uint32_t r = *p++;
  r |= *p++ << 8;
  r |= *p++ << 16;
  r |= *p++ << 24;
  return r;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <file> <address>\n", argv[0]);
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
  if (addr > len - 4) {
    fprintf(stderr, "Address is too large\n");
    return -1;
  }

  uint8_t done = 0;
  uint16_t start = r16(data + addr);
  addr += 2;
  do {
    uint32_t to = r32(data + addr); addr += 4;
    uint32_t pages = r32(data + addr); addr += 4;
    if (pages)
      printf("Address: $%02x:%04x Block #%d  blocks: %d\n", to >> 16, to & 0xffff, start, pages / 2);
    start += pages / 2;
    if (pages == 0)
      done = 1;
  } while (!done);
}
