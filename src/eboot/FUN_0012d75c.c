/* HSTMATCH module=EBOOT.BIN start=0x0012d75c end=0x0012d76c symbol=FUN_0012d75c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_0012d75c(int param_1)
{
  return *(int *)(*(int *)(param_1 + 4) + 0x8c) != 0;
}
