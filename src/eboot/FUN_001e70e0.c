/* HSTMATCH module=EBOOT.BIN start=0x001e70e0 end=0x001e70e8 symbol=FUN_001e70e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0021dbfc();

void FUN_001e70e0(int param_1)
{
  FUN_0021dbfc(*(u32 *)(param_1 + 0x1d64));
}
