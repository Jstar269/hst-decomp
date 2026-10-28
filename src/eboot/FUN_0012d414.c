/* HSTMATCH module=EBOOT.BIN start=0x0012d414 end=0x0012d454 symbol=FUN_0012d414 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000550c8();

void FUN_0012d414(int param_1,u32 param_2)
{
  FUN_000550c8(*(u32 *)(param_1 + 4));
  FUN_000550c8(*(u32 *)(param_1 + 0xc),param_2);
}
