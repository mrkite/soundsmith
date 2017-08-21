This directory contains utiltiies I wrote to extract music from
FTA demos.

Extracting the music is a multistep process, that involves analyzing
boot loaders to determine where on disk the music is stored (since the
FTA demos don't have filesystems).

Compile all the utilities by running `make`.

There are step-by-step tutorials on how to use these tools to extract music from
the various FTA demos inside the docs/ folder.

Most of these tools work on 2mg images, and are controlled at a 512-byte block level.

== disasm

`disasm` is a quick and dirty 65816 disassembler.  You specify the starting
block and the number of blocks to disassemble.  You also specify the starting address (in hex)
for disassembly.
into memory starting at 0x800.  Then redirect the disassembly into a file called boot.s

== decrunch

`decrunch` will extract.  There's a special `raw` keyword that will skip the
decrunching routine, and thus this routine can also be used to extract random blocks
out of a disk image.

== dumptbl

Modulae and the Xmas demo both use a loader that uses tables of blocks and their
destination addresses to load data off of the disk.  This tool will parse and
print out those tables.

== trimmusic and trimwb

Since the music and wavebanks weren't loaded from files, but instead just loaded
as groups of 512-byte blocks from disk.  They should be trimmed to the correct
size afterwards.  These routines will determine the proper length of the files
and trim them.  Since these files don't necessarily start at the beginning of
the block, you can also specify the starting offset of the song or music inside
the block.

== 2mg

This tool is for the disk images that have an actual ProDOS filesystem on them.
Simply pass it a disk image and it will extract the entire disk image, creating
directories as needed.
