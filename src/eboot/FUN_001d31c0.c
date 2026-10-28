/* HSTMATCH module=EBOOT.BIN start=0x001d31c0 end=0x001d31c8 symbol=FUN_001d31c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d31c0(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x84) = param_2;
}
