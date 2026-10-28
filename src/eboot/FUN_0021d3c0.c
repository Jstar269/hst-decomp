/* HSTMATCH module=EBOOT.BIN start=0x0021d3c0 end=0x0021d3f8 symbol=FUN_0021d3c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_0021d3c0(int param_1)
{
  FUN_00103628(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
  *(u32 *)(param_1 + 100) = 0xffffffff;
}
