/* HSTMATCH module=EBOOT.BIN start=0x001e74d4 end=0x001e750c symbol=FUN_001e74d4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e750c();

void FUN_001e74d4(int param_1)
{
  FUN_001e2694();
  FUN_00103628(*(u32 *)(param_1 + 0x21e4),0);
  FUN_001e750c(param_1);
}
