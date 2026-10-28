/* HSTMATCH module=EBOOT.BIN start=0x0022c1ac end=0x0022c1c4 symbol=FUN_0022c1ac lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

void FUN_0022c1ac(u32 param_1)
{
  *(u32 *)(DAT_003415a8 + 0xd4d4) = param_1;
}
