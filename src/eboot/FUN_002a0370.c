/* HSTMATCH module=EBOOT.BIN start=0x002a0370 end=0x002a038c symbol=FUN_002a0370 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_002a0370(int param_1)
{
  return (*(u16 *)(**(int **)(*(int *)(param_1 + 0x54) + 0x10) + 0xe) & 3) != 0;
}
