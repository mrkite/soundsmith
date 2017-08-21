var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : new P(function (resolve) { resolve(result.value); }).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = y[op[0] & 2 ? "return" : op[0] ? "throw" : "next"]) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [0, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var _this = this;
var Song = (function () {
    function Song() {
    }
    return Song;
}());
var SoundSmith = (function () {
    function SoundSmith() {
        this.player = null;
    }
    SoundSmith.prototype.getSongList = function (path) {
        return __awaiter(this, void 0, void 0, function () {
            return __generator(this, function (_a) {
                return [2, new Promise(function (resolve) {
                        var req = new XMLHttpRequest();
                        req.open('GET', path, true);
                        req.onload = function () {
                            resolve(JSON.parse(req.responseText));
                        };
                        req.send(null);
                    })];
            });
        });
    };
    SoundSmith.prototype.open = function (name, music, wb) {
        return __awaiter(this, void 0, void 0, function () {
            var _this = this;
            var loaded, info, song, _a, wavebank, _b, controls, stop_1, play;
            return __generator(this, function (_c) {
                switch (_c.label) {
                    case 0:
                        this.name = name;
                        loaded = document.getElementById('loaded');
                        if (loaded) {
                            loaded.textContent = 'loading...';
                        }
                        info = document.getElementById('info');
                        _a = Handle.bind;
                        return [4, this.load(music)];
                    case 1:
                        song = new (_a.apply(Handle, [void 0, _c.sent()]))();
                        _b = Handle.bind;
                        return [4, this.load(wb)];
                    case 2:
                        wavebank = new (_b.apply(Handle, [void 0, _c.sent()]))();
                        if (this.player) {
                            this.player.stop();
                        }
                        this.player = new Player(song, wavebank, function (cur, max) {
                            if (info) {
                                if (max == 0) {
                                    info.textContent = 'none';
                                }
                                else {
                                    info.textContent = cur.toString(10) + ' / ' + max.toString(10);
                                }
                            }
                        });
                        if (loaded) {
                            loaded.textContent = name;
                        }
                        controls = document.getElementById('controls');
                        if (controls) {
                            while (controls.firstChild) {
                                controls.removeChild(controls.firstChild);
                            }
                            stop_1 = document.createElement('button');
                            stop_1.textContent = '\u23f9';
                            stop_1.addEventListener('click', function () {
                                if (_this.player) {
                                    _this.player.stop();
                                }
                            });
                            controls.appendChild(stop_1);
                            play = document.createElement('button');
                            play.textContent = '\u25b6';
                            play.addEventListener('click', function () {
                                if (_this.player) {
                                    _this.player.play();
                                }
                            });
                            controls.appendChild(play);
                        }
                        return [2];
                }
            });
        });
    };
    SoundSmith.prototype.load = function (file) {
        return __awaiter(this, void 0, void 0, function () {
            return __generator(this, function (_a) {
                return [2, new Promise(function (resolve) {
                        var req = new XMLHttpRequest();
                        req.open('GET', file, true);
                        req.responseType = 'arraybuffer';
                        req.onload = function () {
                            if (req.response) {
                                resolve(new Uint8Array(req.response));
                            }
                        };
                        req.send(null);
                    })];
            });
        });
    };
    return SoundSmith;
}());
document.addEventListener('DOMContentLoaded', function () { return __awaiter(_this, void 0, void 0, function () {
    var _this = this;
    var ss, songs, list, _i, songs_1, song, row;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0:
                ss = new SoundSmith();
                return [4, ss.getSongList('songs.json')];
            case 1:
                songs = _a.sent();
                list = document.getElementById('songlist');
                if (!list) {
                    return [2];
                }
                for (_i = 0, songs_1 = songs; _i < songs_1.length; _i++) {
                    song = songs_1[_i];
                    row = document.createElement('div');
                    row.dataset.name = song.name;
                    row.dataset.music = song.music;
                    row.dataset.wb = song.wb;
                    row.appendChild(document.createTextNode(song.name));
                    row.addEventListener('click', function (event) { return __awaiter(_this, void 0, void 0, function () {
                        var target;
                        return __generator(this, function (_a) {
                            switch (_a.label) {
                                case 0:
                                    target = event.target;
                                    return [4, ss.open(target.dataset.name, target.dataset.music, target.dataset.wb)];
                                case 1:
                                    _a.sent();
                                    return [2];
                            }
                        });
                    }); });
                    list.appendChild(row);
                }
                return [2];
        }
    });
}); });
var Player = (function () {
    function Player(music, wavebank, notice) {
        var _this = this;
        this.stereo = true;
        this.timer = 0;
        this.tempo = 0;
        this.curRow = 0;
        this.curPat = 0;
        this.orders = [];
        this.volTable = [];
        this.rowOffset = 0;
        this.numInst = 0;
        this.ticksLeft = 0;
        this.instruments = [];
        this.compactTable = new Uint16Array(16);
        this.stereoTable = new Uint16Array(16);
        this.curInst = new Uint8Array(16);
        this.arpeggio = new Uint8Array(16);
        this.tone = new Uint8Array(16);
        this.frequencies = [
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
            0x2066, 0x2254, 0x245e, 0x2688,
        ];
        this.notice = notice;
        this.es5503 = new ES5503(function (osc) { _this.irq(osc); });
        this.loadWavebank(wavebank);
        music.seek(6);
        var blockLen = music.r16();
        this.tempo = music.r16();
        this.es5503.setFrequency(30, 0xfa);
        this.es5503.setVolume(30, 0);
        this.es5503.setPointer(30, 0);
        this.es5503.setSize(30, 0);
        this.es5503.setEnabled(0x3c);
        this.es5503.setControl(30, 8);
        music.seek(0x2c);
        for (var i = 0; i < 15; i++) {
            this.volTable.push(music.r16());
            music.skip(0x1c);
        }
        music.seek(0x1d6);
        var songLen = music.r16() & 0xff;
        for (var i = 0; i < songLen; i++) {
            this.orders.push(music.r8() * 64 * 14);
        }
        music.seek(0x258);
        this.notes = music.read(blockLen);
        this.effects1 = music.read(blockLen);
        this.effects2 = music.read(blockLen);
        for (var i = 0; i < 16; i++) {
            this.stereoTable[i] = music.r16();
        }
        this.rowOffset = this.orders[this.curPat];
        this.notice(this.curPat + 1, this.orders.length);
    }
    Player.prototype.play = function () {
        var _this = this;
        try {
            this.ctx = new AudioContext();
        }
        catch (e) {
            alert('No audio support');
            return;
        }
        this.audioNode = this.ctx.createScriptProcessor(0, 0, 2);
        this.audioNode.onaudioprocess = function (evt) {
            _this.render(evt);
        };
        this.audioNode.connect(this.ctx.destination);
    };
    Player.prototype.stop = function () {
        if (this.audioNode) {
            this.audioNode.disconnect();
        }
        this.audioNode = undefined;
        if (this.ctx) {
            this.ctx.close();
        }
        this.ctx = undefined;
    };
    Player.prototype.loadWavebank = function (wavebank) {
        wavebank.seek(0);
        if (wavebank.r4() == 'GSWV') {
            var ofs = wavebank.r16();
            this.numInst = wavebank.r8();
            wavebank.skip(this.numInst * 10);
            for (var i = 0; i < this.numInst; i++) {
                var instLen = (wavebank.r8() + wavebank.r8()) * 6;
                this.instruments.push(wavebank.read(instLen));
            }
            wavebank.seek(ofs);
            var tbl = new Uint8Array(0x10000);
            tbl.set(wavebank.read(wavebank.length - ofs));
        }
        else {
            wavebank.seek(0);
            this.numInst = wavebank.r16() & 0xff;
            this.es5503.setRam(wavebank.read(0x10000));
            wavebank.seek(0x10022);
            for (var i = 0; i < this.numInst; i++) {
                this.instruments.push(wavebank.read(12));
                wavebank.skip(0x50);
            }
            wavebank.skip(0x3c);
            for (var i = 0; i < 16; i++) {
                this.compactTable[i] = wavebank.r16();
            }
        }
    };
    Player.prototype.render = function (evt) {
        var sampleRate = evt.outputBuffer.sampleRate;
        var leftBuf = evt.outputBuffer.getChannelData(0);
        var rightBuf = evt.outputBuffer.getChannelData(1);
        for (var i = 0; i < evt.outputBuffer.length; i++) {
            this.ticksLeft -= 26320;
            if (this.ticksLeft <= 0) {
                this.ticksLeft += sampleRate;
                this.es5503.tick();
            }
            var _a = this.es5503.render(), left = _a[0], right = _a[1];
            if (!this.stereo) {
                leftBuf[i] = (left + right) * 0.707;
                rightBuf[i] = leftBuf[i];
            }
            else {
                leftBuf[i] = left;
                rightBuf[i] = right;
            }
        }
    };
    Player.prototype.irq = function (osc) {
        if (osc != 30) {
            this.es5503.go(osc);
            return;
        }
        this.timer++;
        if (this.timer == this.tempo) {
            this.timer = 0;
            for (var oscillator = 0; oscillator < 14; oscillator++) {
                var semitone = this.notes[this.rowOffset];
                if (semitone == 0 || (semitone & 0x80)) {
                    this.rowOffset++;
                    if (semitone == 0x80) {
                        this.es5503.setControl(oscillator * 2, 1);
                        this.es5503.setControl(oscillator * 2 + 1, 1);
                    }
                    else if (semitone == 0x81) {
                        this.curRow = 0x3f;
                    }
                }
                else {
                    var fx = this.effects1[this.rowOffset];
                    if (fx & 0xf0) {
                        this.curInst[oscillator] = (fx >> 4) - 1;
                    }
                    var inst = this.curInst[oscillator];
                    var volume = this.volTable[inst] >> 1;
                    fx &= 0xf;
                    if (fx == 0) {
                        this.arpeggio[oscillator] = this.effects2[this.rowOffset];
                        this.tone[oscillator] = semitone;
                    }
                    else {
                        this.arpeggio[oscillator] = 0;
                        if (fx == 3) {
                            volume = this.effects2[this.rowOffset] >> 1;
                            this.es5503.setVolume(oscillator * 2, volume);
                            this.es5503.setVolume(oscillator * 2 + 1, volume);
                        }
                        else if (fx == 6) {
                            volume -= this.effects2[this.rowOffset] >> 1;
                            volume = Math.max(volume, 0);
                            this.es5503.setVolume(oscillator * 2, volume);
                            this.es5503.setVolume(oscillator * 2 + 1, volume);
                        }
                        else if (fx == 5) {
                            volume += this.effects2[this.rowOffset] >> 1;
                            volume = Math.min(volume, 0x7f);
                            this.es5503.setVolume(oscillator * 2, volume);
                            this.es5503.setVolume(oscillator * 2 + 1, volume);
                        }
                        else if (fx == 0xf) {
                            this.tempo = this.effects2[this.rowOffset];
                        }
                    }
                    var addr = oscillator * 2;
                    this.es5503.stop(addr);
                    this.es5503.stop(addr + 1);
                    if (inst < this.numInst) {
                        var x = 0;
                        while (this.instruments[inst][x] < semitone) {
                            x += 6;
                        }
                        var oscAptr = this.instruments[inst][x + 1];
                        var oscAsiz = this.instruments[inst][x + 2];
                        var oscActl = this.instruments[inst][x + 3] & 0xf;
                        if (this.stereoTable[oscillator]) {
                            oscActl |= 0x10;
                        }
                        while (this.instruments[inst][x] != 0x7f) {
                            x += 6;
                        }
                        x += 6;
                        while (this.instruments[inst][x] < semitone) {
                            x += 6;
                        }
                        var oscBptr = this.instruments[inst][x + 1];
                        var oscBsiz = this.instruments[inst][x + 2];
                        var oscBctl = this.instruments[inst][x + 3] & 0xf;
                        if (this.stereoTable[oscillator]) {
                            oscBctl |= 0x10;
                        }
                        var freq = this.frequencies[semitone] >>
                            this.compactTable[inst];
                        this.es5503.setFrequency(addr, freq);
                        this.es5503.setFrequency(addr + 1, freq);
                        this.es5503.setVolume(addr, volume);
                        this.es5503.setVolume(addr + 1, volume);
                        this.es5503.setPointer(addr, oscAptr);
                        this.es5503.setPointer(addr + 1, oscBptr);
                        this.es5503.setSize(addr, oscAsiz);
                        this.es5503.setSize(addr + 1, oscBsiz);
                        this.es5503.setControl(addr, oscActl);
                        this.es5503.setControl(addr + 1, oscBctl);
                    }
                    this.rowOffset++;
                }
            }
            this.curRow++;
            if (this.curRow < 0x40) {
                return;
            }
            this.curRow = 0;
            this.curPat++;
            if (this.curPat < this.orders.length) {
                this.notice(this.curPat + 1, this.orders.length);
                this.rowOffset = this.orders[this.curPat];
                return;
            }
            this.notice(0, 0);
            this.stop();
            return;
        }
        else {
            for (var oscillator = 0; oscillator < 14; oscillator++) {
                var a = this.arpeggio[oscillator];
                if (a) {
                    switch (this.timer % 6) {
                        case 1:
                        case 4:
                            this.tone[oscillator] += a >> 4;
                            break;
                        case 2:
                        case 5:
                            this.tone[oscillator] += a & 0xf;
                            break;
                        case 0:
                        case 3:
                            this.tone[oscillator] -= a >> 4;
                            this.tone[oscillator] -= a & 0xf;
                            break;
                    }
                    var freq = this.frequencies[this.tone[oscillator]] >>
                        this.compactTable[oscillator];
                    var addr = oscillator * 2;
                    this.es5503.setFrequency(addr, freq);
                    this.es5503.setFrequency(addr + 1, freq);
                }
            }
        }
    };
    return Player;
}());
var Mode;
(function (Mode) {
    Mode[Mode["freeRun"] = 0] = "freeRun";
    Mode[Mode["oneShot"] = 1] = "oneShot";
    Mode[Mode["sync"] = 2] = "sync";
    Mode[Mode["swap"] = 3] = "swap";
})(Mode || (Mode = {}));
var Oscillator = (function () {
    function Oscillator() {
        this.pointer = 0;
        this.frequency = 0;
        this.size = 0;
        this.control = 1;
        this.volume = 0;
        this.data = 0;
        this.resolution = 0;
        this.accumulator = 0;
        this.ptr = 0;
        this.shift = 9;
        this.max = 0xff;
    }
    return Oscillator;
}());
var ES5503 = (function () {
    function ES5503(irq) {
        this.waveTable = new Float32Array(0x10000);
        this.oscillators = [];
        this.enabled = 0;
        this.waveSizes = [
            0x100, 0x200, 0x400, 0x800, 0x1000, 0x2000, 0x4000, 0x8000,
        ];
        this.waveMasks = [
            0x1ff00, 0x1fe00, 0x1fc00, 0x1f800, 0x1f000, 0x1e000, 0x1c000, 0x18000,
        ];
        this.irq = irq;
        for (var i = 0; i < 32; i++) {
            this.oscillators.push(new Oscillator());
        }
    }
    ES5503.prototype.setEnabled = function (enabled) {
        this.enabled = enabled >> 1;
    };
    ES5503.prototype.setRam = function (bank) {
        for (var i = 0; i < bank.length; i++) {
            this.waveTable[i] = (bank[i] - 128) / 128;
        }
    };
    ES5503.prototype.setFrequency = function (osc, freq) {
        this.oscillators[osc].frequency = freq;
    };
    ES5503.prototype.setVolume = function (osc, vol) {
        this.oscillators[osc].volume = vol / 127;
    };
    ES5503.prototype.setPointer = function (osc, ptr) {
        this.oscillators[osc].pointer = ptr << 8;
        this.recalc(osc);
    };
    ES5503.prototype.setSize = function (osc, size) {
        this.oscillators[osc].size = (size >> 3) & 7;
        this.oscillators[osc].resolution = size & 7;
        this.recalc(osc);
    };
    ES5503.prototype.setControl = function (osc, ctl) {
        var prev = this.oscillators[osc].control & 1;
        this.oscillators[osc].control = ctl;
        var mode = (ctl >> 1) & 3;
        if (!(ctl & 1) && prev) {
            if (mode == Mode.sync) {
                this.oscillators[osc ^ 1].control &= ~1;
                this.oscillators[osc ^ 1].accumulator = 0;
            }
            this.oscillators[osc].accumulator = 0;
        }
    };
    ES5503.prototype.stop = function (osc) {
        this.oscillators[osc].control &= 0xf7;
        this.oscillators[osc].control |= 1;
        this.oscillators[osc].accumulator = 0;
    };
    ES5503.prototype.go = function (osc) {
        this.oscillators[osc].control &= ~1;
    };
    ES5503.prototype.tick = function () {
        for (var osc = 0; osc <= this.enabled; osc++) {
            var cur = this.oscillators[osc];
            if (!(cur.control & 1)) {
                var base = cur.accumulator >> cur.shift;
                var ofs = (base & cur.max) + cur.ptr;
                cur.data = this.waveTable[ofs] * cur.volume;
                cur.accumulator += cur.frequency;
                if (this.waveTable[ofs] == -1) {
                    this.halted(osc, true);
                }
                else if (base >= cur.max) {
                    this.halted(osc, false);
                }
            }
        }
    };
    ES5503.prototype.render = function () {
        var left = 0;
        var right = 0;
        for (var osc = 0; osc <= this.enabled; osc++) {
            var cur = this.oscillators[osc];
            if (!(cur.control & 1)) {
                if (cur.control & 0x10) {
                    right += cur.data;
                }
                else {
                    left += cur.data;
                }
            }
        }
        var spread = (this.enabled - 2) / 4;
        return [left / spread, right / spread];
    };
    ES5503.prototype.recalc = function (osc) {
        var cur = this.oscillators[osc];
        cur.shift = (cur.resolution + 9) - cur.size;
        cur.ptr = cur.pointer & this.waveMasks[cur.size];
        cur.max = this.waveSizes[cur.size] - 1;
    };
    ES5503.prototype.halted = function (osc, interrupted) {
        var cur = this.oscillators[osc];
        var mode = (cur.control >> 1) & 3;
        if (interrupted || mode != Mode.freeRun) {
            cur.control |= 1;
        }
        else {
            var base = (cur.accumulator >> cur.shift) - cur.max;
            cur.accumulator = Math.max(base, 0) << cur.shift;
        }
        if (mode == Mode.swap) {
            var swap = this.oscillators[osc ^ 1];
            swap.control &= ~1;
            swap.accumulator = 0;
        }
        if (cur.control & 8) {
            this.irq(osc);
        }
    };
    return ES5503;
}());
var Handle = (function () {
    function Handle(data) {
        this.pos = 0;
        this.data = data;
        this.length = data.length;
    }
    Handle.prototype.eof = function () {
        return this.pos >= this.length;
    };
    Handle.prototype.r8 = function () {
        return this.data[this.pos++];
    };
    Handle.prototype.r16 = function () {
        var v = this.data[this.pos++];
        v |= this.data[this.pos++] << 8;
        return v;
    };
    Handle.prototype.r24 = function () {
        var v = this.data[this.pos++];
        v |= this.data[this.pos++] << 8;
        v |= this.data[this.pos++] << 16;
        return v;
    };
    Handle.prototype.r32 = function () {
        var v = this.data[this.pos++];
        v |= this.data[this.pos++] << 8;
        v |= this.data[this.pos++] << 16;
        v |= this.data[this.pos++] << 24;
        return v >>> 0;
    };
    Handle.prototype.r4 = function () {
        var r = '';
        for (var i = 0; i < 4; i++) {
            r += String.fromCharCode(this.data[this.pos++]);
        }
        return r;
    };
    Handle.prototype.seek = function (pos) {
        this.pos = pos;
    };
    Handle.prototype.skip = function (len) {
        this.pos += len;
    };
    Handle.prototype.tell = function () {
        return this.pos;
    };
    Handle.prototype.read = function (len) {
        var oldpos = this.pos;
        this.pos += len;
        return this.data.subarray(oldpos, this.pos);
    };
    return Handle;
}());
//# sourceMappingURL=smith.js.map