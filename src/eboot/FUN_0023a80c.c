/* HSTMATCH module=EBOOT.BIN start=0x0023a80c end=0x0023a830 symbol=FUN_0023a80c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a6bc;

bool FUN_0023a80c(int param_1)
{
  return (*(int *)(param_1 + 0x1850) / *(int *)(DAT_0034a6bc + 0x18b8) & 1U) != 0;
}
