/* HSTMATCH module=hstp_trans_main.prx start=0x001dbb6c end=0x001dbc38 symbol=FUN_001dbb6c lang=c++ */
/* Clone of src/eboot/FUN_001cd490.cpp (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: preserve the positive guard and type the global manager virtual dispatch; exact match verified; names and types await human review. */
#include "hst/types.h"
struct Manager { virtual void f0(); virtual void f1(); };
extern "C" {
  extern Manager *DAT_003e48c0;
  void FUN_0013936c(...);
  void FUN_0013a948(...);
}
extern "C" int FUN_001dbb6c(int param_1, int param_2, int param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8)
{
  int state;
  if (param_2 > 0) {
    *(u8 *)(*(int *)(param_1 + 0x15c) + 0x60) = 1;
    if (DAT_003e48c0 != 0) {
      FUN_0013936c((int)DAT_003e48c0, 4, param_2, param_3, param_5, param_6, param_7, param_8);
    }
  } else {
    state = *(int *)(param_1 + 0x15c);
    *(u8 *)(state + 0x60) = 0;
    *(u8 *)(*(int *)(state + 0x20) + 0x6d) = 1;
    if (DAT_003e48c0 != 0 && param_3 > 0) {
      FUN_0013936c((int)DAT_003e48c0, 0, 0, 0, param_5, param_6, param_7, param_8);
    }
    if (param_3 == 2 && DAT_003e48c0 != 0) {
      DAT_003e48c0->f1();
      FUN_0013a948((int)DAT_003e48c0);
    }
  }
}

