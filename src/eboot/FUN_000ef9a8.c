/* HSTMATCH module=EBOOT.BIN start=0x000ef9a8 end=0x000ef9d8 symbol=FUN_000ef9a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_000ef9a8(int param_1)
{
  FUN_00103628(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
}
