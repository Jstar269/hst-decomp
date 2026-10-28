/* HSTMATCH module=EBOOT.BIN start=0x000c50c4 end=0x000c50cc symbol=FUN_000c50c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002861e0();

void FUN_000c50c4(int param_1)
{
  FUN_002861e0(*(u32 *)(param_1 + 0x784));
}
