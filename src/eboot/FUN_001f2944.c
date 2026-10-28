/* HSTMATCH module=EBOOT.BIN start=0x001f2944 end=0x001f294c symbol=FUN_001f2944 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00216c28();

void FUN_001f2944(int param_1)
{
  FUN_00216c28(*(u32 *)(param_1 + 0x560));
}
