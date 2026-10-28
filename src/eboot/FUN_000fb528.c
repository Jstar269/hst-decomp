/* HSTMATCH module=EBOOT.BIN start=0x000fb528 end=0x000fb544 symbol=FUN_000fb528 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_000fb528(int param_1)
{
  u8 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 100);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = *(u8 *)(iVar2 + 0xb0);
  }
  return uVar1;
}
