/* HSTMATCH module=EBOOT.BIN start=0x00095dd8 end=0x00095e10 symbol=FUN_00095dd8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

int FUN_00095dd8(int param_1)
{
  *(u32 *)(param_1 + 0x2c) = 1;
  FUN_000114c0(param_1,0,0x40);
  return param_1;
}
