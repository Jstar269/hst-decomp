/* HSTMATCH module=EBOOT.BIN start=0x0017e9b0 end=0x0017e9c0 symbol=FUN_0017e9b0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0017e9b0(int param_1)
{
  *(u8 *)(param_1 + 0x2d4) = 1;
  *(u32 *)(param_1 + 0x2d0) = 0;
}
