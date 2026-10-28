/* HSTMATCH module=EBOOT.BIN start=0x0021fb70 end=0x0021fb9c symbol=FUN_0021fb70 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00103628();

void FUN_0021fb70(int param_1)
{
  FUN_00103628(param_1,0);
  *(u8 *)(param_1 + 0x54) = 0;
}
