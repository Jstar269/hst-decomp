/* HSTMATCH module=EBOOT.BIN start=0x00266748 end=0x00266760 symbol=FUN_00266748 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00266748(int param_1)
{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(u32 *)(*(int *)(param_1 + 0x70) + 0xd0) = 0;
  }
}
