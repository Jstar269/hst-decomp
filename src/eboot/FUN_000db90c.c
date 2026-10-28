/* HSTMATCH module=EBOOT.BIN start=0x000db90c end=0x000db93c symbol=FUN_000db90c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000db90c(int param_1)
{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(int *)(param_1 + 0x8c) != 0) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  return 1;
}
