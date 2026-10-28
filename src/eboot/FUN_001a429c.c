/* HSTMATCH module=EBOOT.BIN start=0x001a429c end=0x001a42b8 symbol=FUN_001a429c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001a429c(int param_1)
{
  *(u32 *)(param_1 + 0x308) = *(u32 *)(param_1 + 0x2fc);
  *(u32 *)(param_1 + 0x30c) = *(u32 *)(param_1 + 0x300);
  *(u32 *)(param_1 + 0x310) = *(u32 *)(param_1 + 0x304);
}
