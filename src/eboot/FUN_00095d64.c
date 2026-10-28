/* HSTMATCH module=EBOOT.BIN start=0x00095d64 end=0x00095d94 symbol=FUN_00095d64 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

u32 FUN_00095d64(u32 param_1)
{
  FUN_000114c0(param_1,0,0x90);
  return param_1;
}
