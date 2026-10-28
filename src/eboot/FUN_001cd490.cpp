/* HSTMATCH module=EBOOT.BIN start=0x001cd490 end=0x001cd55c symbol=FUN_001cd490 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: preserve the positive guard and type the global manager virtual dispatch; exact match verified; names and types await human review. */
#include "hst/types.h"
struct Manager { virtual void f0(); virtual void f1(); };
extern "C" {
  extern Manager *DAT_0033b580;
  void FUN_0012de6c(...);
  void FUN_0012f3f0(...);
}
extern "C" int FUN_001cd490(int param_1, int param_2, int param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8)
{
  int state;
  if (param_2 > 0) {
    *(u8 *)(*(int *)(param_1 + 0x15c) + 0x60) = 1;
    if (DAT_0033b580 != 0) {
      FUN_0012de6c((int)DAT_0033b580, 4, param_2, param_3, param_5, param_6, param_7, param_8);
    }
  } else {
    state = *(int *)(param_1 + 0x15c);
    *(u8 *)(state + 0x60) = 0;
    *(u8 *)(*(int *)(state + 0x20) + 0x6d) = 1;
    if (DAT_0033b580 != 0 && param_3 > 0) {
      FUN_0012de6c((int)DAT_0033b580, 0, 0, 0, param_5, param_6, param_7, param_8);
    }
    if (param_3 == 2 && DAT_0033b580 != 0) {
      DAT_0033b580->f1();
      FUN_0012f3f0((int)DAT_0033b580);
    }
  }
}

