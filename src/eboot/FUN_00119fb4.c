/* HSTMATCH module=EBOOT.BIN start=0x00119fb4 end=0x0011a004 symbol=FUN_00119fb4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;

void FUN_00119fb4(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(DAT_003386b0 + 0xa0);
  *(int *)(iVar1 + 0xb4) = *(int *)(iVar1 + 0xb4) + *(int *)(param_1 + 0xf4);
  *(int *)(iVar1 + 0x110) = *(int *)(iVar1 + 0x110) + *(int *)(param_1 + 0xf8);
  *(int *)(iVar1 + 0x16c) = *(int *)(iVar1 + 0x16c) + *(int *)(param_1 + 0xfc);
  *(int *)(iVar1 + 0x1c8) = *(int *)(iVar1 + 0x1c8) + *(int *)(param_1 + 0x100);
}
