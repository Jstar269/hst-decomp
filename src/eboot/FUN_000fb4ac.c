/* HSTMATCH module=EBOOT.BIN start=0x000fb4ac end=0x000fb4d0 symbol=FUN_000fb4ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000fb4ac(int param_1,u8 param_2)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x3c) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x3c) + 0x8c), iVar1 != 0)) {
    *(u8 *)(iVar1 + 0x870) = param_2;
  }
}
