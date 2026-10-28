/* HSTMATCH module=EBOOT.BIN start=0x001cd150 end=0x001cd164 symbol=FUN_001cd150 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001cd150(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x15c) + 4) == 4;
}
