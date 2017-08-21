#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>

#define fourcc(x) (x[0] | (x[1] << 8) | (x[2] << 16) | (x[3] << 24))

static void handleDirectory(uint16_t key, uint8_t *disk, uint32_t diskLen);
static void handleEntry(uint8_t *entry, uint8_t *disk, uint32_t diskLen);
static void handleFile(uint16_t key, uint32_t len, char *name, uint8_t *disk,
    uint32_t diskLen, int type);

static inline uint32_t r32(uint8_t *data) {
  uint32_t r = *data++;
  r |= *data++ << 8;
  r |= *data++ << 16;
  r |= *data << 24;
  return r;
}

static inline uint16_t r16(uint8_t *data) {
  uint16_t r = *data++;
  r |= *data << 8;
  return r;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename.2mg>\n", argv[0]);
    fprintf(stderr, "This will extract all files in the 2mg into the current folder.\n");
    fprintf(stderr, "It will create directories as needed.\n");
    return -1;
  }
  FILE *f = fopen(argv[1], "rb");
  if (!f) {
    fprintf(stderr, "Couldn't open '%s'\n", argv[1]);
    return -1;
  }

  fseek(f, 0, SEEK_END);
  size_t len = ftell(f);
  fseek(f, 0, SEEK_SET);
  if (len < 64) {
    fprintf(stderr, "%s is not a valid 2mg file\n", argv[1]);
    fclose(f);
    return -1;
  }

  uint8_t *header = malloc(64);
  fread(header, 64, 1, f);

  if (r32(header) != fourcc("2IMG")) {
    fprintf(stderr, "%s is not a valid 2mg file\n", argv[1]);
    fclose(f);
    return -1;
  }

  if (r32(header + 0xc) != 1) {
    fprintf(stderr, "Not in ProDOS format\n");
    fclose(f);
    return -1;
  }

  uint32_t diskLen = r32(header + 0x14) * 512;
  uint32_t diskOfs = r32(header + 0x18);
  free(header);

  fseek(f, diskOfs, SEEK_SET);
  uint8_t *disk = malloc(diskLen);
  fread(disk, diskLen, 1, f);
  fclose(f);

  handleDirectory(2, disk, diskLen);
  free(disk);
  return 0;
}

static void readFilename(uint8_t *filename, uint8_t length, char *outname) {
  for (int i = 0; i < length; i++) {
    char ch = filename[i];
    if (isalnum(ch) || ch == '_' || ch == '.' || ch ==' ') {
      *outname++ = ch;
    } else {
      *outname++ = 'x';
      char hi = ch >> 4;
      char lo = ch & 0xf;
      if (hi > 9)
        *outname++ = 'a' + (hi - 10);
      else
        *outname++ = '0' + hi;
      if (lo > 9)
        *outname++ = 'a' + (lo - 10);
      else
        *outname++ = '0' + lo;
    }
  }
  *outname = 0;
}

static void handleDirectory(uint16_t key, uint8_t *disk, uint32_t diskLen) {
  uint8_t *block = disk + key * 512;

  if ((block[4] & 0xf0) != 0xf0 && (block[4] & 0xf0) != 0xe0) {
    fprintf(stderr, "Corrupted directory header\n");
    return;
  }

  char dirname[50];
  readFilename(block + 5, block[4] & 0xf, dirname);

  mkdir(dirname, 0777);
  chdir(dirname);

  uint8_t entryLength = block[0x23];
  uint8_t entriesPerBlock= block[0x24];
  uint16_t fileCount = r16(block + 0x25);
  uint8_t *entry = block + entryLength + 4;
  uint8_t curEntry = 1;
  uint16_t curFile = 0;

  while (curFile < fileCount) {
    if (entry[0] != 0) {
      handleEntry(entry, disk, diskLen);
      curFile++;
    }
    curEntry++;
    entry += entryLength;
    if (curEntry == entriesPerBlock) {
      curEntry = 0;
      block = disk + r16(block + 2) * 512;
      entry = block + 4;
    }
  }

  chdir("..");
}

static void handleEntry(uint8_t *entry, uint8_t *disk, uint32_t diskLen) {
  uint16_t key = r16(entry + 0x11);
  uint32_t eof = r32(entry + 0x15) & 0xffffff;

  char filename[50];
  readFilename(entry + 1, entry[0] & 0xf, filename);

  switch (entry[0] & 0xf0) {
    case 0x10:
      handleFile(key, eof, filename, disk, diskLen, 1);  // seedling
      break;
    case 0x20:
      handleFile(key, eof, filename, disk, diskLen, 2);  // sapling
      break;
    case 0x30:
      handleFile(key, eof, filename, disk, diskLen, 3);  // tree
      break;
    case 0xd0:
      handleDirectory(key, disk, diskLen);
      break;
    default:
      fprintf(stderr, "Unknown file type: %x\n", entry[0] >> 4);
      return;
  }
}

static void dumpSeedling(uint8_t *block, uint32_t len, FILE *f) {
  if (block == NULL)
    fseek(f, len, SEEK_CUR);
  else
    fwrite(block, len, 1, f);
}

static void dumpSapling(uint8_t *index, uint32_t len, FILE *f, uint8_t *disk,
    uint32_t diskLen) {
  if (index == NULL) {
    fseek(f, len, SEEK_CUR);
    return;
  }
  while (len > 0) {
    uint16_t blockid = index[0] | (index[256] << 8);
    uint8_t *block = NULL;
    if (blockid && (blockid + 1) * 512 <= diskLen)
      block = disk + blockid * 512;
    uint32_t blen = len > 512 ? 512 : len;
    dumpSeedling(block, blen, f);
    len -= blen;
    index++;
  }
}

static void dumpTree(uint8_t *index, uint32_t len, FILE *f, uint8_t *disk,
    uint32_t diskLen) {
  if (index == NULL) {
    fseek(f, len, SEEK_CUR);
    return;
  }
  while (len > 0) {
    uint16_t blockid = index[0] | (index[256] << 8);
    uint8_t *block = NULL;
    if (blockid && (blockid + 1) * 512 <= diskLen)
      block = disk + blockid * 512;
    uint32_t blen = len > 256 * 512 ? 256 * 512 : len;
    dumpSapling(block, blen, f, disk, diskLen);
    len -= blen;
    index++;
  }
}

static void handleFile(uint16_t key, uint32_t len, char *name, uint8_t *disk,
    uint32_t diskLen, int type) {
  uint8_t *block = disk + key * 512;
  FILE *f = fopen(name, "wb");
  if (!f) {
    fprintf(stderr, "Failed to create '%s'\n", name);
    return;
  }

  switch (type) {
    case 1:
      dumpSeedling(block, len, f);
      break;
    case 2:
      dumpSapling(block, len, f, disk, diskLen);
      break;
    case 3:
      dumpTree(block, len, f, disk, diskLen);
      break;
  }
  fclose(f);
}
