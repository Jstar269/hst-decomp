/* HSTMATCH module=EBOOT.BIN start=0x0022c15c end=0x0022c17c symbol=FUN_0022c15c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

bool FUN_0022c15c(void)
{
  return (*(u16 *)(DAT_003415a8 + 0xd504) & 2) != 0;
}
