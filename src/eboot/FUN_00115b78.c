/* HSTMATCH module=EBOOT.BIN start=0x00115b78 end=0x00115bac symbol=FUN_00115b78 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00101f48();

void FUN_00115b78(int param_1,u16 param_2)
{
  FUN_00101f48();
  *(u16 *)(param_1 + 0x908) = param_2;
}
