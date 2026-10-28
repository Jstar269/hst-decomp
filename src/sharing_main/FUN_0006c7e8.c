/* HSTMATCH module=hstp_trans_main.prx start=0x0006c7e8 end=0x0006c85c symbol=FUN_0006c7e8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0006d71c();

void FUN_0006c7e8(int *param_1,char *param_2,int *param_3)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_0006d71c(param_2,param_3,*(u32 *)(param_2 + 4),param_2 + 4));
  if ((iVar1 == param_2 + 4) || (*param_3 < *(int *)(iVar1 + 0xc))) {
    *param_1 = (int)(param_2 + 4);
  }
  else {
    *param_1 = (int)(iVar1);
  }
}
