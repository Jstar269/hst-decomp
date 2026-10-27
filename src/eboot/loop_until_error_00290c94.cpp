/* HSTMATCH module=EBOOT.BIN start=0x00290c94 end=0x00290da4 symbol=FUN_00290c94 lang=c++ data=0x002ff7a8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002ff7a8-0x002ff830) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern bool DAT_0034a80c;
extern char DAT_002ff830[];
extern "C" void FUN_0028fb44(const char *, int);
extern "C" void FUN_002b79b0(int);
extern "C" int FUN_002b7a78(void);
extern "C" int FUN_002b7ea8(void *, int *);
extern "C" int FUN_002b7ec8(void *);
extern "C" int FUN_002b7ee0(void *);

struct Obj { char pad[0x2c]; int f2c; char pad2[0xe8 - 0x30]; int fe8; };

static inline bool Running() { return !DAT_0034a80c; }

extern "C" int FUN_00290c94(Obj *self)
{
  int r;
  int buf[3];
  for (;;) {
    if (!Running()) break;
    r = FUN_002b7ee0(self);
    if (r < 0) { FUN_0028fb44("ERROR: scePsmfPlayerGetCurrentStatus()[2]: 0x%08x\n", r); break; }
    if (r == 2) break;
    buf[0] = 0x200;
    buf[1] = self->f2c;
    buf[2] = 0;
    r = FUN_002b7ec8(self);
    if (r != 0) { FUN_0028fb44("ERROR: scePsmfPlayerUpdate(): 0x%08x\n", r); break; }
    r = FUN_002b7ea8(self, buf);
    if (r != (int)0x8061600c && r < 0) { FUN_0028fb44("ERROR: scePsmfPlayerGetVideoData(): 0x%08x\n", r); break; }
    self->fe8 = buf[2];
    r = FUN_002b7a78();
    if (r < 0) { FUN_0028fb44(DAT_002ff830, r); break; }
  }
  FUN_002b79b0(0);
  return 0;
}
