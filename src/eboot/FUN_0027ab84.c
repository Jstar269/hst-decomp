/* HSTMATCH module=EBOOT.BIN start=0x0027ab84 end=0x0027ab98 symbol=FUN_0027ab84 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_0027ab84(int param_1,int param_2)
{
  return *(int *)(param_2 + 0x10) < *(int *)(*(int *)(param_1 + 4) + 0x10);
}
