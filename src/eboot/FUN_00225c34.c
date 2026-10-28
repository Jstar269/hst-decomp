/* HSTMATCH module=EBOOT.BIN start=0x00225c34 end=0x00225c40 symbol=FUN_00225c34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0021b5d8();

void FUN_00225c34(int param_1)
{
  FUN_0021b5d8(*(u32 *)(*(int *)(param_1 + 0x3c) + 8));
}
