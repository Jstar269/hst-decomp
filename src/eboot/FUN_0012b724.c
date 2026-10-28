/* HSTMATCH module=EBOOT.BIN start=0x0012b724 end=0x0012b72c symbol=FUN_0012b724 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_0012b724(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x404) = param_2;
}
