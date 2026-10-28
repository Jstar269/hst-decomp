/* HSTMATCH module=EBOOT.BIN start=0x001791f8 end=0x00179210 symbol=FUN_001791f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001791f8(int param_1,int param_2)
{
  return **(u32 **)(*(int *)(param_1 + 0x1f0) + param_2 * 4);
}
