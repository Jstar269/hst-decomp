/* HSTMATCH module=EBOOT.BIN start=0x001b4458 end=0x001b4464 symbol=FUN_001b4458 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001b4458(int *param_1)
{
  return *(u32 *)(*param_1 + 0x7b8);
}
