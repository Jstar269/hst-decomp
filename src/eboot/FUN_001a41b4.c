/* HSTMATCH module=EBOOT.BIN start=0x001a41b4 end=0x001a41d0 symbol=FUN_001a41b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001a41b4(int param_1)
{
  *(u32 *)(param_1 + 0x2cc) = *(u32 *)(param_1 + 0x2c0);
  *(u32 *)(param_1 + 0x2d0) = *(u32 *)(param_1 + 0x2c4);
  *(u32 *)(param_1 + 0x2d4) = *(u32 *)(param_1 + 0x2c8);
}
