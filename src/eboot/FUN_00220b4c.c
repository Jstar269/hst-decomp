/* HSTMATCH module=EBOOT.BIN start=0x00220b4c end=0x00220b7c symbol=FUN_00220b4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_00220b4c(int param_1)
{
  FUN_00103628(param_1,1);
  *(u8 *)(param_1 + 0x54) = 1;
}
