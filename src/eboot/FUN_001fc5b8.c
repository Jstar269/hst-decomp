/* HSTMATCH module=EBOOT.BIN start=0x001fc5b8 end=0x001fc614 symbol=FUN_001fc5b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();
extern void FUN_001fc718();

void FUN_001fc5b8(int param_1,u8 param_2)
{
  int iVar1;
  
  *(u8 *)(param_1 + 0x54) = param_2;
  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x90) = param_2;
  iVar1 = *(int *)(param_1 + 0x44);
  FUN_00103628(iVar1);
  *(u8 *)(iVar1 + 0x5c) = param_2;
  FUN_001fc718(param_1,0);
}
