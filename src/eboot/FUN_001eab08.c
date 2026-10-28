/* HSTMATCH module=EBOOT.BIN start=0x001eab08 end=0x001eab18 symbol=FUN_001eab08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_001eab08(int *param_1)
{
  return *(int *)(*param_1 + 0x3e4) != 0;
}
