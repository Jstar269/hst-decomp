/* HSTMATCH module=EBOOT.BIN start=0x0011844c end=0x0011847c symbol=FUN_0011844c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0011847c();

int FUN_0011844c(int param_1)
{
  FUN_0011847c();
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
