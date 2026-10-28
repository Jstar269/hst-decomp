/* HSTMATCH module=EBOOT.BIN start=0x0022c17c end=0x0022c194 symbol=FUN_0022c17c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

u32 FUN_0022c17c(void)
{
  return *(u32 *)(DAT_003415a8 + 0xd4e0);
}
