/* HSTMATCH module=EBOOT.BIN start=0x000eee60 end=0x000eee98 symbol=FUN_000eee60 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000eeec8();
extern void FUN_001036f8();

void FUN_000eee60(int param_1)
{
  *(u32 *)(param_1 + 0x6c) = 0;
  *(u32 *)(param_1 + 0x70) = 0;
  FUN_000eeec8();
  FUN_001036f8(param_1,0);
}
