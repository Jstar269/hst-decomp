/* HSTMATCH module=EBOOT.BIN start=0x00250cc4 end=0x00250cec symbol=FUN_00250cc4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00250cc4(int param_1)
{
  u32 uVar1;
  
  uVar1 = 1;
  if ((*(int *)(param_1 + 0x2f8) != 4) && (*(int *)(param_1 + 0x2f8) != 6)) {
    uVar1 = 0;
  }
  return uVar1;
}
