/* HSTMATCH module=hstp_trans_main.prx start=0x0001cb60 end=0x0001cbf0 symbol=FUN_0001cb60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: reversed the direct and indirect callback arms to match the retail branch path; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern int FUN_00000a90();
extern u32 * FUN_00011090();

int FUN_0001cb60(int param_1,u32 *param_2,code *param_3)
{
  int iVar1;
  u32 uVar2;
  
  uVar2 = *param_2;
  iVar1 = param_2[1];
  if (param_1 == 0) {
    param_1 = FUN_00000a90(uVar2);
  }
  if (iVar1 != 0) {
    (*param_3)(param_1,param_2 + 2,uVar2);
  } else {
    FUN_00011090(param_1,param_2 + 2,uVar2);
  }
  return param_1;
}
