/* HSTMATCH module=EBOOT.BIN start=0x0017df34 end=0x0017df44 symbol=FUN_0017df34 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0017df34(int param_1)
{
  *(u8 *)(param_1 + 0x41) = 1;
  *(u32 *)(param_1 + 0x44) = 0;
}
