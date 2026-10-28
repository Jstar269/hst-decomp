/* HSTMATCH module=EBOOT.BIN start=0x0005a678 end=0x0005a770 symbol=FUN_0005a678 lang=c++ */
/* Clone of src/sharing_main/FUN_0005b448.cpp (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v17) corrected by hand: grouped the helper calls under switch cases 4, 3, and 1; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00052bf4(...);
}
struct VC_0 { virtual void d0(); virtual int m(); };

extern "C" void FUN_0005a678(int *param_1,u32 param_2,int *param_3)
{
  int iVar1;
  
  if (param_3 == (int *)0x0) {
    param_3 = param_1 + 4;
  }
  iVar1 = ((VC_0 *)(param_1))->m();
  switch (iVar1) {
  case 4:
    FUN_00052bf4(param_2,param_3,4,param_1[0x18],param_1[0x17],0,param_1[param_1[0x15] + 0x19]);
    break;
  case 3:
    FUN_00052bf4(param_2,param_3,3,param_1[0x18],param_1[0x17],0,param_1[param_1[0x15] + 0x19]);
    break;
  case 1:
    FUN_00052bf4(param_2,param_3,1,param_1[0x18],param_1[0x17],0,param_1[param_1[0x15] + 0x19]);
    break;
  }
}
