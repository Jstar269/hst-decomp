/* HSTMATCH module=EBOOT.BIN start=0x0022599c end=0x002259a8 symbol=FUN_0022599c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0022599c(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x28);
}
