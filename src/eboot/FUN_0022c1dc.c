/* HSTMATCH module=EBOOT.BIN start=0x0022c1dc end=0x0022c1f4 symbol=FUN_0022c1dc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

u8 FUN_0022c1dc(void)
{
  return *(u8 *)(DAT_003415a8 + 0xe04c);
}
