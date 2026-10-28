/* HSTMATCH module=EBOOT.BIN start=0x00289c44 end=0x00289c58 symbol=FUN_00289c44 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00289c44(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
}
