/* HSTMATCH module=EBOOT.BIN start=0x0022c02c end=0x0022c044 symbol=FUN_0022c02c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

void FUN_0022c02c(u16 param_1)
{
  *(u16 *)(DAT_003415a8 + 0xd4e4) = param_1;
}
