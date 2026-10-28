/* HSTMATCH module=EBOOT.BIN start=0x001f1e8c end=0x001f1ea8 symbol=FUN_001f1e8c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001f1e8c(int param_1)
{
  if (*(int *)(param_1 + 0x44) == 0) {
    *(u8 *)(param_1 + 0x515) = 1;
  }
}
