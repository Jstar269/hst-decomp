/* HSTMATCH module=EBOOT.BIN start=0x0021f30c end=0x0021f338 symbol=FUN_0021f30c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_0021f30c(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
}
