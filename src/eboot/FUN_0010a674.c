/* HSTMATCH module=EBOOT.BIN start=0x0010a674 end=0x0010a684 symbol=FUN_0010a674 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_0010a674(int param_1)
{
  return *(int *)(param_1 + 0x240) == 1;
}
