/* HSTMATCH module=EBOOT.BIN start=0x0022c890 end=0x0022c8b4 symbol=FUN_0022c890 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415a8;

void FUN_0022c890(int param_1)
{
  int iVar1;
  
  iVar1 = param_1 + 0x8d00 + DAT_003415a8;
  *(u8 *)(iVar1 + 0x3500) = *(u8 *)(iVar1 + 0x3500) | 1;
}
