/* HSTMATCH module=EBOOT.BIN start=0x0022c94c end=0x0022c988 symbol=FUN_0022c94c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415a8;

void FUN_0022c94c(int param_1)
{
  int iVar1;
  
  iVar1 = param_1 + 0x8d00 + DAT_003415a8;
  *(u8 *)(iVar1 + 0x3500) = *(u8 *)(iVar1 + 0x3500) | 2;
  iVar1 = param_1 + 0x8d00 + DAT_003415a8;
  *(u8 *)(iVar1 + 0x3500) = *(u8 *)(iVar1 + 0x3500) | 4;
}
