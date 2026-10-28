/* HSTMATCH module=EBOOT.BIN start=0x0025a360 end=0x0025a370 symbol=FUN_0025a360 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_0025a360(int param_1)
{
  return *(int *)(param_1 + 4) == 0;
}
