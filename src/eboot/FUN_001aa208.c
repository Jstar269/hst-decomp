/* HSTMATCH module=EBOOT.BIN start=0x001aa208 end=0x001aa244 symbol=FUN_001aa208 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0016b0c0();
extern u32 FUN_0019d474();

void FUN_001aa208(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0019d474();
  iVar1 = FUN_0016b0c0(*(u32 *)(iVar1 + 0x2ec));
  *(int *)(*(int *)(param_1 + 0xac) + 0x24) = *(int *)(*(int *)(param_1 + 0xac) + 0x28) + iVar1;
}
