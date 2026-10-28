/* HSTMATCH module=EBOOT.BIN start=0x0029e0f0 end=0x0029e0fc symbol=FUN_0029e0f0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_0029e0f0(int param_1)
{
  return *(u8 *)(*(int *)(param_1 + 0x3c) + 0x24);
}
