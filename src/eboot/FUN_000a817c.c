/* HSTMATCH module=EBOOT.BIN start=0x000a817c end=0x000a81b4 symbol=FUN_000a817c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338b44;
extern void FUN_000dc820();
extern void FUN_000dc90c();

void FUN_000a817c(int param_1)
{
  FUN_000dc90c(DAT_00338b44,*(u32 *)(param_1 + 0x144),*(u32 *)(param_1 + 0x148));
  FUN_000dc820(DAT_00338b44);
}
