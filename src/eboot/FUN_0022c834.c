/* HSTMATCH module=EBOOT.BIN start=0x0022c834 end=0x0022c84c symbol=FUN_0022c834 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;
extern u32 * FUN_000149a8();

void FUN_0022c834(u32 param_1)
{
  FUN_000149a8(DAT_003415a8 + 0xe010,param_1);
}
