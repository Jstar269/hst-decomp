/* HSTMATCH module=EBOOT.BIN start=0x00225b6c end=0x00225b78 symbol=FUN_00225b6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000f6b0c();

void FUN_00225b6c(int param_1)
{
  FUN_000f6b0c(*(u32 *)(*(int *)(param_1 + 0x3c) + 0x30));
}
