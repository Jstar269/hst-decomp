/* HSTMATCH module=hstp_trans_main.prx start=0x001b93f4 end=0x001b9500 symbol=FUN_001b93f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/types.h"

extern "C" {
void *FUN_001aa91c(void);
void FUN_001b8e10(u32, int, int);
void FUN_001b7f74(u32, int, int);
}

extern "C" void FUN_001b93f4(u32 param_1, int param_2)
{
  int uVar3;
  u8 val;

  val = *(u8 *)((int)FUN_001aa91c() + 0x11c);
  switch (val) {
  case 0:
  case 4:
    int ok = 1;
    uVar3 = 0;
    int a2 = param_2;
    if (param_2 == 0) {
      a2 = param_2;
    }
    else if (param_2 == 2) {
      a2 = 3;
      uVar3 = 10;
    }
    else {
      ok = 0;
    }
    if (!ok) return;
    FUN_001b8e10(param_1, param_2, a2);
    FUN_001b7f74(param_1, param_2, uVar3);
    return;
  default:
    uVar3 = 0;
    if (param_2 == 0) {
      uVar3 = 20;
    }
    else if (param_2 == 1) {
      uVar3 = 30;
    }
    else if (param_2 == 2) {
      uVar3 = 40;
    }
    else if (param_2 == 3) {
      uVar3 = 50;
    }
    FUN_001b8e10(param_1, param_2, param_2);
    FUN_001b7f74(param_1, param_2, uVar3);
    break;
  }
}
