/* HSTMATCH module=EBOOT.BIN start=0x00292e48 end=0x00292e60 symbol=FUN_00292e48 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00292e48(int param_1)
{
  *(u8 *)(param_1 + 0x40) = 0;
  *(u32 *)(param_1 + 4) = 0x41f00000;
  *(u32 *)(param_1 + 8) = 0x41f00000;
  *(u32 *)(param_1 + 0x38) = 0;
}
