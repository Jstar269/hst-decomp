/* HSTMATCH module=EBOOT.BIN start=0x00198d30 end=0x00198d38 symbol=FUN_00198d30 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00198d30(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x9c) = param_2;
}
