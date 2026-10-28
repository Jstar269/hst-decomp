/* HSTMATCH module=EBOOT.BIN start=0x001ecbbc end=0x001ecbc4 symbol=FUN_001ecbbc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001ecbbc(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 8) = param_2;
}
