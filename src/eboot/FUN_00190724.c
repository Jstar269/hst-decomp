/* HSTMATCH module=EBOOT.BIN start=0x00190724 end=0x00190738 symbol=FUN_00190724 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_00190724(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x3c) + 8) == 0;
}
