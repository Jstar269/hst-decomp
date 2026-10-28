/* HSTMATCH module=EBOOT.BIN start=0x001afa00 end=0x001afa0c symbol=FUN_001afa00 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001ad604();

void FUN_001afa00(int param_1)
{
  FUN_001ad604(*(u32 *)(param_1 + 0xc),1);
}
