/* HSTMATCH module=EBOOT.BIN start=0x001cd804 end=0x001cd810 symbol=FUN_001cd804 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001cd804(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x15c) + 0x2c);
}
