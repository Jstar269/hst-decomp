/* HSTMATCH module=EBOOT.BIN start=0x002a10a0 end=0x002a10d8 symbol=FUN_002a10a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

void FUN_002a10a0(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0001342c();
  *(int *)(param_1 + 0x1d8) = iVar1 % 0x96 + 0x96;
}
