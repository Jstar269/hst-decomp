/* HSTMATCH module=EBOOT.BIN start=0x001da1bc end=0x001da1c8 symbol=FUN_001da1bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001da1bc(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x58) + 0xdc);
}
