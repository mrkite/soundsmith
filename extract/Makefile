CC=clang
CFLAGS=-Wall

all: decrunch disasm dumptbl trimmusic trimwb 2mg

decrunch: decrunch.o
	$(CC) $(CFLAGS) -o $@ $<

disasm: disasm.o
	$(CC) $(CFLAGS) -o $@ $<

dumptbl: dumptbl.o
	$(CC) $(CFLAGS) -o $@ $<

trimmusic: trimmusic.o
	$(CC) $(CFLAGS) -o $@ $<

trimwb: trimwb.o
	$(CC) $(CFLAGS) -o $@ $<

2mg: 2mg.o
	$(CC) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f *.o decrunch disasm dumptbl trimmusic trimwb 2mg
