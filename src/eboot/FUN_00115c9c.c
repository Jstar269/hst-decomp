/* HSTMATCH module=EBOOT.BIN start=0x00115c9c end=0x00115ca4 symbol=FUN_00115c9c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00115c9c(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x144) = param_2;
}
