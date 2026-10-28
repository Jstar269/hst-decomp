/* HSTMATCH module=EBOOT.BIN start=0x001902d0 end=0x00190304 symbol=FUN_001902d0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000031f0();

int FUN_001902d0(int param_1)
{
  FUN_000031f0();
  *(u32 *)(param_1 + 0xc) = 0;
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
