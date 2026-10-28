/* HSTMATCH module=EBOOT.BIN start=0x001b3590 end=0x001b359c symbol=FUN_001b3590 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001b3590(int *param_1,u8 param_2)
{
  *(u8 *)(*param_1 + 0x7dd) = param_2;
}
