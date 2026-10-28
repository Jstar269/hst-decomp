/* HSTMATCH module=EBOOT.BIN start=0x001afa0c end=0x001afa18 symbol=FUN_001afa0c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001ad89c();

void FUN_001afa0c(int param_1)
{
  FUN_001ad89c(*(u32 *)(param_1 + 0xc),1);
}
