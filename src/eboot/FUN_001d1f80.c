/* HSTMATCH module=EBOOT.BIN start=0x001d1f80 end=0x001d1f94 symbol=FUN_001d1f80 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001d1f80(int param_1,int param_2)
{
  return *(u32 *)(*(int *)(param_1 + 4) + param_2 * 4);
}
