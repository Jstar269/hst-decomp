/* HSTMATCH module=EBOOT.BIN start=0x000fb868 end=0x000fb874 symbol=FUN_000fb868 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001fc4e8();

void FUN_000fb868(int param_1)
{
  FUN_001fc4e8(*(u32 *)(param_1 + 0x40),0);
}
