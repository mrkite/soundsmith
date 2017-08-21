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
var FTA = (function () {
    function FTA() {
        this.player = null;
    }
    FTA.prototype.getSongList = function (path) {
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
    FTA.prototype.open = function (name, music, wb, inst, delta) {
        return __awaiter(this, void 0, void 0, function () {
            var _this = this;
            var loaded, song, _a, wavebank, _b, instdef, _c, controls, stop_1, play;
            return __generator(this, function (_d) {
                switch (_d.label) {
                    case 0:
                        this.name = name;
                        loaded = document.getElementById('loaded');
                        if (loaded) {
                            loaded.textContent = 'loading...';
                        }
                        _a = Handle.bind;
                        return [4, this.load(music)];
                    case 1:
                        song = new (_a.apply(Handle, [void 0, _d.sent()]))();
                        _b = Handle.bind;
                        return [4, this.load(wb)];
                    case 2:
                        wavebank = new (_b.apply(Handle, [void 0, _d.sent()]))();
                        _c = Handle.bind;
                        return [4, this.load(inst)];
                    case 3:
                        instdef = new (_c.apply(Handle, [void 0, _d.sent()]))();
                        if (this.player) {
                            this.player.stop();
                        }
                        this.player = new FTAPlayer(song, wavebank, instdef, delta);
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
    FTA.prototype.load = function (file) {
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
    return FTA;
}());
document.addEventListener('DOMContentLoaded', function () { return __awaiter(_this, void 0, void 0, function () {
    var _this = this;
    var fta, songs, list, _i, songs_1, song, row;
    return __generator(this, function (_a) {
        switch (_a.label) {
            case 0:
                fta = new FTA();
                return [4, fta.getSongList('ftasongs.json')];
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
                    row.dataset.inst = song.inst;
                    row.dataset.delta = song.delta.toString(10);
                    row.appendChild(document.createTextNode(song.name));
                    row.addEventListener('click', function (event) { return __awaiter(_this, void 0, void 0, function () {
                        var target;
                        return __generator(this, function (_a) {
                            switch (_a.label) {
                                case 0:
                                    target = event.target;
                                    return [4, fta.open(target.dataset.name, target.dataset.music, target.dataset.wb, target.dataset.inst, parseInt(target.dataset.delta, 10))];
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
var Channel = (function () {
    function Channel() {
        this.ticks = 1;
        this.offset = 0;
        this.pos = 0;
        this.notes = [];
        this.osc = 0;
        this.pointer = 0;
        this.size = 0;
        this.volume = 0;
        this.panning = 0;
        this.control = 0;
        this.freq = 0;
    }
    return Channel;
}());
var FTAPlayer = (function () {
    function FTAPlayer(music, wavebank, inst, delta) {
        var _this = this;
        this.stereo = true;
        this.ticksLeft = 0;
        this.channels = [];
        this.active = [];
        this.es5503 = new ES5503(function (osc) { _this.irq(osc); });
        wavebank.seek(0);
        this.es5503.setRam(wavebank.read(wavebank.length));
        this.es5503.setEnabled(0x3e);
        for (var i = 0; i < 32; i++) {
            this.channels.push(new Channel());
        }
        inst.seek(0);
        var base = inst.r16();
        while (base != 0xffff) {
            var ch = inst.r8();
            this.active.push(ch);
            this.channels[ch].osc = ch;
            this.channels[ch].pointer = inst.r8();
            this.channels[ch].size = inst.r8();
            this.channels[ch].volume = inst.r8();
            this.channels[ch].panning = inst.r8();
            this.channels[ch].control = inst.r8();
            music.seek(base - delta);
            var channelLen = music.r16();
            for (var i = 0; i < channelLen; i++) {
                var freq = music.r16();
                var time = music.r8();
                this.channels[ch].notes.push({ freq: freq, time: time });
            }
            base = inst.r16();
        }
        inst.seek(0x46);
        this.es5503.setFrequency(31, inst.r16());
        this.es5503.setControl(31, 8);
    }
    FTAPlayer.prototype.play = function () {
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
    FTAPlayer.prototype.stop = function () {
        if (this.audioNode) {
            this.audioNode.disconnect();
        }
        this.audioNode = undefined;
        if (this.ctx) {
            this.ctx.close();
        }
        this.ctx = undefined;
    };
    FTAPlayer.prototype.render = function (evt) {
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
    FTAPlayer.prototype.irq = function (osc) {
        if (osc != 31) {
            var ch = this.channels[osc & 0xfc];
            this.noteOff(ch);
            this.noteOn(ch);
        }
        else {
            for (var _i = 0, _a = this.active; _i < _a.length; _i++) {
                var c = _a[_i];
                var ch = this.channels[c];
                ch.ticks--;
                if (ch.ticks == 0) {
                    this.noteOff(ch);
                    ch.ticks = ch.notes[ch.pos].time;
                    ch.freq = ch.notes[ch.pos].freq;
                    ch.pos++;
                    if (ch.pos >= ch.notes.length) {
                        ch.pos = 0;
                    }
                    this.noteOn(ch);
                    ch.osc ^= 2;
                }
            }
        }
    };
    FTAPlayer.prototype.noteOn = function (ch) {
        this.es5503.setFrequency(ch.osc, ch.freq * 2);
        this.es5503.setFrequency(ch.osc + 1, ch.freq * 2);
        var vol = ch.volume & 0xf;
        this.es5503.setVolume(ch.osc, vol << 3);
        this.es5503.setVolume(ch.osc + 1, vol << 3);
        this.es5503.setVolume(ch.osc ^ 2, vol << 3);
        this.es5503.setVolume((ch.osc ^ 2) + 1, vol << 3);
        this.es5503.setPointer(ch.osc, ch.pointer);
        this.es5503.setPointer(ch.osc + 1, ch.pointer);
        this.es5503.setSize(ch.osc, ch.size);
        this.es5503.setSize(ch.osc + 1, ch.size);
        var a = 2;
        var b = 0x12;
        if (ch.panning == 0) {
            b = 2;
        }
        else if (ch.panning == 1) {
            a = 0x12;
        }
        this.es5503.setControl(ch.osc, a | ch.control);
        this.es5503.setControl(ch.osc + 1, b | ch.control);
    };
    FTAPlayer.prototype.noteOff = function (ch) {
        this.es5503.setControl(ch.osc, 7);
        this.es5503.setControl(ch.osc + 1, 7);
    };
    return FTAPlayer;
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
//# sourceMappingURL=fta.js.map