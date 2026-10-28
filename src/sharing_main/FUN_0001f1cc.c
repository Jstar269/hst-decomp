/* HSTMATCH module=hstp_trans_main.prx start=0x0001f1cc end=0x0001f224 symbol=FUN_0001f1cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001f224();

void FUN_0001f1cc(u32 param_1,u32 param_2)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    FUN_0001f224(param_1,param_2,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
}
