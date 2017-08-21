#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

static inline uint16_t r16(uint8_t *p) {
  uint16_t r = *p++;
  r |= *p++ << 8;
  return r;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <file> <start> <outfile>\n", argv[0]);
    fprintf(stderr, "  start is in hex\n");
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

  uint32_t start = strtol(argv[2], NULL, 16);
  if (start > len - 4) {
    fprintf(stderr, "Start address is too large\n");
    return -1;
  }

  uint32_t blockLen = r16(data + start + 6);
  uint32_t fileLen = 600 + blockLen * 3 + 30;

  f = fopen(argv[3], "wb");
  if (!f) {
    fprintf(stderr, "Couldn't create %s\n", argv[3]);
    return -1;
  }
  fwrite(data + start, 1, fileLen, f);
  fclose(f);
}
