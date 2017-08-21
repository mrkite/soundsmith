#ifndef __65816_H__
#define __65816_H__

typedef enum {
  IMP = 0,
  IMM,
  IMMM,
  IMMX,
  IMMS,
  ABSO,
  ABL,
  ABX,
  ABY,
  ABLX,
  AIX,
  ZP,
  ZPX,
  ZPY,
  ZPS,
  IND,
  INZ,
  INL,
  INX,
  INY,
  INLY,
  INS,
  REL,
  RELL,
  BANK,
  DB,
  DW,
  DD
} Address;

typedef struct {
  const char *inst;
  Address address;
} Opcode;

static Opcode opcodes[] = {
  {"brk", IMP},  // 00
  {"ora", INX},  // 01
  {"cop", IMP},  // 02
  {"ora", ZPS},  // 03
  {"tsb", ZP},  // 04
  {"ora", ZP},  // 05
  {"asl", ZP},  // 06
  {"ora", INL},  // 07
  {"php", IMP},  // 08
  {"ora", IMMM},  // 09
  {"asl", IMP},  // 0a
  {"phd", IMP},  // 0b
  {"tsb", ABSO},  // 0c
  {"ora", ABSO},  // 0d
  {"asl", ABSO},  // 0e
  {"ora", ABL},  // 0f
  {"bpl", REL},  // 10
  {"ora", INY},  // 11
  {"ora", INZ},  // 12
  {"ora", INS},  // 13
  {"trb", ZP},  // 14
  {"ora", ZPX},  // 15
  {"asl", ZPX},  // 16
  {"ora", INLY},  // 17
  {"clc", IMP},  // 18
  {"ora", ABY},  // 19
  {"inc", IMP},  // 1a
  {"tcs", IMP},  // 1b
  {"trb", ABSO},  // 1c
  {"ora", ABX},  // 1d
  {"asl", ABX},  // 1e
  {"ora", ABLX},  // 1f
  {"jsr", ABSO},  // 20
  {"and", INX},  // 21
  {"jsl", ABL},  // 22
  {"and", ZPS},  // 23
  {"bit", ZP},  // 24
  {"and", ZP},  // 25
  {"rol", ZP},  // 26
  {"and", INL},  // 27
  {"plp", IMP},  // 28
  {"and", IMMM},  // 29
  {"rol", IMP},  // 2a
  {"pld", IMP},  // 2b
  {"bit", ABSO},  // 2c
  {"and", ABSO},  // 2d
  {"rol", ABSO},  // 2e
  {"and", ABL},  // 2f
  {"bmi", REL},  // 30
  {"and", INY},  // 31
  {"and", INZ},  // 32
  {"and", INS},  // 33
  {"bit", ZPX},  // 34
  {"and", ZPX},  // 35
  {"rol", ZPX},  // 36
  {"and", INLY},  // 37
  {"sec", IMP},  // 38
  {"and", ABY},  // 39
  {"dec", IMP},  // 3a
  {"tsc", IMP},  // 3b
  {"bit", ABX},  // 3c
  {"and", ABX},  // 3d
  {"rol", ABX},  // 3e
  {"and", ABLX},  // 3f
  {"rti", IMP},  // 40
  {"eor", INX},  // 41
  {"db", DB},  // 42
  {"eor", ZPS},  // 43
  {"mvp", BANK},  // 44
  {"eor", ZP},  // 45
  {"lsr", ZP},  // 46
  {"eor", INL},  // 47
  {"pha", IMP},  // 48
  {"eor", IMMM},  // 49
  {"lsr", IMP},  // 4a
  {"phk", IMP},  // 4b
  {"jmp", ABSO},  // 4c
  {"eor", ABSO},  // 4d
  {"lsr", ABSO},  // 4e
  {"eor", ABL},  // 4f
  {"bvc", REL},  // 50
  {"eor", INY},  // 51
  {"eor", INZ},  // 52
  {"eor", INS},  // 53
  {"mvn", BANK},  // 54
  {"eor", ZPX},  // 55
  {"lsr", ZPX},  // 56
  {"eor", INLY},  // 57
  {"cli", IMP},  // 58
  {"eor", ABY},  // 59
  {"phy", IMP},  // 5a
  {"tcd", IMP},  // 5b
  {"jmp", ABL},  // 5c
  {"eor", ABX},  // 5d
  {"lsr", ABX},  // 5e
  {"eor", ABLX},  // 5f
  {"rts", IMP},  // 60
  {"adc", INX},  // 61
  {"per", IMP},  // 62
  {"adc", ZPS},  // 63
  {"stz", ZP},  // 64
  {"adc", ZP},  // 65
  {"ror", ZP},  // 66
  {"adc", INL},  // 67
  {"pla", IMP},  // 68
  {"adc", IMMM},  // 69
  {"ror", IMP},  // 6a
  {"rtl", IMP},  // 6b
  {"jmp", IND},  // 6c
  {"adc", ABSO},  // 6d
  {"ror", ABSO},  // 6e
  {"adc", ABL},  // 6f
  {"bvs", REL},  // 70
  {"adc", INY},  // 71
  {"adc", INZ},  // 72
  {"adc", INS},  // 73
  {"stz", ZPX},  // 74
  {"adc", ZPX},  // 75
  {"ror", ZPX},  // 76
  {"adc", INLY},  // 77
  {"sei", IMP},  // 78
  {"adc", ABY},  // 79
  {"ply", IMP},  // 7a
  {"tdc", IMP},  // 7b
  {"jmp", AIX},  // 7c
  {"adc", ABX},  // 7d
  {"ror", ABX},  // 7e
  {"adc", ABLX},  // 7f
  {"bra", REL},  // 80
  {"sta", INX},  // 81
  {"brl", RELL},  // 82
  {"sta", ZPS},  // 83
  {"sty", ZP},  // 84
  {"sta", ZP},  // 85
  {"stx", ZP},  // 86
  {"sta", INL},  // 87
  {"dey", IMP},  // 88
  {"bit", IMMM},  // 89
  {"txa", IMP},  // 8a
  {"phb", IMP},  // 8b
  {"sty", ABSO},  // 8c
  {"sta", ABSO},  // 8d
  {"stx", ABSO},  // 8e
  {"sta", ABL},  // 8f
  {"bcc", REL},  // 90
  {"sta", INY},  // 91
  {"sta", INZ},  // 92
  {"sta", INS},  // 93
  {"sty", ZPX},  // 94
  {"sta", ZPX},  // 95
  {"stx", ZPY},  // 96
  {"sta", INLY},  // 97
  {"tya", IMP},  // 98
  {"sta", ABY},  // 99
  {"txs", IMP},  // 9a
  {"txy", IMP},  // 9b
  {"stz", ABSO},  // 9c
  {"sta", ABX},  // 9d
  {"stz", ABX},  // 9e
  {"sta", ABLX},  // 9f
  {"ldy", IMMX},  // a0
  {"lda", INX},  // a1
  {"ldx", IMMX},  // a2
  {"lda", ZPS},  // a3
  {"ldy", ZP},  // a4
  {"lda", ZP},  // a5
  {"ldx", ZP},  // a6
  {"lda", INL},  // a7
  {"tay", IMP},  // a8
  {"lda", IMMM},  // a9
  {"tax", IMP},  // aa
  {"plb", IMP},  // ab
  {"ldy", ABSO},  // ac
  {"lda", ABSO},  // ad
  {"ldx", ABSO},  // ae
  {"lda", ABL},  // af
  {"bcs", REL},  // b0
  {"lda", INY},  // b1
  {"lda", INZ},  // b2
  {"lda", INS},  // b3
  {"ldy", ZPX},  // b4
  {"lda", ZPX},  // b5
  {"ldx", ZPY},  // b6
  {"lda", INLY},  // b7
  {"clv", IMP},  // b8
  {"lda", ABY},  // b9
  {"tsx", IMP},  // ba
  {"tyx", IMP},  // bb
  {"ldy", ABX},  // bc
  {"lda", ABX},  // bd
  {"ldx", ABY},  // be
  {"lda", ABLX},  // bf
  {"cpy", IMMX},  // c0
  {"cmp", INX},  // c1
  {"rep", IMM},  // c2
  {"cmp", ZPS},  // c3
  {"cpy", ZP},  // c4
  {"cmp", ZP},  // c5
  {"dec", ZP},  // c6
  {"cmp", INL},  // c7
  {"iny", IMP},  // c8
  {"cmp", IMMM},  // c9
  {"dex", IMP},  // ca
  {"wai", IMP},  // cb
  {"cpy", ABSO},  // cc
  {"cmp", ABSO},  // cd
  {"dec", ABSO},  // ce
  {"cmp", ABL},  // cf
  {"bne", REL},  // d0
  {"cmp", INY},  // d1
  {"cmp", INZ},  // d2
  {"cmp", INS},  // d3
  {"pei", IMP},  // d4
  {"cmp", ZPX},  // d5
  {"dec", ZPX},  // d6
  {"cmp", INLY},  // d7
  {"cld", IMP},  // d8
  {"cmp", ABY},  // d9
  {"phx", IMP},  // da
  {"stp", IMP},  // db
  {"jmp", IND},  // dc
  {"cmp", ABX},  // dd
  {"dec", ABX},  // de
  {"cmp", ABLX},  // df
  {"cpx", IMMX},  // e0
  {"sbc", INX},  // e1
  {"sep", IMM},  // e2
  {"sbc", ZPS},  // e3
  {"cpx", ZP},  // e4
  {"sbc", ZP},  // e5
  {"inc", ZP},  // e6
  {"sbc", INL},  // e7
  {"inx", IMP},  // e8
  {"sbc", IMMM},  // e9
  {"nop", IMP},  // ea
  {"xba", IMP},  // eb
  {"cpx", ABSO},  // ec
  {"sbc", ABSO},  // ed
  {"inc", ABSO},  // ee
  {"sbc", ABL},  // ef
  {"beq", REL},  // f0
  {"sbc", INY},  // f1
  {"sbc", INZ},  // f2
  {"sbc", INS},  // f3
  {"pea", IMMS},  // f4
  {"sbc", ZPX},  // f5
  {"inc", ZPX},  // f6
  {"sbc", INLY},  // f7
  {"sed", IMP},  // f8
  {"sbc", ABY},  // f9
  {"plx", IMP},  // fa
  {"xce", IMP},  // fb
  {"jsr", AIX},  // fc
  {"sbc", ABX},  // fd
  {"inc", ABX},  // fe
  {"sbc", ABLX}  // ff
};


uint8_t addressSizes[] = {
  1,  // IMP
  2,  // IMM
  3,  // IMMM
  3,  // IMMX
  3,  // IMMS
  3,  // ABSO
  4,  // ABL
  3,  // ABX
  3,  // ABY
  4,  // ABLX
  3,  // AIX
  2,  // ZP
  2,  // ZPX
  2,  // ZPY
  2,  // ZPS
  3,  // IND
  2,  // INZ
  2,  // INL
  2,  // INX
  2,  // INY
  2,  // INLY
  2,  // INS
  2,  // REL
  3,  // RELL
  3,  // BANK
  1,  // DB
  2,  // DW
  4  // DD
};

#endif
