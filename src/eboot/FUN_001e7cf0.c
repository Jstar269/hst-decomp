/* HSTMATCH module=EBOOT.BIN start=0x001e7cf0 end=0x001e7d28 symbol=FUN_001e7cf0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002178ac();

void FUN_001e7cf0(int param_1)
{
  FUN_002178ac(param_1 + 0x252c,0x80,0,10);
  *(u32 *)(param_1 + 0x2528) = 0;
}
