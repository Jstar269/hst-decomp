/* HSTMATCH module=EBOOT.BIN start=0x000b5ed4 end=0x000b5ee8 symbol=FUN_000b5ed4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000b5ed4(u32 *param_1,u32 *param_2)
{
  u32 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
}
