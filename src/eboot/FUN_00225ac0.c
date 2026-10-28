/* HSTMATCH module=EBOOT.BIN start=0x00225ac0 end=0x00225b00 symbol=FUN_00225ac0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000f6b0c();

void FUN_00225ac0(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  FUN_000f6b0c(*(u32 *)(iVar1 + 0x30),0);
  iVar1 = *(int *)(iVar1 + 0x20);
  *(u32 *)(iVar1 + 0x78) = 0xffffffff;
  *(u32 *)(iVar1 + 0x7c) = 0;
  *(u32 *)(iVar1 + 0x80) = 0;
}
