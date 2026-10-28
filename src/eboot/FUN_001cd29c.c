/* HSTMATCH module=EBOOT.BIN start=0x001cd29c end=0x001cd2a8 symbol=FUN_001cd29c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001cd29c(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x15c) + 0xf4);
}
