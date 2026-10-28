/* HSTMATCH module=EBOOT.BIN start=0x00216de8 end=0x00216e00 symbol=FUN_00216de8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

int FUN_00216de8(u32 param_1)
{
  int iVar1;
  
  iVar1 = (int)param_1 >> 1;
  if ((param_1 & 1) != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}
