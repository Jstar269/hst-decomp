/* HSTMATCH module=EBOOT.BIN start=0x001f94ac end=0x001f94b8 symbol=FUN_001f94ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001e7c64();

void FUN_001f94ac(int param_1)
{
  FUN_001e7c64(*(u32 *)(param_1 + 0x510),1);
}
