/* HSTMATCH module=EBOOT.BIN start=0x000944bc end=0x000944c8 symbol=FUN_000944bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000944bc(int param_1,u32 param_2,u32 param_3)
{
  *(u32 *)(param_1 + 0x20) = param_2;
  *(u32 *)(param_1 + 0x24) = param_3;
}
