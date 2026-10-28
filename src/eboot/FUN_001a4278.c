/* HSTMATCH module=EBOOT.BIN start=0x001a4278 end=0x001a4294 symbol=FUN_001a4278 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001a4278(int param_1)
{
  *(u32 *)(param_1 + 0x2e8) = *(u32 *)(param_1 + 0x2e4);
  *(u32 *)(param_1 + 0x2f0) = *(u32 *)(param_1 + 0x2ec);
  *(u32 *)(param_1 + 0x2f8) = *(u32 *)(param_1 + 0x2f4);
}
