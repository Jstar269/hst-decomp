/* HSTMATCH module=EBOOT.BIN start=0x000fb504 end=0x000fb528 symbol=FUN_000fb504 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_000fb504(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x3c) + 100);
  bVar1 = true;
  if (iVar2 != 0) {
    bVar1 = *(int *)(iVar2 + 0xb8) == 5;
  }
  return bVar1;
}
