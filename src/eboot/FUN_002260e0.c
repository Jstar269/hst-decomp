/* HSTMATCH module=EBOOT.BIN start=0x002260e0 end=0x00226118 symbol=FUN_002260e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_002260e0(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x24);
  FUN_00103628(iVar1,1);
  *(u8 *)(iVar1 + 0x54) = 1;
}
