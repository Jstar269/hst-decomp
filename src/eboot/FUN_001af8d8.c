/* HSTMATCH module=EBOOT.BIN start=0x001af8d8 end=0x001af8e4 symbol=FUN_001af8d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001acc30();

void FUN_001af8d8(int param_1)
{
  FUN_001acc30(*(u32 *)(param_1 + 0xc),1);
}
