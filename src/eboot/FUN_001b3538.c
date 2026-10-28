/* HSTMATCH module=EBOOT.BIN start=0x001b3538 end=0x001b3544 symbol=FUN_001b3538 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001b3538(int *param_1,u32 param_2)
{
  *(u32 *)(*param_1 + 0x7a0) = param_2;
}
