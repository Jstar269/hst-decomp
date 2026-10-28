/* HSTMATCH module=EBOOT.BIN start=0x00115ca4 end=0x00115cac symbol=FUN_00115ca4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00115ca4(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x145) = param_2;
}
