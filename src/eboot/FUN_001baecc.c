/* HSTMATCH module=EBOOT.BIN start=0x001baecc end=0x001baef8 symbol=FUN_001baecc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001baecc(int param_1,int param_2)
{
  u8 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(**(int **)(*(int *)(param_1 + 4) + param_2 * 4) + 0x5c);
  uVar1 = 0;
  if (iVar2 != 0) {
    uVar1 = *(u8 *)(iVar2 + 0x171);
  }
  return uVar1;
}
