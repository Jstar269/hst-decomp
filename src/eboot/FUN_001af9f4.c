/* HSTMATCH module=EBOOT.BIN start=0x001af9f4 end=0x001afa00 symbol=FUN_001af9f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001ad350();

void FUN_001af9f4(int param_1)
{
  FUN_001ad350(*(u32 *)(param_1 + 0xc),1);
}
