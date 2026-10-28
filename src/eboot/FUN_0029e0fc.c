/* HSTMATCH module=EBOOT.BIN start=0x0029e0fc end=0x0029e108 symbol=FUN_0029e0fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0029e0fc(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x28);
}
