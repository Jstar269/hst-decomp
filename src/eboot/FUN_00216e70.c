/* HSTMATCH module=EBOOT.BIN start=0x00216e70 end=0x00216e90 symbol=FUN_00216e70 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00216e70(u8 *param_1,u32 *param_2,u8 param_3)
{
  u32 uVar1;
  u32 uVar2;
  
  uVar2 = param_2[2];
  uVar1 = param_2[1];
  *param_1 = (char)*param_2;
  param_1[1] = (char)uVar1;
  param_1[2] = (char)uVar2;
  param_1[3] = param_3;
}
