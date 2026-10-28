/* HSTMATCH module=hstp_trans_main.prx start=0x0020e490 end=0x0020e58c symbol=FUN_0020e490 lang=c++ */
/* Clone of src/eboot/deleting_dtor_001ffcc0.cpp (hstclone.py tag c160307): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: the global tested before FUN_000009e4 is that call's argument (Ghidra dropped it, so retail loads it into a0); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void *DAT_003f347c;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(...);
extern int FUN_0022667c(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" int FUN_0020e490(int param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != 0) {
    if (DAT_003f347c) {
      FUN_000009e4(DAT_003f347c);
      DAT_003f347c = 0;
    }
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(u32 *)(param_1 + 4) = 0;
    }
    FUN_0022667c(param_1 + 0xb78,0xffffffff);
    FUN_0022667c(param_1 + 0xaec,0xffffffff);
    FUN_0022667c(param_1 + 0xa60,0xffffffff);
    FUN_0022667c(param_1 + 0x9d4,0xffffffff);
    FUN_0022667c(param_1 + 0x948,0xffffffff);
    FUN_0022667c(param_1 + 0x8bc,0xffffffff);
    FUN_0022667c(param_1 + 0x830,0xffffffff);
    FUN_0022667c(param_1 + 0x7a4,0xffffffff);
    FUN_0022667c(param_1 + 0x718,0xffffffff);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
