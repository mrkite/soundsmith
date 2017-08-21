#ifndef __ADDRESSES_H__
#define __ADDRESSES_H__

typedef struct {
  uint32_t address;
  const char *comment;
} MemAddress;

static MemAddress addresses[] = {
  {0x03d0, "Enter BASIC"},
  {0x03d2, "Reconnect DOS"},
  {0x03d9, "Cow Sound"},
  {0x03ea, "Reconnect IO"},
  {0x03f2, "Control-Reset Vector"},
  {0x03f5, "Ampersand Vector"},
  {0x03f8, "Control-Y Vector"},
  {0x0400, "Text Screen"},
  {0x0800, "Text Screen 2"},
  {0x0803, "Enter assembler"},
  {0x2000, "Hires screen"},
  {0x4000, "Hires screen 2"},
  {0x9dbf, "Reconnect DOS 3.3"},
  {0xa56e, "CATALOG"},
  {0xc000, "KBD / 80STOREOFF"},
  {0xc001, "80STOREON"},
  {0xc002, "RDMAINRAM"},
  {0xc003, "RDCARDRAM"},
  {0xc004, "WRMAINRAM"},
  {0xc005, "WRCARDRAM"},
  {0xc006, "SETSLOTCXROM"},
  {0xc007, "SETINTCXROM"},
  {0xc008, "SETSTDZP"},
  {0xc009, "SETALTZP"},
  {0xc00a, "SETINTC3ROM"},
  {0xc00b, "SETSLOTC3ROM"},
  {0xc00c, "CLR80VID"},
  {0xc00d, "SET80VID"},
  {0xc00e, "CLRALTCHAR"},
  {0xc00f, "SETALTCHAR"},
  {0xc010, "KBDSTRB"},
  {0xc011, "RDLCBNK2"},
  {0xc012, "RDLCRAM"},
  {0xc013, "RDRAMRD"},
  {0xc014, "RDRAMWRT"},
  {0xc015, "RDCXROM"},
  {0xc016, "RDALTZP"},
  {0xc017, "RDC3ROM"},
  {0xc018, "RD80STORE"},
  {0xc019, "RDVBL"},
  {0xc01a, "RDTEXT"},
  {0xc01b, "RDMIXED"},
  {0xc01c, "RDPAGE2"},
  {0xc01d, "RDHIRES"},
  {0xc01e, "RDALTCHAR"},
  {0xc01f, "RD80VID"},
  {0xc020, "TAPEOUT"},
  {0xc021, "MONOCOLOR"},
  {0xc022, "TBCOLOR"},
  {0xc023, "VGCINT"},
  {0xc024, "MOUSEDATA"},
  {0xc025, "KEYMODREG"},
  {0xc026, "DATAREG"},
  {0xc027, "KMSTATUS"},
  {0xc028, "ROMBANK"},
  {0xc029, "NEWVIDEO"},
  {0xc02b, "LANGSEL"},
  {0xc02c, "CHARROM"},
  {0xc02d, "SLTROMSEL"},
  {0xc02e, "VERTCNT"},
  {0xc02f, "HORIZCNT"},
  {0xc030, "SPKR"},
  {0xc031, "DISKREG"},
  {0xc032, "SCANINT"},
  {0xc033, "CLOCKDATA"},
  {0xc034, "CLOCKCTL"},
  {0xc035, "SHADOW"},
  {0xc036, "CYAREG"},
  {0xc037, "DMAREG"},
  {0xc038, "SCCBREG"},
  {0xc039, "SCCAREG"},
  {0xc03a, "SCCBDATA"},
  {0xc03b, "SCCADATA"},
  {0xc03c, "SOUNDCTL"},
  {0xc03d, "SOUNDDATA"},
  {0xc03e, "SOUNDADRL"},
  {0xc03f, "SOUNDADRH"},
  {0xc040, "STROBE"},
  {0xc041, "INTEN"},
  {0xc044, "MMDELTAX"},
  {0xc045, "MMDELTAY"},
  {0xc046, "DIAGTYPE"},
  {0xc047, "CLRVBLINT"},
  {0xc048, "CLRXYINT"},
  {0xc050, "TXTCLR"},
  {0xc051, "TXTSET"},
  {0xc052, "MIXCLR"},
  {0xc053, "MIXSET"},
  {0xc054, "TXTPAGE1"},
  {0xc055, "TXTPAGE2"},
  {0xc056, "LORES"},
  {0xc057, "HIRES"},
  {0xc058, "CLRAN0"},
  {0xc059, "SETAN0"},
  {0xc05a, "CLRAN1"},
  {0xc05b, "SETAN1"},
  {0xc05c, "CLRAN2"},
  {0xc05d, "SETAN2"},
  {0xc05e, "DHIRESON"},
  {0xc05f, "DHIRESOFF"},
  {0xc060, "TAPEIN"},
  {0xc061, "RDBTN0"},
  {0xc062, "RDBTN1"},
  {0xc063, "RDBTN2"},
  {0xc064, "PADDL0"},
  {0xc065, "PADDL1"},
  {0xc066, "PADDL2"},
  {0xc067, "PADDL3"},
  {0xc068, "STATEREG"},
  {0xc06d, "TESTREG"},
  {0xc06e, "CLTRM"},
  {0xc06f, "ENTM"},
  {0xc070, "PTRIG"},
  {0xc073, "BANKSEL"},
  {0xc07e, "IOUDISON"},
  {0xc07f, "IOUDISOFF"},
  {0xc081, "ROMIN"},
  {0xc083, "LCBANK2"},
  {0xc08b, "LCBANK1"},
  {0xc0e0, "PH0 off"},
  {0xc0e1, "PH0 on"},
  {0xc0e2, "PH1 off"},
  {0xc0e3, "PH1 on"},
  {0xc0e4, "PH2 off"},
  {0xc0e5, "PH2 on"},
  {0xc0e6, "PH3 off"},
  {0xc0e7, "PH3 on"},
  {0xc0e8, "motor off"},
  {0xc0e9, "motor on"},
  {0xc0ea, "drive 1"},
  {0xc0eb, "drive 2"},
  {0xc0ec, "q6 off"},
  {0xc0ed, "q6 on"},
  {0xc0ee, "q7 off"},
  {0xc0ef, "q7 on"},
  {0xc311, "AUXMOVE"},
  {0xc314, "XFER"},
  {0xc50d, "Smartport"},
  {0xc70d, "Smartport"},
  {0xcfff," CLRROM"},
  {0xd1fc, "Hires Find"},
  {0xd2c9, "Hires bg"},
  {0xd331, "Hires graphics bg"},
  {0xd33a, "Hires DRAW1"},
  {0xd3b9, "Hires SHLOAD"},
  {0xd683, "Clear FOR"},
  {0xdafb, "Carriage Return"},
  {0xe000, "Reset Int Basic"},
  {0xe04b, "IntBASIC LIST"},
  {0xe5ad, "NEW"},
  {0xe5b7, "PLOT"},
  {0xe836, "IntBASIC CHAIN"},
  {0xefec, "IntBASIC RUN"},
  {0xf07c, "IntBASIC LOAD"},
  {0xf0e0, "Leave monitor"},
  {0xf123, "DRAW shape"},
  {0xf14f, "Plot point"},
  {0xf171, "IntBASIC TRACE ON"},
  {0xf176, "IntBASIC TRACE OFF"},
  {0xf30a, "IntBASIC CON"},
  {0xf317, "RESUME"},
  {0xf328, "Clear error"},
  {0xf3de, "HGR"},
  {0xf3e4, "Show hires"},
  {0xf3f2, "Clear hires"},
  {0xf3f6, "Clear hires color"},
  {0xf666, "Enter assembler"},
  {0xf800, "PLOT"},
  {0xf80e, "PLOT1"},
  {0xf819, "HLINE"},
  {0xf828, "VLINE"},
  {0xf832, "CLRSCR"},
  {0xf836, "CLRTOP"},
  {0xf838, "Clear lores y"},
  {0xf83c, "Clear rect"},
  {0xf847, "GBASCALC"},
  {0xf85e, "Add 3 COLOR"},
  {0xf85f, "NXTCOL"},
  {0xf864, "SETCOL"},
  {0xf871, "SCRN"},
  {0xf88c, "INSDS1.2"},
  {0xf88e, "INSDS2"},
  {0xf890, "GET816LEN"},
  {0xf8d0, "INSTDSP"},
  {0xf940, "PRNTYX"},
  {0xf941, "PRNTAX"},
  {0xf944, "PRNTX"},
  {0xf948, "PRBLNK"},
  {0xf94a, "PRBL2"},
  {0xf94c, "Print X blank"},
  {0xf953, "PCADJ"},
  {0xf962, "TEXT2COPY"},
  {0xfa40, "OLDIRQ"},
  {0xfa4c, "BREAK"},
  {0xfa59, "OLDBRK"},
  {0xfa62, "RESET"},
  {0xfaa6, "PWRUP"},
  {0xfaba, "SLOOP"},
  {0xfad7, "REGDSP"},
  {0xfb19, "RTBL"},
  {0xfb1e, "PREAD"},
  {0xfb21, "PREAD4"},
  {0xfb2f, "INIT"},
  {0xfb39, "SETTXT"},
  {0xfb40, "SETGR"},
  {0xfb4b, "SETWND"},
  {0xfb51, "SETWND2"},
  {0xfb5b, "TABV"},
  {0xfb60, "APPLEII"},
  {0xfb6f, "SETPWRC"},
  {0xfb78, "VIDWAIT"},
  {0xfb88, "KBDWAIT"},
  {0xfbb3, "VERSION"},
  {0xfbbf, "ZIDBYTE2"},
  {0xfbc0, "ZIDBYTE"},
  {0xfbc1, "BASCALC"},
  {0xfbdd, "BELL1"},
  {0xfbe2, "BELL1.2"},
  {0xfbe4, "BELL2"},
  {0xfbf0, "STORADV"},
  {0xfbf4, "ADVANCE"},
  {0xfbfd, "VIDOUT"},
  {0xfc10, "BS"},
  {0xfc1a, "UP"},
  {0xfc22, "VTAB"},
  {0xfc24, "VTABZ"},
  {0xfc2c, "ESC"},
  {0xfc42, "CLREOP"},
  {0xfc58, "HOME"},
  {0xfc62, "CR"},
  {0xfc66, "LF"},
  {0xfc70, "SCROLL"},
  {0xfc9c, "CLREOL"},
  {0xfc9e, "CLREOLZ"},
  {0xfca8, "WAIT"},
  {0xfcb4, "NXTA4"},
  {0xfcba, "NXTA1"},
  {0xfcc9, "HEADR"},
  {0xfd0c, "RDKEY"},
  {0xfd10, "FD10"},
  {0xfd18, "RDKEY1"},
  {0xfd1b, "KEYIN"},
  {0xfd35, "RDCHAR"},
  {0xfd5a, "Wait return"},
  {0xfd5c, "Ring bell wait"},
  {0xfd67, "GETLNZ"},
  {0xfd6a, "GETLN"},
  {0xfd6c, "GETLN0"},
  {0xfd6f, "GETLN1"},
  {0xfd75, "Wait line"},
  {0xfd8b, "CROUT1"},
  {0xfd8e, "CROUT"},
  {0xfd92, "PRA1"},
  {0xfda3, "Print memory"},
  {0xfdda, "PRBYTE"},
  {0xfde3, "PRHEX"},
  {0xfded, "COUT"},
  {0xfdf0, "COUT1"},
  {0xfdf6, "COUTZ"},
  {0xfe1f, "IDROUTINE"},
  {0xfe2c, "MOVE"},
  {0xfe5e, "LIST"},
  {0xfe61, "Disassembler"},
  {0xfe80, "INVERSE"},
  {0xfe84, "NORMAL"},
  {0xfe86, "Set I"},
  {0xfe89, "SETKBD"},
  {0xfe8b, "INPORT"},
  {0xfe93, "SETVID"},
  {0xfe95, "OUTPORT"},
  {0xfeb0, "Jump BASIC"},
  {0xfeb6, "GO"},
  {0xfebf, "Display regs"},
  {0xfec2, "Perform trace"},
  {0xfecd, "WRITE"},
  {0xfefd, "READ"},
  {0xff2d, "PRERR"},
  {0xff3a, "BELL"},
  {0xff3f, "RESTORE"},
  {0xff44, "RSTR1"},
  {0xff4a, "SAVE"},
  {0xff4c, "SAV1"},
  {0xff58, "IORTS"},
  {0xff59, "OLDRST"},
  {0xff65, "MON"},
  {0xff69, "MONZ"},
  {0xff6c, "MONZ2"},
  {0xff70, "MONZ4"},
  {0xff8a, "DIG"},
  {0xffa7, "GETNUM"},
  {0xffad, "NXTCHR"},
  {0xffbe, "TOSUB"},
  {0xffc7, "ZMODE"},
  {0xe01e04, "StdText"},
  {0xe01e08, "StdLine"},
  {0xe01e0c, "StdRect"},
  {0xe01e10, "StdRRect"},
  {0xe01e14, "StdOval"},
  {0xe01e18, "StdArc"},
  {0xe01e1c, "StdPoly"},
  {0xe01e20, "StdRgn"},
  {0xe01e24, "StdPixels"},
  {0xe01e28, "StdComment"},
  {0xe01e2c, "StdTxMeas"},
  {0xe01e30, "StdTxBnds"},
  {0xe01e34, "StdGetPic"},
  {0xe01e38, "StdPutPic"},
  {0xe01e98, "ShieldCursor"},
  {0xe01e9c, "UnshieldCursor"},
  {0xe10000, "System Tool dispatch"},
  {0xe10004, "System Tool dispatch"},
  {0xe10008, "User Tool dispatch"},
  {0xe1000c, "User Tool dispatch"},
  {0xe10010, "Interrupt manager"},
  {0xe10014, "COP manager"},
  {0xe10018, "Abort manager"},
  {0xe1001c, "System death manager"},
  {0xe10020, "AppleTalk interrupt"},
  {0xe10024, "Serial interrupt"},
  {0xe10028, "Scanline interrupt"},
  {0xe1002c, "Sound interrupt"},
  {0xe10030, "VBlank interrupt"},
  {0xe10034, "Mouse interrupt"},
  {0xe10038, "250ms interrupt"},
  {0xe1003c, "Keyboard interrupt"},
  {0xe10040, "ADB Response"},
  {0xe10044, "ADB SRQ"},
  {0xe10048, "DA manager"},
  {0xe1004c, "Flush Buffer"},
  {0xe10050, "KbdMicro interrupt"},
  {0xe10054, "1s interrupt"},
  {0xe10058, "External VGC interrupt"},
  {0xe1005c, "Ohter interrupt"},
  {0xe10060, "Cursor update"},
  {0xe10064, "IncBusy"},
  {0xe10068, "DecBusy"},
  {0xe1006c, "Bell vector"},
  {0xe10070, "Break vector"},
  {0xe10074, "Trace vector"},
  {0xe10078, "Step vector"},
  {0xe1007c, "ROM disk"},
  {0xe10080, "ToWriteBram"},
  {0xe10084, "ToReadBram"},
  {0xe10088, "ToWriteTime"},
  {0xe1008c, "ToReadTime"},
  {0xe10090, "ToCtrlPanel"},
  {0xe10094, "ToBramSetup"},
  {0xe10098, "ToPrintMsg8"},
  {0xe1009c, "ToPrintMsg16"},
  {0xe100a0, "Native Ctl-Y"},
  {0xe100a4, "ToAltDispCDA"},
  {0xe100a8, "Prodos 16"},
  {0xe100ac, "OS vector"},
  {0xe100b0, "GS/OS"},
  {0xe100b4, "P8 Switch"},
  {0xe100b8, "Public Flags"},
  {0xe100bc, "OS Kind"},
  {0xe100bd, "OS Boot"},
  {0xe100be, "OS Busy"},
  {0xe100c0, "MsgPtr"},
  {0xe10180, "ToBusyStrip"},
  {0xe10184, "ToStrip"},
  {0xe101b2, "MidiInputPoll"},
  {0xe10200, "Memory manager"},
  {0xe10204, "Set System Speed"},
  {0xe10208, "Slot Arbiter"},
  {0xe10220, "Hypercard callback"},
  {0xe10224, "WordForRTL"},
  {0xe11004, "ATLK Basic"},
  {0xe11008, "ATLK Pascal"},
  {0xe1100c, "ATLK RamGoComp"},
  {0xe11010, "ATLK SoftReset"},
  {0xe11014, "ATLK RamDispatch"},
  {0xe11018, "ATLK RamForbid"},
  {0xe1101c, "ATLK RamPermit"},
  {0xe11020, "ATLK ProEntry"},
  {0xe11022, "ATLK ProDOS"},
  {0xe11026, "ATLK SerStatus"},
  {0xe1102a, "ATLK SerWrite"},
  {0xe1102e, "ATLK SerRead"},
  {0xe1103e, "ATLK PFI"},
  {0xe1d600, "ATLK CmdTable"},
  {0xe1da00, "ATLK TickCount"}
};

#define numAddresses (sizeof(addresses) / sizeof(addresses[0]))

static const char *addressLookup(uint32_t addr) {
  for (int i = 0; i < numAddresses; i++) {
    if (addresses[i].address >= addr) {
      if (addresses[i].address == addr)
        return addresses[i].comment;
      break;
    }
  }
  if (addr & ~0xffff)
    return addressLookup(addr & 0xffff);  // try pageless
  return NULL;
}

#endif