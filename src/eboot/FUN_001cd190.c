/* HSTMATCH module=EBOOT.BIN start=0x001cd190 end=0x001cd1a4 symbol=FUN_001cd190 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001cd190(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x15c) + 4) == 10;
}
