/* HSTMATCH module=EBOOT.BIN start=0x00225d74 end=0x00225d98 symbol=FUN_00225d74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00225d74(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x20);
  *(u32 *)(iVar1 + 0x78) = 0xffffffff;
  if (param_2 != 0) {
    *(u32 *)(iVar1 + 0x7c) = 0;
    *(u32 *)(iVar1 + 0x80) = 0;
  }
}
