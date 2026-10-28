/* HSTMATCH module=EBOOT.BIN start=0x001baf80 end=0x001bafac symbol=FUN_001baf80 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0019d474();

u8 FUN_001baf80(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0019d474();
  return *(u8 *)(param_1 + iVar1 + 0x5c);
}
