/* HSTMATCH module=EBOOT.BIN start=0x002a105c end=0x002a10a0 symbol=FUN_002a105c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

void FUN_002a105c(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0001342c();
  *(int *)(param_1 + 0x1f0) = (iVar1 % 0xc) * 0x1e + 0x78;
}
