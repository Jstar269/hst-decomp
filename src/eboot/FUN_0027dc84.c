/* HSTMATCH module=EBOOT.BIN start=0x0027dc84 end=0x0027dc90 symbol=FUN_0027dc84 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0027dc84(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x74);
}
