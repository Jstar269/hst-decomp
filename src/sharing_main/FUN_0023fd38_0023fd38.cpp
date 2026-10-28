/* HSTMATCH module=hstp_trans_main.prx start=0x0023fd38 end=0x0023fddc symbol=FUN_0023fd38 lang=c++ */
/* Clone of src/eboot/FUN_0022fc38_0022fc38.cpp (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u32 DAT_003f3b4c;
extern u8 * DAT_003f469c;
extern void FUN_00108aec(void *);
extern void FUN_0016a4b4(void *);
extern void FUN_002a2db8(u32);
}
struct VC { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); };
struct Obj {
  char pad0[0x54];
  unsigned char flag;
  char pad1[0x214 - 0x55];
  VC *field214;
  char pad2[4];
  int *field21c;
  char pad3[0x414 - 0x220];
  int mode;
};

extern "C" void FUN_0023fd38(Obj *param_1)
{
  if (param_1->mode == 5) {
    FUN_002a2db8(DAT_003f3b4c);
  }
  else if ((DAT_003f469c == 0) || (*(int *)(DAT_003f469c + 0x5d0) == 0)) {
    FUN_00108aec(param_1);
    if (param_1->field21c != 0) {
      FUN_0016a4b4(param_1->field21c);
    }
    if ((param_1->flag != 0) && (param_1->field214 != 0)) {
      param_1->field214->f3();
    }
  }
}

