/* HSTMATCH module=hstp_trans_main.prx start=0x002a239c end=0x002a24ac symbol=FUN_002a239c lang=c++ data=0x003a86b4 */
/* Clone of src/eboot/loop_until_error_00290c94.cpp (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x003a86b4-0x003a873c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern bool DAT_003f3b3c;
extern char DAT_003a873c[];
extern "C" void FUN_002a130c(const char *, int);
extern "C" void FUN_002c7750(int);
extern "C" int FUN_002c7818(void);
extern "C" int FUN_002c7c28(void *, int *);
extern "C" int FUN_002c7c48(void *);
extern "C" int FUN_002c7c60(void *);

struct Obj { char pad[0x2c]; int f2c; char pad2[0xe8 - 0x30]; int fe8; };

static inline bool Running() { return !DAT_003f3b3c; }

extern "C" int FUN_002a239c(Obj *self)
{
  int r;
  int buf[3];
  for (;;) {
    if (!Running()) break;
    r = FUN_002c7c60(self);
    if (r < 0) { FUN_002a130c("ERROR: scePsmfPlayerGetCurrentStatus()[2]: 0x%08x\n", r); break; }
    if (r == 2) break;
    buf[0] = 0x200;
    buf[1] = self->f2c;
    buf[2] = 0;
    r = FUN_002c7c48(self);
    if (r != 0) { FUN_002a130c("ERROR: scePsmfPlayerUpdate(): 0x%08x\n", r); break; }
    r = FUN_002c7c28(self, buf);
    if (r != (int)0x8061600c && r < 0) { FUN_002a130c("ERROR: scePsmfPlayerGetVideoData(): 0x%08x\n", r); break; }
    self->fe8 = buf[2];
    r = FUN_002c7818();
    if (r < 0) { FUN_002a130c(DAT_003a873c, r); break; }
  }
  FUN_002c7750(0);
  return 0;
}
