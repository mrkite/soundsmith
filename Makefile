TS = src/es5503.ts src/handle.ts
SSTS = src/smith.ts src/player.ts
FTATS = src/fta.ts src/ftaplayer.ts

.DELETE_ON_ERROR:

all: smith.js fta.js

smith.js: $(TS) $(SSTS)
	tsc

fta.js: $(TS) $(FTATS)
	tsc -p tsconfig_fta.json

check:
	tslint $(TS) $(FTATS) $(SSTS)

clean:
	rm -f smith.js fta.js
