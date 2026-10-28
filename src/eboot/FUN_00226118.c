/* HSTMATCH module=EBOOT.BIN start=0x00226118 end=0x00226128 symbol=FUN_00226118 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00226118(int param_1)
{
  return *(u32 *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x24) + 0x90);
}
