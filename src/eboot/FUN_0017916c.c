/* HSTMATCH module=EBOOT.BIN start=0x0017916c end=0x00179178 symbol=FUN_0017916c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0017916c(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x1d4) + 4);
}
