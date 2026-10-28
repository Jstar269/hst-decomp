/* HSTMATCH module=EBOOT.BIN start=0x0023e468 end=0x0023e47c symbol=FUN_0023e468 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0023de6c();

void FUN_0023e468(int param_1)
{
  *(u32 *)(*(int *)(param_1 + 0x14c0) + 0x1c) = 0;
  FUN_0023de6c(param_1,1,0);
}
