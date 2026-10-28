/* HSTMATCH module=EBOOT.BIN start=0x000e98f0 end=0x000e9904 symbol=FUN_000e98f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e30;

int FUN_000e98f0(int param_1)
{
  *(u8 **)(param_1 + 0x40) = &DAT_002c0e30;
  return param_1;
}
