/* HSTMATCH module=EBOOT.BIN start=0x001eab18 end=0x001eab2c symbol=FUN_001eab18 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001eab18(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  *(u8 *)(iVar1 + 0x43c) = 1;
  *(u32 *)(iVar1 + 0x440) = 0;
}
