#ifndef __TOOLS_H__
#define __TOOLS_H__

typedef struct {
  uint16_t id;
  const char *name;
} Tool;

static Tool tools[] = {
  {0x0101, "TLBootInit"},
  {0x0102, "MMBootInit"},
  {0x0103, "MTBootInit"},
  {0x0104, "QDBootInit"},
  {0x0105, "DeskBootInit"},
  {0x0106, "EMBootInit"},
  {0x0107, "SchBootInit"},
  {0x0108, "SoundBootInit"},
  {0x0109, "ADBBootInit"},
  {0x010a, "SANEBootInit"},
  {0x010b, "IMBootInit"},
  {0x010c, "TextBootInit"},
  {0x010e, "WindBootInit"},
  {0x010f, "MenuBootInit"},
  {0x0110, "CtlBootInit"},
  {0x0111, "LoaderBootInit"},
  {0x0112, "QDAuxBootInit"},
  {0x0113, "PMBootInit"},
  {0x0114, "LEBootInit"},
  {0x0115, "DialogBootInit"},
  {0x0116, "ScrapBootInit"},
  {0x0117, "SFBootInit"},
  {0x0118, "DUBootInit"},
  {0x0119, "NSBootInit"},
  {0x011a, "SeqBootInit"},
  {0x011b, "FMBootInit"},
  {0x011c, "ListBootInit"},
  {0x011d, "ACEBootInit"},
  {0x011e, "ResourceBootInit"},
  {0x0120, "MIDIBootInit"},
  {0x0121, "VDBootInit"},
  {0x0122, "TEBootInit"},
  {0x0123, "MSBootInit"},
  {0x0125, "AnimBootInit"},
  {0x0201, "TLStartUp"},
  {0x0202, "MMStartUp"},
  {0x0203, "MTStartUp"},
  {0x0204, "QDStartUp"},
  {0x0205, "DeskStartUp"},
  {0x0206, "EMStartUp"},
  {0x0207, "SchStartUp"},
  {0x0208, "SoundStartUp"},
  {0x0209, "ADBStartUp"},
  {0x020a, "SANEStartUp"},
  {0x020b, "IMStartUp"},
  {0x020c, "TextStartUp"},
  {0x020e, "WindStartUp"},
  {0x020f, "MenuStartUp"},
  {0x0210, "CtlStartUp"},
  {0x0211, "LoaderStartUp"},
  {0x0212, "QDAuxStartUp"},
  {0x0213, "PMStartUp"},
  {0x0214, "LEStartUp"},
  {0x0215, "DialogStartUp"},
  {0x0216, "ScrapStartUp"},
  {0x0217, "SFStartUp"},
  {0x0218, "DUStartUp"},
  {0x0219, "NSStartUp"},
  {0x021a, "SeqStartUp"},
  {0x021b, "FMStartUp"},
  {0x021c, "ListStartUp"},
  {0x021d, "ACEStartUp"},
  {0x021e, "ResourceStartUp"},
  {0x0220, "MIDIStartUp"},
  {0x0221, "VDStartUp"},
  {0x0222, "TEStartUp"},
  {0x0223, "MSStartUp"},
  {0x0225, "AnimStartUp"},
  {0x0301, "TLShutDown"},
  {0x0302, "MMShutDown"},
  {0x0303, "MTShutDown"},
  {0x0304, "QDShutDown"},
  {0x0305, "DeskShutDown"},
  {0x0306, "EMShutDown"},
  {0x0307, "SchShutDown"},
  {0x0308, "SoundShutDown"},
  {0x0309, "ADBShutDown"},
  {0x030a, "SANEShutDown"},
  {0x030b, "IMShutDown"},
  {0x030c, "TextShutDown"},
  {0x030e, "WindShutDown"},
  {0x030f, "MenuShutDown"},
  {0x0310, "CtlShutDown"},
  {0x0311, "LoaderShutDown"},
  {0x0312, "QDAuxShutDown"},
  {0x0313, "PMShutDown"},
  {0x0314, "LEShutDown"},
  {0x0315, "DialogShutDown"},
  {0x0316, "ScrapShutDown"},
  {0x0317, "SFShutDown"},
  {0x0318, "DUShutDown"},
  {0x0319, "NSShutDown"},
  {0x031a, "SeqShutDown"},
  {0x031b, "FMShutDown"},
  {0x031c, "ListShutDown"},
  {0x031d, "ACEShutDown"},
  {0x031e, "ResourceShutDown"},
  {0x0320, "MIDIShutDown"},
  {0x0321, "VDShutDown"},
  {0x0322, "TEShutDown"},
  {0x0323, "MSShutDown"},
  {0x0325, "AnimShutDown"},
  {0x0401, "TLVersion"},
  {0x0402, "MMVersion"},
  {0x0403, "MTVersion"},
  {0x0404, "QDVersion"},
  {0x0405, "DeskVersion"},
  {0x0406, "EMVersion"},
  {0x0407, "SchVersion"},
  {0x0408, "SoundVersion"},
  {0x0409, "ADBVersion"},
  {0x040a, "SANEVersion"},
  {0x040b, "IMVersion"},
  {0x040c, "TextVersion"},
  {0x040e, "WindVersion"},
  {0x040f, "MenuVersion"},
  {0x0410, "CtlVersion"},
  {0x0411, "LoaderVersion"},
  {0x0412, "QDAuxVersion"},
  {0x0413, "PMVersion"},
  {0x0414, "LEVersion"},
  {0x0415, "DialogVersion"},
  {0x0416, "ScrapVersion"},
  {0x0417, "SFVersion"},
  {0x0418, "DUVersion"},
  {0x0419, "NSVersion"},
  {0x041a, "SeqVersion"},
  {0x041b, "FMVersion"},
  {0x041c, "ListVersion"},
  {0x041d, "ACEVersion"},
  {0x041e, "ResourceVersion"},
  {0x0420, "MIDIVersion"},
  {0x0421, "VDVersion"},
  {0x0422, "TEVersion"},
  {0x0423, "MSVersion"},
  {0x0425, "AnimVersion"},
  {0x0501, "TLReset"},
  {0x0502, "MMReset"},
  {0x0503, "MTReset"},
  {0x0504, "QDReset"},
  {0x0505, "DeskReset"},
  {0x0506, "EMReset"},
  {0x0507, "SchReset"},
  {0x0508, "SoundReset"},
  {0x0509, "ADBReset"},
  {0x050a, "SANEReset"},
  {0x050b, "IMReset"},
  {0x050c, "TextReset"},
  {0x050e, "WindReset"},
  {0x050f, "MenuReset"},
  {0x0510, "CtlReset"},
  {0x0511, "LoaderReset"},
  {0x0512, "QDAuxReset"},
  {0x0513, "PMReset"},
  {0x0514, "LEReset"},
  {0x0515, "DialogReset"},
  {0x0516, "ScrapReset"},
  {0x0517, "SFReset"},
  {0x0518, "DUReset"},
  {0x0519, "NSReset"},
  {0x051a, "SeqReset"},
  {0x051b, "FMReset"},
  {0x051c, "ListReset"},
  {0x051d, "ACEReset"},
  {0x051e, "ResourceReset"},
  {0x0520, "MIDIReset"},
  {0x0521, "VDReset"},
  {0x0522, "TEReset"},
  {0x0523, "MSReset"},
  {0x0525, "AnimReset"},
  {0x0601, "TLStatus"},
  {0x0602, "MMStatus"},
  {0x0603, "MTStatus"},
  {0x0604, "QDStatus"},
  {0x0605, "DeskStatus"},
  {0x0606, "EMStatus"},
  {0x0607, "SchStatus"},
  {0x0608, "SoundStatus"},
  {0x0609, "ADBStatus"},
  {0x060a, "SANEStatus"},
  {0x060b, "IMStatus"},
  {0x060c, "TextStatus"},
  {0x060e, "WindStatus"},
  {0x060f, "MenuStatus"},
  {0x0610, "CtlStatus"},
  {0x0611, "LoaderStatus"},
  {0x0612, "QDAuxStatus"},
  {0x0613, "PMStatus"},
  {0x0614, "LEStatus"},
  {0x0615, "DialogStatus"},
  {0x0616, "ScrapStatus"},
  {0x0617, "SFStatus"},
  {0x0618, "DUStatus"},
  {0x0619, "NSStatus"},
  {0x061a, "SeqStatus"},
  {0x061b, "FMStatus"},
  {0x061c, "ListStatus"},
  {0x061d, "ACEStatus"},
  {0x061e, "ResourceStatus"},
  {0x0620, "MIDIStatus"},
  {0x0621, "VDStatus"},
  {0x0622, "TEStatus"},
  {0x0623, "MSStatus"},
  {0x0625, "AnimStatus"},
  {0x071d, "ACEInfo"},
  {0x0804, "AddPt"},
  {0x0825, "AnimIdleDebug"},
  {0x0901, "GetTSPtr"},
  {0x0902, "NewHandle"},
  {0x0903, "WriteBRam"},
  {0x0904, "GetAddress"},
  {0x0905, "SaveScrn"},
  {0x0906, "DoWindows"},
  {0x0907, "SchAddTask"},
  {0x0908, "WriteRamBlock"},
  {0x0909, "SendInfo"},
  {0x090a, "SANEFP816"},
  {0x090b, "Multiply"},
  {0x090c, "SetInGlobals"},
  {0x090e, "NewWindow"},
  {0x090f, "MenuKey"},
  {0x0910, "NewControl"},
  {0x0911, "InitialLoad"},
  {0x0912, "CopyPixels"},
  {0x0913, "PrDefault"},
  {0x0914, "LENew"},
  {0x0915, "ErrorSound"},
  {0x0916, "UnloadScrap"},
  {0x0917, "SFGetFile"},
  {0x0919, "AllocGen"},
  {0x091a, "SetIncr"},
  {0x091b, "CountFamilies"},
  {0x091c, "CreateList"},
  {0x091d, "ACECompress"},
  {0x091e, "CreateResourceFile"},
  {0x0920, "MIDIControl"},
  {0x0921, "VDInStatus"},
  {0x0922, "TENew"},
  {0x0923, "SetBasicChan"},
  {0x0925, "StartScene"},
  {0x0a01, "SetTSPtr"},
  {0x0a02, "ReAllocHandle"},
  {0x0a03, "ReadBRam"},
  {0x0a04, "GrafOn"},
  {0x0a05, "RestScrn"},
  {0x0a06, "GetNextEvent"},
  {0x0a07, "SchFlush"},
  {0x0a08, "ReadRamBlock"},
  {0x0a09, "ReadKeyMicroData"},
  {0x0a0a, "SANEDecStr816"},
  {0x0a0b, "SDivide"},
  {0x0a0c, "SetOutGlobals"},
  {0x0a0e, "CheckUpdate"},
  {0x0a0f, "GetMenuBar"},
  {0x0a10, "DisposeControl"},
  {0x0a11, "Restart"},
  {0x0a12, "WaitCursor"},
  {0x0a13, "PrValidate"},
  {0x0a14, "LEDispose"},
  {0x0a15, "NewModalDialog"},
  {0x0a16, "LoadScrap"},
  {0x0a17, "SFPutFile"},
  {0x0a19, "DeAlocGen"},
  {0x0a1a, "ClearIncr"},
  {0x0a1b, "FindFamily"},
  {0x0a1c, "SortList"},
  {0x0a1d, "ACEExpand"},
  {0x0a1e, "OpenResourceFile"},
  {0x0a20, "MIDIDevice"},
  {0x0a21, "VDInSetStd"},
  {0x0a22, "TEKill"},
  {0x0a23, "SetMIDIMode"},
  {0x0a25, "StopScene"},
  {0x0b01, "GetFuncPtr"},
  {0x0b02, "RestoreHandle"},
  {0x0b03, "WriteBParam"},
  {0x0b04, "GrafOff"},
  {0x0b05, "SaveAll"},
  {0x0b06, "EventAvail"},
  {0x0b08, "GetTableAddress"},
  {0x0b09, "ReadKeyMicroMemory"},
  {0x0b0a, "SANEElems816"},
  {0x0b0b, "UDivide"},
  {0x0b0c, "SetErrGlobals"},
  {0x0b0e, "CloseWindow"},
  {0x0b0f, "MenuRefresh"},
  {0x0b10, "KillControls"},
  {0x0b11, "LoadSegNum"},
  {0x0b12, "DrawIcon"},
  {0x0b13, "PrStlDialog"},
  {0x0b14, "LESetText"},
  {0x0b15, "NewModelessDialog"},
  {0x0b16, "ZeroScrap"},
  {0x0b17, "SFPGetFile"},
  {0x0b19, "NoteOn"},
  {0x0b1a, "GetTimer"},
  {0x0b1b, "GetFamInfo"},
  {0x0b1c, "NextMember"},
  {0x0b1d, "ACECompBegin"},
  {0x0b1e, "CloseResourceFile"},
  {0x0b20, "MIDIClock"},
  {0x0b21, "VDInGetStd"},
  {0x0b22, "TESetText"},
  {0x0b23, "PlayNote"},
  {0x0b25, "StartFrameTimer"},
  {0x0c01, "GetWAP"},
  {0x0c02, "AddToOOMQueue"},
  {0x0c03, "ReadBParam"},
  {0x0c04, "GetStandardSCB"},
  {0x0c05, "RestAll"},
  {0x0c06, "GetMouse"},
  {0x0c08, "GetSoundVolume"},
  {0x0c09, "Resync"},
  {0x0c0b, "LongMul"},
  {0x0c0c, "GetInGlobals"},
  {0x0c0e, "Destkop"},
  {0x0c0f, "FlashMenuBar"},
  {0x0c10, "SetCtlTitle"},
  {0x0c11, "UnloadSegNum"},
  {0x0c12, "SpecialRect"},
  {0x0c13, "PrJobDialog"},
  {0x0c14, "LEIdle"},
  {0x0c15, "CloseDialog"},
  {0x0c16, "PutScrap"},
  {0x0c17, "SFPPutFile"},
  {0x0c19, "NoteOff"},
  {0x0c1a, "GetLoc"},
  {0x0c1b, "GetFamNum"},
  {0x0c1c, "DrawMember"},
  {0x0c1d, "ACEExpBegin"},
  {0x0c1e, "AddResource"},
  {0x0c20, "MIDIInfo"},
  {0x0c21, "VDInConvAdj"},
  {0x0c22, "TEGetText"},
  {0x0c23, "StopNote"},
  {0x0c25, "StopFrameTimer"},
  {0x0d01, "SetWAP"},
  {0x0d02, "RemoveFromOOMQueue"},
  {0x0d03, "ReadTimeHex"},
  {0x0d04, "InitColorTable"},
  {0x0d06, "Button"},
  {0x0d08, "SetSoundVolume"},
  {0x0d09, "AsyncADBReceive"},
  {0x0d0b, "LongDivide"},
  {0x0d0c, "GetOutGlobals"},
  {0x0d0e, "SetWTitle"},
  {0x0d0f, "InsertMenu"},
  {0x0d10, "GetCtlTitle"},
  {0x0d11, "LoadSegNum"},
  {0x0d12, "SeedFill"},
  {0x0d13, "PrPixelMap"},
  {0x0d14, "LEClick"},
  {0x0d15, "NewDItem"},
  {0x0d16, "GetScrap"},
  {0x0d17, "SFAllCaps"},
  {0x0d19, "AllNotesOff"},
  {0x0d1a, "SeqAllNotesOff"},
  {0x0d1b, "AddFamily"},
  {0x0d1c, "SelectMember"},
  {0x0d1d, "GetACEExpState"},
  {0x0d1e, "UpdateResourceFile"},
  {0x0d20, "MIDIReadPacket"},
  {0x0d21, "VDKeyControl"},
  {0x0d22, "TEGetTextInfo"},
  {0x0d23, "KillAllNotes"},
  {0x0d25, "SetBackgndPort"},
  {0x0e01, "LoadTools"},
  {0x0e03, "WriteTimeHex"},
  {0x0e04, "SetColorTable"},
  {0x0e05, "InstallNDA"},
  {0x0e06, "StillDown"},
  {0x0e08, "FFStartSound"},
  {0x0e09, "SyncADBReceive"},
  {0x0e0b, "FixRatio"},
  {0x0e0c, "GetErrGlobals"},
  {0x0e0e, "GetWTitle"},
  {0x0e0f, "DeleteMenu"},
  {0x0e10, "HideControl"},
  {0x0e11, "UnloadSeg"},
  {0x0e12, "CalcMask"},
  {0x0e13, "PrOpenDoc"},
  {0x0e14, "LESetSelect"},
  {0x0e15, "RemoveDItem"},
  {0x0e16, "GetScrapHandle"},
  {0x0e17, "SFGetFile2"},
  {0x0e19, "NSSetUpdateRate"},
  {0x0e1a, "SetTrkInfo"},
  {0x0e1b, "InstallFont"},
  {0x0e1c, "GetListDefProc"},
  {0x0e1d, "SetACEExpState"},
  {0x0e1e, "LoadResource"},
  {0x0e20, "MIDIWritePacket"},
  {0x0e21, "VDKeyStatus"},
  {0x0e22, "TEIdle"},
  {0x0e23, "SetRecTrack"},
  {0x0e25, "RefreshBack"},
  {0x0f01, "LoadOneTool"},
  {0x0f03, "ReadAsciiTime"},
  {0x0f04, "GetColorTable"},
  {0x0f05, "InstallCDA"},
  {0x0f06, "WaitMouseUp"},
  {0x0f08, "FFStopSound"},
  {0x0f09, "AbsOn"},
  {0x0f0b, "FixMul"},
  {0x0f0c, "SetInputDevice"},
  {0x0f0e, "SetFrameColor"},
  {0x0f0f, "InsertMItem"},
  {0x0f10, "ShowControl"},
  {0x0f11, "GetLoadSegInfo"},
  {0x0f12, "GetSysIcon"},
  {0x0f13, "PrCloseDoc"},
  {0x0f14, "LEActivate"},
  {0x0f15, "ModalDialog"},
  {0x0f16, "GetScrapSize"},
  {0x0f17, "SFPutFile2"},
  {0x0f19, "NSSetUserUpdateRtn"},
  {0x0f1a, "StartSeq"},
  {0x0f1b, "SetPurgeStart"},
  {0x0f1c, "ResetMember"},
  {0x0f1e, "RemoveResource"},
  {0x0f20, "MIDIRecordSeq"},
  {0x0f21, "VDKeySetKCol"},
  {0x0f22, "TEActivate"},
  {0x0f23, "SetPlayTrack"},
  {0x0f25, "StartChar"},
  {0x1001, "UnloadOneTool"},
  {0x1002, "DisposeHandle"},
  {0x1003, "SetVector"},
  {0x1004, "SetColorEntry"},
  {0x1006, "TickCount"},
  {0x1008, "FFSoundStatus"},
  {0x1009, "AbsOff"},
  {0x100b, "FracMul"},
  {0x100c, "SetOutputDevice"},
  {0x100e, "GetFrameColor"},
  {0x100f, "DeleteMItem"},
  {0x1010, "DrawControls"},
  {0x1011, "GetUserID"},
  {0x1012, "PixelMap2Rgn"},
  {0x1013, "PrOpenPage"},
  {0x1014, "LEDeactivate"},
  {0x1015, "IsDialogEvent"},
  {0x1016, "GetScrapPath"},
  {0x1017, "SFPGetFile2"},
  {0x101a, "StepSeq"},
  {0x101b, "CountFonts"},
  {0x101c, "NewList"},
  {0x101e, "MarkResourceChange"},
  {0x1020, "MIDIStopRecord"},
  {0x1021, "VDKeyGetKRCol"},
  {0x1022, "TEDeactivate"},
  {0x1023, "TrackToChan"},
  {0x1025, "MoveChar"},
  {0x1101, "TLMountVolume"},
  {0x1102, "DisposeAll"},
  {0x1103, "GetVector"},
  {0x1104, "GetColorEntry"},
  {0x1105, "ChooseCDA"},
  {0x1106, "GetDBLTime"},
  {0x1108, "FFGeneratorStatus"},
  {0x1109, "ReadAbs"},
  {0x110b, "FixDiv"},
  {0x110c, "SetErrorDevice"},
  {0x110e, "SelectWindow"},
  {0x110f, "GetSysBar"},
  {0x1110, "HiliteControls"},
  {0x1111, "LGetPathname"},
  {0x1113, "PrClosePage"},
  {0x1114, "LEKey"},
  {0x1115, "DialogSelect"},
  {0x1116, "SetScrapPath"},
  {0x1117, "SFPPutFile2"},
  {0x111a, "StopSeq"},
  {0x111b, "FindFontStats"},
  {0x111c, "DrawMember2"},
  {0x111e, "SetCurResourceFile"},
  {0x1120, "MIDIPlaySeq"},
  {0x1121, "VDKeyGetKGCol"},
  {0x1122, "TEClick"},
  {0x1123, "Locate"},
  {0x1125, "GetCharRecPtr"},
  {0x1201, "TLTextMountVolume"},
  {0x1202, "PurgeHandle"},
  {0x1203, "SetHeartBeat"},
  {0x1204, "SetSCB"},
  {0x1206, "GetCaretTime"},
  {0x1208, "SetSoundMIRQV"},
  {0x1209, "SetAbsScale"},
  {0x120b, "FracDiv"},
  {0x120c, "GetInputDevice"},
  {0x120e, "HideWindow"},
  {0x120f, "SetSysBar"},
  {0x1210, "CtlNewRes"},
  {0x1211, "UserShutdown"},
  {0x1213, "PrPicFile"},
  {0x1214, "LECut"},
  {0x1215, "DlgCut"},
  {0x1216, "GetScrapCount"},
  {0x1217, "SFShowInvisible"},
  {0x121a, "SetInstTable"},
  {0x121b, "LoadFont"},
  {0x121c, "NextMember2"},
  {0x121e, "GetCurResourceFile"},
  {0x1220, "MIDIStopPlay"},
  {0x1221, "VDKeyGetKBCol"},
  {0x1222, "TEUpdate"},
  {0x1223, "SetVelComp"},
  {0x1225, "KillChar"},
  {0x1301, "SaveTextState"},
  {0x1302, "PurgeAll"},
  {0x1303, "DelHeartBeat"},
  {0x1304, "GetSCB"},
  {0x1305, "SetDAStrPtr"},
  {0x1306, "SetSwitch"},
  {0x1308, "SetUserSoundIRQV"},
  {0x1309, "GetAbsScale"},
  {0x130b, "FixRound"},
  {0x130c, "GetOutputDevice"},
  {0x130e, "ShowWindow"},
  {0x130f, "FixMenuBar"},
  {0x1310, "FindControl"},
  {0x1311, "RenamePathname"},
  {0x1312, "IBeamCursor"},
  {0x1313, "PrControl"},
  {0x1314, "LECopy"},
  {0x1315, "DlgCopy"},
  {0x1316, "GetScrapState"},
  {0x1317, "SFReScan"},
  {0x131a, "StartInts"},
  {0x131b, "LoadSysFont"},
  {0x131c, "ResetMember2"},
  {0x131e, "SetCurResourceApp"},
  {0x1320, "MIDIConvert"},
  {0x1321, "VDKeySetKDiss"},
  {0x1322, "TEPaintText"},
  {0x1323, "SetMIDIPort"},
  {0x1325, "LoadActor"},
  {0x1401, "RestoreTextState"},
  {0x1403, "ClrHeartBeat"},
  {0x1404, "SetAllSCBs"},
  {0x1405, "GetDAStrPtr"},
  {0x1406, "PostEvent"},
  {0x1408, "FFSoundDoneStatus"},
  {0x1409, "SRQPoll"},
  {0x140b, "FracSqrt"},
  {0x140c, "GetErrorDevice"},
  {0x140e, "SendBehind"},
  {0x140f, "CountMItems"},
  {0x1410, "TestControl"},
  {0x1412, "WhooshRect"},
  {0x1413, "PrError"},
  {0x1414, "LEPaste"},
  {0x1415, "DlgPaste"},
  {0x1417, "SFMultiGet2"},
  {0x141a, "StopInts"},
  {0x141b, "AddFontVar"},
  {0x141c, "SelectMember2"},
  {0x141e, "GetCurResourceApp"},
  {0x1421, "VDKeyGetKDiss"},
  {0x1422, "TEKey"},
  {0x1423, "SetInstrument"},
  {0x1425, "SetCharScript"},
  {0x1501, "MessageCenter"},
  {0x1503, "SysFailMgr"},
  {0x1504, "ClearScreen"},
  {0x1505, "OpenNDA"},
  {0x1506, "FlushEvents"},
  {0x1508, "FFSetUpSound"},
  {0x1509, "SRQRemove"},
  {0x150b, "FracCos"},
  {0x150c, "InitTextDev"},
  {0x150e, "FrontWindow"},
  {0x150f, "NewMenuBar"},
  {0x1510, "TrackControl"},
  {0x1513, "PrSetError"},
  {0x1514, "LEDelete"},
  {0x1515, "DlgDelete"},
  {0x1517, "SFPMultiGet2"},
  {0x151a, "StartSeqRel"},
  {0x151b, "FixFontMenu"},
  {0x151c, "SortList2"},
  {0x151e, "HomeResourceFile"},
  {0x1521, "VDKeySetNKD"},
  {0x1522, "TEUnsupported"},
  {0x1523, "SeqPlayer"},
  {0x1525, "RunAnimScripts"},
  {0x1601, "SetDefaultTPT"},
  {0x1603, "GetAddr"},
  {0x1604, "SetMasterSCB"},
  {0x1605, "CloseNDA"},
  {0x1606, "GetOSEvent"},
  {0x1608, "FFStartPlaying"},
  {0x1609, "ClearSRQTable"},
  {0x160b, "FracSin"},
  {0x160c, "CtlTextDev"},
  {0x160e, "SetInfoDraw"},
  {0x160f, "GetMHandle"},
  {0x1610, "MoveControl"},
  {0x1613, "PrChoosePrinter"},
  {0x1614, "LEInsert"},
  {0x1615, "DrawDialog"},
  {0x161b, "ChooseFont"},
  {0x161c, "NewList2"},
  {0x161e, "WriteResource"},
  {0x1621, "VDKeyGetNKD"},
  {0x1622, "TECut"},
  {0x1623, "SetTempo"},
  {0x1625, "FillAddrTable"},
  {0x1701, "MessageByName"},
  {0x1703, "ReadMouse"},
  {0x1704, "GetMasterSCB"},
  {0x1705, "SystemClick"},
  {0x1706, "OSEventAvail"},
  {0x1708, "SetDOCReg"},
  {0x170b, "FixATan2"},
  {0x170c, "StatusTextDev"},
  {0x170e, "FindWindow"},
  {0x170f, "SetBarColors"},
  {0x1710, "DragControl"},
  {0x1713, "GetDeviceName"},
  {0x1714, "LEUpdate"},
  {0x1715, "Alert"},
  {0x171b, "ItemID2FamNum"},
  {0x171c, "ListKey"},
  {0x171e, "ReleaseResource"},
  {0x1721, "VDOutSetStd"},
  {0x1722, "TECopy"},
  {0x1723, "SetCallBack"},
  {0x1725, "CompileRect"},
  {0x1801, "StartUpTools"},
  {0x1802, "GetHandleSize"},
  {0x1803, "InitMouse"},
  {0x1804, "OpenPort"},
  {0x1805, "SystemEdit"},
  {0x1806, "SetEventMask"},
  {0x1808, "ReadDOCReg"},
  {0x180b, "HiWord"},
  {0x180c, "WriteChar"},
  {0x180e, "TrackGoAway"},
  {0x180f, "GetBarColors"},
  {0x1810, "SetCtlIcons"},
  {0x1813, "PrGetPrinterSpecs"},
  {0x1814, "LETextBox"},
  {0x1815, "StopAlert"},
  {0x181b, "FMSetSysFont"},
  {0x181c, "CompareStrings"},
  {0x181e, "DetachResource"},
  {0x1821, "VDOutGetStd"},
  {0x1822, "TEPaste"},
  {0x1823, "SysExOut"},
  {0x1825, "StartTockTask"},
  {0x1901, "ShutDownTools"},
  {0x1902, "SetHandleSize"},
  {0x1903, "SetMouse"},
  {0x1904, "InitPort"},
  {0x1905, "SystemTask"},
  {0x1906, "FakeMouse"},
  {0x190b, "LoWord"},
  {0x190c, "ErrWriteChar"},
  {0x190e, "MoveWindow"},
  {0x190f, "SetMTitleStart"},
  {0x1910, "SetCtlValue"},
  {0x1913, "PrDevPrChanged"},
  {0x1914, "LEFromScrap"},
  {0x1915, "NoteAlert"},
  {0x191b, "FMGetSysFID"},
  {0x191e, "UniqueResourceID"},
  {0x1921, "VDOutControl"},
  {0x1922, "TEClear"},
  {0x1923, "SetBeat"},
  {0x1925, "FireTockTask"},
  {0x1a01, "GetMsgHandle"},
  {0x1a02, "FindHandle"},
  {0x1a03, "HomeMouse"},
  {0x1a04, "ClosePort"},
  {0x1a05, "SystemEvent"},
  {0x1a06, "SetAutokeyLimit"},
  {0x1a0b, "Long2Fix"},
  {0x1a0c, "WriteLine"},
  {0x1a0e, "DragWindow"},
  {0x1a0f, "GetMTitleStart"},
  {0x1a10, "GetCtlValue"},
  {0x1a13, "PrDevstartup"},
  {0x1a14, "LEToScrap"},
  {0x1a15, "CautionAlert"},
  {0x1a1b, "FMGetCurFID"},
  {0x1a1e, "SetResourceID"},
  {0x1a21, "VDOutStatus"},
  {0x1a22, "TEInsert"},
  {0x1a23, "MIDIMessage"},
  {0x1a25, "SetForegndPort"},
  {0x1b01, "AcceptRequests"},
  {0x1b02, "FreeMem"},
  {0x1b03, "ClearMouse"},
  {0x1b04, "SetPort"},
  {0x1b05, "GetNumNDAs"},
  {0x1b06, "GetKeyTranslation"},
  {0x1b0b, "Fix2Long"},
  {0x1b0c, "ErrWriteLine"},
  {0x1b0e, "GrowWindow"},
  {0x1b0f, "GetMenuMgrPort"},
  {0x1b10, "SetCtlParams"},
  {0x1b13, "PrDevShutdown"},
  {0x1b14, "LEScrapHandle"},
  {0x1b15, "ParamText"},
  {0x1b1b, "FamNum2ItemID"},
  {0x1b1e, "GetResourceAttr"},
  {0x1b21, "VDGetFeatures"},
  {0x1b22, "TEReplace"},
  {0x1b23, "LocateEnd"},
  {0x1b25, "SetAnimWindow"},
  {0x1c01, "SendRequests"},
  {0x1c02, "MaxBlock"},
  {0x1c03, "ClampMouse"},
  {0x1c04, "GetPort"},
  {0x1c05, "CloseNDAbyWinPtr"},
  {0x1c06, "SetKeyTranslation"},
  {0x1c0b, "Fix2Frac"},
  {0x1c0c, "WriteString"},
  {0x1c0e, "SizeWindow"},
  {0x1c0f, "CalcMenuSize"},
  {0x1c10, "GetCtlParams"},
  {0x1c13, "PrDevOpen"},
  {0x1c14, "LEGetScrapLen"},
  {0x1c15, "SetDAFont"},
  {0x1c1b, "InstallWithStats"},
  {0x1c1e, "SetResourceAttr"},
  {0x1c21, "VDInControl"},
  {0x1c22, "TEGetSelection"},
  {0x1c23, "Merge"},
  {0x1d02, "TotalMem"},
  {0x1d03, "GetMouseClamp"},
  {0x1d04, "SetPortLoc"},
  {0x1d05, "CloseAllNDAs"},
  {0x1d0b, "Frac2Fix"},
  {0x1d0c, "ErrWriteString"},
  {0x1d0e, "TaskMaster"},
  {0x1d0f, "SetMTitleWidth"},
  {0x1d10, "DragRect"},
  {0x1d13, "PrDevRead"},
  {0x1d14, "LESetScrapLen"},
  {0x1d1e, "GetResourceSize"},
  {0x1d21, "VDGGControl"},
  {0x1d22, "TESsetSelection"},
  {0x1d23, "DeleteTrack"},
  {0x1e02, "CheckHandle"},
  {0x1e03, "PosMouse"},
  {0x1e04, "GetPortLoc"},
  {0x1e05, "FixAppleMenu"},
  {0x1e0b, "Fix2X"},
  {0x1e0c, "TextWriteBlock"},
  {0x1e0e, "BeginUpdate"},
  {0x1e0f, "GetMTitleWidth"},
  {0x1e10, "GrowSize"},
  {0x1e13, "PrDevWrite"},
  {0x1e14, "LESetHilite"},
  {0x1e15, "GetControlDItem"},
  {0x1e1e, "MatchResourceHandle"},
  {0x1e21, "VDGGStatus"},
  {0x1e22, "TEGetSelectionStyle"},
  {0x1e23, "SetMetro"},
  {0x1f02, "CompactMem"},
  {0x1f03, "ServeMouse"},
  {0x1f04, "SetPortRect"},
  {0x1f05, "AddToRunQ"},
  {0x1f0b, "Frac2X"},
  {0x1f0c, "ErrWriteBlock"},
  {0x1f0e, "EndUpdate"},
  {0x1f0f, "SetMenuFlag"},
  {0x1f10, "GetCtlDPage"},
  {0x1f13, "PrDevClose"},
  {0x1f14, "LESetCaret"},
  {0x1f15, "GetIText"},
  {0x1f1e, "GetOpenFileRefNum"},
  {0x1f22, "TEStyleChange"},
  {0x1f23, "GetMSData"},
  {0x2002, "HLock"},
  {0x2003, "GetNewID"},
  {0x2004, "GetPortRect"},
  {0x2005, "RemoveFromRunQ"},
  {0x200b, "X2FIx"},
  {0x200c, "WriteCString"},
  {0x200e, "GetWMgrPort"},
  {0x200f, "GetMenuFlag"},
  {0x2010, "SetCtlAction"},
  {0x2011, "InitialLoad2"},
  {0x2013, "PrDevStatus"},
  {0x2014, "LETextBox2"},
  {0x2015, "SetIText"},
  {0x201e, "CountTypes"},
  {0x2022, "TEOffsetToPoint"},
  {0x2023, "ConvertToTime"},
  {0x2102, "HLockAll"},
  {0x2103, "DeleteID"},
  {0x2104, "SetPortSize"},
  {0x2105, "RemoveCDA"},
  {0x210b, "X2Frac"},
  {0x210c, "ErrWriteCString"},
  {0x210e, "PinRect"},
  {0x210f, "SetMenuTitle"},
  {0x2110, "GetCtlAction"},
  {0x2111, "GetUserID2"},
  {0x2113, "PrDevAsyncRead"},
  {0x2114, "LESetJust"},
  {0x2115, "SelectIText"},
  {0x211e, "GetIndType"},
  {0x2122, "TEPointToOffset"},
  {0x2123, "ConvertToMeasure"},
  {0x2202, "HUnlock"},
  {0x2203, "StatusID"},
  {0x2204, "MovePortTo"},
  {0x2205, "RemoveNDA"},
  {0x220b, "Int2Hex"},
  {0x220c, "ReadChar"},
  {0x220e, "HiliteWindow"},
  {0x220f, "GetMenuTitle"},
  {0x2210, "SetCtlRefCon"},
  {0x2211, "LGetPathname2"},
  {0x2213, "PrDevWriteBackground"},
  {0x2214, "LEGetTextHand"},
  {0x2215, "HideDItem"},
  {0x221e, "CountResources"},
  {0x2222, "TEGetDefProc"},
  {0x2223, "MSSuspend"},
  {0x2302, "HUnlockAll"},
  {0x2303, "IntSource"},
  {0x2304, "SetOrigin"},
  {0x2305, "GetIndDAInfo"},
  {0x230b, "Long2Hex"},
  {0x230c, "TextReadBlock"},
  {0x230e, "ShowHide"},
  {0x230f, "MenuGlobal"},
  {0x2310, "GetCtlRefCon"},
  {0x2313, "PrDriverVer"},
  {0x2314, "LEGetTextLen"},
  {0x2315, "ShowDItem"},
  {0x231e, "GetIndResource"},
  {0x2322, "TEGetRuler"},
  {0x2323, "MSResume"},
  {0x2402, "SetPurge"},
  {0x2403, "FWEntry"},
  {0x2404, "SetClip"},
  {0x2405, "CallDeskAcc"},
  {0x240b, "Hex2Int"},
  {0x240c, "ReadLine"},
  {0x240e, "BringToFront"},
  {0x240f, "SetMItem"},
  {0x2410, "EraseControl"},
  {0x2413, "PrPortVer"},
  {0x2414, "GetLEDefProc"},
  {0x2415, "FindDItem"},
  {0x241e, "SetResourceLoad"},
  {0x2422, "TESetRuler"},
  {0x2423, "SetTuningTable"},
  {0x2502, "SetPurgeAll"},
  {0x2503, "GetTick"},
  {0x2504, "GetClip"},
  {0x2505, "GetDeskGlobal"},
  {0x250b, "Hex2Long"},
  {0x250e, "WindNewRes"},
  {0x250f, "GetMItem"},
  {0x2510, "DrawOneCtl"},
  {0x2513, "PrGetZoneName"},
  {0x2515, "UpdateDialog"},
  {0x251e, "SetResourceFileDepth"},
  {0x2522, "TEScroll"},
  {0x2523, "GetTuningTable"},
  {0x2603, "PackBytes"},
  {0x2604, "ClipRect"},
  {0x260b, "Int2Dec"},
  {0x260e, "TrackZoom"},
  {0x260f, "SetMItemFlag"},
  {0x2610, "FindTargetCtl"},
  {0x2615, "GetDItemType"},
  {0x261e, "GetMapHandle"},
  {0x2622, "TEGetInternalProc"},
  {0x2623, "SetTrackOut"},
  {0x2703, "UnPackBytes"},
  {0x2704, "HidePen"},
  {0x270b, "Long2Dec"},
  {0x270e, "ZoomWindow"},
  {0x270f, "GetMItemFlag"},
  {0x2710, "MakeNextCtlTarget"},
  {0x2715, "SetDItemType"},
  {0x271e, "LoadAbsResource"},
  {0x2722, "TEGetLastError"},
  {0x2723, "StartMIDIDriver"},
  {0x2802, "PtrToHand"},
  {0x2803, "Munger"},
  {0x2804, "ShowPen"},
  {0x280b, "Dec2Int"},
  {0x280e, "SetWRefCon"},
  {0x280f, "SetMItemBlink"},
  {0x2810, "MakeThisCtlTarget"},
  {0x2813, "PrGetPrinterDrvName"},
  {0x2815, "GetDItemBox"},
  {0x281e, "ResourceConverter"},
  {0x2822, "TECompactRecord"},
  {0x2823, "StopMIDIDriver"},
  {0x2902, "HandToPtr"},
  {0x2903, "GetIRQEnable"},
  {0x2904, "GetPen"},
  {0x290b, "Dec2Long"},
  {0x290e, "GetWRefCon"},
  {0x290f, "MenuNewRes"},
  {0x2910, "SendEventToCtl"},
  {0x2913, "PrGetPortDvrName"},
  {0x2915, "SetDItemBox"},
  {0x2a02, "HandToHand"},
  {0x2a03, "SetAbsClamp"},
  {0x2a04, "SetPenState"},
  {0x2a0b, "HexIt"},
  {0x2a0e, "GetNextWindow"},
  {0x2a0f, "DrawMenuBar"},
  {0x2a10, "GetCtlID"},
  {0x2a13, "PrGetUserName"},
  {0x2a15, "GetFirstDItem"},
  {0x2a1e, "RMFindNamedResource"},
  {0x2b02, "BlockMove"},
  {0x2b03, "GetAbsClamp"},
  {0x2b04, "GetPenState"},
  {0x2b0e, "GetWKind"},
  {0x2b0f, "MenuSelect"},
  {0x2b10, "SetCtlID"},
  {0x2b13, "PrGetNetworkName"},
  {0x2b15, "GetNextDItem"},
  {0x2b1e, "RMGetResourceName"},
  {0x2c03, "SysBeep"},
  {0x2c04, "SetPenSize"},
  {0x2c0e, "GetWFrame"},
  {0x2c0f, "HiliteMenu"},
  {0x2c10, "CallCtlDefProc"},
  {0x2c15, "ModalDialog2"},
  {0x2c1e, "RMLoadNamedResource"},
  {0x2d04, "GetPenSize"},
  {0x2d0e, "SetWFrame"},
  {0x2d0f, "NewMenu"},
  {0x2d10, "NotifyCtls"},
  {0x2d1e, "RMSetResourceName"},
  {0x2e03, "AddToQueue"},
  {0x2e04, "SetPenMode"},
  {0x2e0e, "GetStructRgn"},
  {0x2e0f, "DisposeMenu"},
  {0x2e10, "GetCtlMoreFlags"},
  {0x2e15, "GetDItemValue"},
  {0x2f02, "RealFreeMem"},
  {0x2f03, "DeleteFromQueue"},
  {0x2f04, "GetPenMode"},
  {0x2f0e, "GetContentRgn"},
  {0x2f0f, "InitPalette"},
  {0x2f10, "SetCtlMoreFlags"},
  {0x2f15, "SetDItemValue"},
  {0x3002, "SetHandleID"},
  {0x3004, "SetPenPat"},
  {0x300e, "GetUpdateRgn"},
  {0x300f, "EnableMItem"},
  {0x3010, "GetCtlHandleFromID"},
  {0x3013, "PrDevIsItSafe"},
  {0x3103, "GetInterruptState"},
  {0x3104, "GetPenPat"},
  {0x310e, "GetDefProc"},
  {0x310f, "DisableMItem"},
  {0x3110, "NewControl2"},
  {0x3113, "GetZoneList"},
  {0x3203, "GetIntStateRecSize"},
  {0x3204, "SetPenMask"},
  {0x320e, "SetDefProc"},
  {0x320f, "CheckMItem"},
  {0x3210, "CMLoadResource"},
  {0x3213, "GetMyZone"},
  {0x3215, "GetNewModalDialog"},
  {0x3303, "ReadMouse2"},
  {0x3304, "GetPenMask"},
  {0x330e, "GetWControls"},
  {0x330f, "SetMItemMark"},
  {0x3310, "CMReleaseResource"},
  {0x3313, "GetPrinterList"},
  {0x3315, "GetNewDItem"},
  {0x3403, "GetCodeResConverter"},
  {0x3404, "SetBackPat"},
  {0x340e, "SetOriginMask"},
  {0x340f, "GetMItemMark"},
  {0x3410, "SetCtlParamPtr"},
  {0x3413, "PMUnloadDriver"},
  {0x3415, "GetAlertStage"},
  {0x3503, "GetROMResource"},
  {0x3504, "GetBackPat"},
  {0x350e, "GetInfoRefCon"},
  {0x350f, "SetMItemStyle"},
  {0x3510, "GetCtlParamPtr"},
  {0x3513, "PMLoadDriver"},
  {0x3515, "ResetAlertStage"},
  {0x3603, "ReleaseROMResource"},
  {0x3604, "PenNormal"},
  {0x360e, "SetInfoRefCon"},
  {0x360f, "GetMItemStyle"},
  {0x3613, "PrGetDocName"},
  {0x3615, "DefaultFilter"},
  {0x3703, "ConvSeconds"},
  {0x3704, "SetSolidPenPat"},
  {0x370e, "GetZoomRect"},
  {0x370f, "SetMenuID"},
  {0x3710, "InvalCtls"},
  {0x3713, "PrSetDocName"},
  {0x3715, "GetDefButton"},
  {0x3803, "SysBeep2"},
  {0x3804, "SetSolidBackPat"},
  {0x380e, "SetZoomRect"},
  {0x380f, "SetMItemID"},
  {0x3810, "CtlReserved"},
  {0x3813, "PrGetPgOrientation"},
  {0x3815, "SetDefButton"},
  {0x3903, "VersionString"},
  {0x3904, "SolidPattern"},
  {0x390e, "RefreshDesktop"},
  {0x390f, "SetMenuBar"},
  {0x3910, "FindRadioButton"},
  {0x3915, "DisableDItem"},
  {0x3a03, "WaitUntil"},
  {0x3a04, "MoveTo"},
  {0x3a0e, "InvalRect"},
  {0x3a0f, "SetMItemName"},
  {0x3a10, "SetLETextByID"},
  {0x3a15, "EnableDItem"},
  {0x3b03, "StringToText"},
  {0x3b04, "Move"},
  {0x3b0e, "InvalRgn"},
  {0x3b0f, "GetPopUpDefProc"},
  {0x3b10, "GetLETextByID"},
  {0x3c03, "ShowBootInfo"},
  {0x3c04, "LineTo"},
  {0x3c0e, "ValidRect"},
  {0x3c0f, "PopUpMenuSelect"},
  {0x3d03, "ScanDevices"},
  {0x3d04, "Line"},
  {0x3d0e, "ValidRgn"},
  {0x3d0f, "DrawPopUp"},
  {0x3e04, "SetPicSave"},
  {0x3e0e, "GetContentOrigin"},
  {0x3e0f, "NewMenu2"},
  {0x3f04, "GetPicSave"},
  {0x3f0e, "SetContentOrigin"},
  {0x3f0f, "InsertMItem2"},
  {0x4004, "SetRgnSave"},
  {0x400e, "GetDataSize"},
  {0x400f, "SetMenuTitle2"},
  {0x4104, "GetRgnSave"},
  {0x410e, "SetDataSize"},
  {0x410f, "SetMItem2"},
  {0x4204, "SetPolySave"},
  {0x420e, "GetMaxGrow"},
  {0x420f, "SetMItemName2"},
  {0x4304, "GetPolySave"},
  {0x430e, "SetMaxGrow"},
  {0x430f, "NewMenuBar2"},
  {0x4404, "SetGrafProcs"},
  {0x440e, "GetScroll"},
  {0x4504, "GetGrafProcs"},
  {0x450e, "SetScroll"},
  {0x450f, "HideMenuBar"},
  {0x4604, "SetUserField"},
  {0x460e, "GetPage"},
  {0x460f, "ShowMenuBar"},
  {0x4704, "GetUserField"},
  {0x470e, "SetPage"},
  {0x470f, "SetMItemIcon"},
  {0x4804, "SetSysField"},
  {0x480e, "GetContentDraw"},
  {0x480f, "GetMItemIcon"},
  {0x4904, "GetSysField"},
  {0x490e, "SetContentDraw"},
  {0x490f, "SetMItemStruct"},
  {0x4a04, "SetRect"},
  {0x4a0e, "GetInfoDraw"},
  {0x4a0f, "GetMItemStruct"},
  {0x4b04, "OffsetRect"},
  {0x4b0e, "SetSysWindow"},
  {0x4b0f, "RemoveMItemStruct"},
  {0x4c04, "InsetRect"},
  {0x4c0e, "GetSysWFlag"},
  {0x4c0f, "GetMItemFlag2"},
  {0x4d04, "SectRect"},
  {0x4d0e, "StartDrawing"},
  {0x4d0f, "SetMItemFlag2"},
  {0x4e04, "UnionRect"},
  {0x4e0e, "SetWindowIcons"},
  {0x4e0f, "GetMItemWidth"},
  {0x4f04, "PtInRect"},
  {0x4f0e, "GetRectInfo"},
  {0x4f0f, "GetMItemBlink"},
  {0x5004, "Pt2Rect"},
  {0x500e, "StartInfoDrawing"},
  {0x500f, "InsertPathMItems"},
  {0x5104, "EqualRect"},
  {0x510e, "EndInfoDrawing"},
  {0x5204, "NotEmptyRect"},
  {0x520e, "GetFirstWindow"},
  {0x5304, "FrameRect"},
  {0x530e, "WindDragRect"},
  {0x5404, "PaintRect"},
  {0x540e, "Private01"},
  {0x5504, "EraseRect"},
  {0x550e, "DrawInfoBar"},
  {0x5604, "InvertRect"},
  {0x560e, "WindowGlobal"},
  {0x5704, "FillRect"},
  {0x570e, "SetContentOrigin2"},
  {0x5804, "FrameOval"},
  {0x580e, "GetWindowMgrGlobals"},
  {0x5904, "PaintOval"},
  {0x590e, "AlertWindow"},
  {0x5a04, "EraseOval"},
  {0x5a0e, "StartFrameDrawing"},
  {0x5b04, "InvertOval"},
  {0x5b0e, "EndFrameDrawing"},
  {0x5c04, "FillOVal"},
  {0x5c0e, "ResizeWindow"},
  {0x5d04, "FrameRRect"},
  {0x5d0e, "TaskMasterContent"},
  {0x5e04, "PaintRRect"},
  {0x5e0e, "TaskMasterKey"},
  {0x5f04, "EraseRRect"},
  {0x5f0e, "TaskMasterDA"},
  {0x6004, "InvertRRect"},
  {0x600e, "CompileText"},
  {0x6104, "FillRRect"},
  {0x610e, "NewWindow2"},
  {0x6204, "FrameArc"},
  {0x620e, "ErrorWindow"},
  {0x6304, "PaintArc"},
  {0x630e, "GetAuxWindInfo"},
  {0x6404, "EraseArc"},
  {0x640e, "DoModalWindow"},
  {0x6504, "InvertArc"},
  {0x650e, "MWGetCtlPart"},
  {0x6604, "FillArc"},
  {0x660e, "MWSetMenuProc"},
  {0x6704, "NewRgn"},
  {0x670e, "MWStdDrawProc"},
  {0x6804, "DisposeRgn"},
  {0x680e, "MWSetUpEditMenu"},
  {0x6904, "CopyRgn"},
  {0x690e, "FindCursorCtl"},
  {0x6a04, "SetEmptyRgn"},
  {0x6a0e, "ResizeInfoBar"},
  {0x6b04, "SetRectRgn"},
  {0x6b0e, "HandleDiskInsert"},
  {0x6c04, "RectRgn"},
  {0x6d04, "OpenRgn"},
  {0x6e04, "CloseRgn"},
  {0x6f04, "OffsetRgn"},
  {0x7004, "InsetRgn"},
  {0x7104, "SectRgn"},
  {0x7204, "UnionRgn"},
  {0x7304, "DiffRgn"},
  {0x7404, "XorRgn"},
  {0x7504, "PtInRgn"},
  {0x7604, "RectInRgn"},
  {0x7704, "EqualRgn"},
  {0x7804, "EmptyRgn"},
  {0x7904, "FrameRgn"},
  {0x7a04, "PaintRgn"},
  {0x7b04, "EraseRgn"},
  {0x7c04, "InvertRgn"},
  {0x7d04, "FillRgn"},
  {0x7e04, "ScrollRect"},
  {0x7f04, "PaintPixels"},
  {0x8004, "AddPt"},
  {0x8104, "SubPt"},
  {0x8204, "SetPt"},
  {0x8304, "EqualPt"},
  {0x8404, "LocalToGlobal"},
  {0x8504, "GlobalToLocal"},
  {0x8604, "Random"},
  {0x8704, "SetRandSeed"},
  {0x8804, "GetPixel"},
  {0x8904, "ScalePt"},
  {0x8a04, "MapPt"},
  {0x8b04, "MapRect"},
  {0x8c04, "MapRgn"},
  {0x8d04, "SetStdProcs"},
  {0x8e04, "SetCursor"},
  {0x8f04, "GetCursorAdr"},
  {0x9004, "HideCursor"},
  {0x9104, "ShowCursor"},
  {0x9204, "ObscureCursor"},
  {0x9304, "SetMouseLoc"},
  {0x9404, "SetFont"},
  {0x9504, "GetFont"},
  {0x9604, "GetFontInfo"},
  {0x9704, "GetFontGlobals"},
  {0x9804, "SetFontFlags"},
  {0x9904, "GetFontFlags"},
  {0x9a04, "SetTextFace"},
  {0x9b04, "GetTextFace"},
  {0x9c04, "SetTextMode"},
  {0x9d04, "GetTextMode"},
  {0x9e04, "SetSpaceExtra"},
  {0x9f04, "GetSpaceExtra"},
  {0xa004, "SetForeColor"},
  {0xa104, "GetForeColor"},
  {0xa204, "SetBackColor"},
  {0xa304, "GetBackColor"},
  {0xa404, "DrawChar"},
  {0xa504, "DrawString"},
  {0xa604, "DrawCString"},
  {0xa704, "DrawText"},
  {0xa804, "CharWidth"},
  {0xa904, "StringWidth"},
  {0xaa04, "CStringWidth"},
  {0xab04, "TextWidth"},
  {0xac04, "CharBounds"},
  {0xad04, "StringBounds"},
  {0xae04, "CStringBounds"},
  {0xaf04, "TextBounds"},
  {0xb004, "SetArcRot"},
  {0xb104, "GetArcRot"},
  {0xb204, "SetSysFont"},
  {0xb304, "GetSysFont"},
  {0xb404, "SetVisRgn"},
  {0xb504, "GetVisRgn"},
  {0xb604, "SetIntUse"},
  {0xb704, "OpenPicture"},
  {0xb712, "OpenPicture"},
  {0xb804, "PicComment"},
  {0xb812, "PicComment"},
  {0xb904, "ClosePicture"},
  {0xba04, "DrawPicture"},
  {0xba12, "DrawPicture"},
  {0xbb04, "KillPicture"},
  {0xbb12, "KillPicture"},
  {0xbc04, "FramePoly"},
  {0xbd04, "PaintPoly"},
  {0xbe04, "ErasePoly"},
  {0xbf04, "InvertPoly"},
  {0xc004, "FillPoly"},
  {0xc104, "OpenPoly"},
  {0xc204, "ClosePoly"},
  {0xc304, "KillPoly"},
  {0xc404, "OffsetPoly"},
  {0xc504, "MapPoly"},
  {0xc604, "SetClipHandle"},
  {0xc704, "GetClipHandle"},
  {0xc804, "SetVisHandle"},
  {0xc904, "GetVisHandle"},
  {0xca04, "InitCursor"},
  {0xcb04, "SetBufDims"},
  {0xcc04, "ForceBufDims"},
  {0xcd04, "SaveBufDims"},
  {0xce04, "RestoreBufDims"},
  {0xcf04, "GetFGSize"},
  {0xd004, "SetFontID"},
  {0xd104, "GetFontID"},
  {0xd204, "SetTextSize"},
  {0xd304, "GetTextSize"},
  {0xd404, "SetCharExtra"},
  {0xd504, "GetCharExtra"},
  {0xd604, "PPToPort"},
  {0xd704, "InflateTextBuffer"},
  {0xd804, "GetRomFont"},
  {0xd904, "GetFontLore"},
  {0xda04, "Get640Color"},
  {0xdb04, "Set640Color"}
};

#define numTools (sizeof(tools) / sizeof(tools[0]))

static const char *toolLookup(uint16_t tool) {
  for (int i = 0; i < numTools; i++) {
    if (tools[i].id >= tool) {
      if (tools[i].id == tool)
        return tools[i].name;
      break;
    }
  }
  return NULL;
}

#endif