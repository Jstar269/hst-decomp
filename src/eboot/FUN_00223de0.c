/* HSTMATCH module=EBOOT.BIN start=0x00223de0 end=0x00223e18 symbol=FUN_00223de0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000ffb3c();
extern void FUN_00103628();

void FUN_00223de0(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
  FUN_000ffb3c(*(u32 *)(param_1 + 100),1);
}
