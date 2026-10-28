/* HSTMATCH module=EBOOT.BIN start=0x000e6d4c end=0x000e6e24 symbol=FUN_000e6d4c lang=c++ */
/* Clone of src/sharing_main/FUN_000ebd48.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

struct EmptyTag {};
struct VC_000e6d4c {
  virtual ~VC_000e6d4c();
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
};

extern u32 DAT_00307634;
extern "C" {
extern void FUN_000006e8(int, void (*)());
extern void FUN_00000a00(void *);
extern int * FUN_0001f0f0(int *, int);
extern void FUN_0005aeac();
extern void FUN_000e85c4(int *, int, EmptyTag);
extern void FUN_000e8744(int *, int);
extern void FUN_000e855c(int *, int);
}

extern "C" int * FUN_000e6d4c(int *param_1, short param_2)
{
  int *piVar1;
  int iVar2;

  if (param_1 != 0) {
    *(void **)param_1 = &DAT_00307634;
    ((VC_000e6d4c *)param_1)->m4();
    if (param_1[0x37] != 0) {
      FUN_000006e8(param_1[0x37], FUN_0005aeac);
      param_1[0x37] = 0;
    }
    iVar2 = param_1[0x13];
    FUN_000e85c4(param_1 + 0x12, iVar2, EmptyTag());
    piVar1 = param_1 + 0x12;
    if ((piVar1 != 0) && (piVar1 != 0)) {
      FUN_000e8744(piVar1, 0);
    }
    piVar1 = param_1 + 0xf;
    if ((piVar1 != 0) && (piVar1 != 0)) {
      FUN_000e855c(piVar1, 0);
    }
    FUN_0001f0f0(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
