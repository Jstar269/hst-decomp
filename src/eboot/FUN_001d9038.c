/* HSTMATCH module=EBOOT.BIN start=0x001d9038 end=0x001d9048 symbol=FUN_001d9038 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001d9038(int param_1)
{
  return *(int *)(param_1 + 4) == 1;
}
