/* HSTMATCH module=EBOOT.BIN start=0x001fb4ec end=0x001fb4fc symbol=FUN_001fb4ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001fb4ec(int param_1)
{
  return *(int *)(param_1 + 0x12d0) == -1;
}
