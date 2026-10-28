/* HSTMATCH module=EBOOT.BIN start=0x000bdb14 end=0x000bdb1c symbol=FUN_000bdb14 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00126864();

void FUN_000bdb14(int param_1)
{
  FUN_00126864(*(u32 *)(param_1 + 0x26c));
}
