/* HSTMATCH module=EBOOT.BIN start=0x002667f4 end=0x002667fc symbol=FUN_002667f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002667f4(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x114) = param_2;
}
