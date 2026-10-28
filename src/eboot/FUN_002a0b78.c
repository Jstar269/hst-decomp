/* HSTMATCH module=EBOOT.BIN start=0x002a0b78 end=0x002a0b84 symbol=FUN_002a0b78 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002a0b78(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 8) + 8);
}
