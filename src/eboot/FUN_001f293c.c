/* HSTMATCH module=EBOOT.BIN start=0x001f293c end=0x001f2944 symbol=FUN_001f293c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00216c28();

void FUN_001f293c(int param_1)
{
  FUN_00216c28(*(u32 *)(param_1 + 0x560));
}
