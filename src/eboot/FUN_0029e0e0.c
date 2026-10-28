/* HSTMATCH module=EBOOT.BIN start=0x0029e0e0 end=0x0029e0f0 symbol=FUN_0029e0e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_0029e0e0(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x3c) + 8) != 0;
}
