/* HSTMATCH module=EBOOT.BIN start=0x002a1a4c end=0x002a1a64 symbol=FUN_002a1a4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002a1a4c(u32 *param_1,u32 param_2)
{
  *param_1 = param_2;
  *(u8 *)(param_1 + 1) = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  *(u8 *)(param_1 + 0x43) = 0;
}
