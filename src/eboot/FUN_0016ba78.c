/* HSTMATCH module=EBOOT.BIN start=0x0016ba78 end=0x0016baa0 symbol=FUN_0016ba78 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0016bb88();

void FUN_0016ba78(u8 param_1)
{
  int iVar1;
  
  iVar1 = FUN_0016bb88();
  *(u8 *)(iVar1 + 0x103c) = param_1;
}
