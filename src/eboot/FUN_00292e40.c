/* HSTMATCH module=EBOOT.BIN start=0x00292e40 end=0x00292e48 symbol=FUN_00292e40 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00292e40(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x34) = param_2;
}
