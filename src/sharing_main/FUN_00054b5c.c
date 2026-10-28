/* HSTMATCH module=hstp_trans_main.prx start=0x00054b5c end=0x00054ba4 symbol=FUN_00054b5c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0002e7f8();
extern void FUN_00054ba4();

void FUN_00054b5c(int param_1,u32 param_2)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_0002e7f8(*(int *)(param_1 + 8) + 0x10);
  FUN_00054ba4(param_1,param_2,*puVar1);
}
