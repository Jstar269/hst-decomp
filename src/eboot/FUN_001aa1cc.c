/* HSTMATCH module=EBOOT.BIN start=0x001aa1cc end=0x001aa208 symbol=FUN_001aa1cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0016b070();
extern u32 FUN_0019d474();

void FUN_001aa1cc(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_0019d474();
  iVar1 = FUN_0016b070(*(u32 *)(iVar1 + 0x2e4));
  *(int *)(*(int *)(param_1 + 0x98) + 0x24) = *(int *)(*(int *)(param_1 + 0x98) + 0x28) + iVar1;
}
