/* HSTMATCH module=EBOOT.BIN start=0x002259a8 end=0x002259b4 symbol=FUN_002259a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002259a8(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x2c);
}
