/* HSTMATCH module=EBOOT.BIN start=0x002b42a0 end=0x002b42b4 symbol=FUN_002b42a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_002b42a0(int param_1,int param_2)
{
  return *(int *)(param_2 + 0x50) < *(int *)(*(int *)(param_1 + 4) + 0x50);
}
