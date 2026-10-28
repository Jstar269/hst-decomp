/* HSTMATCH module=EBOOT.BIN start=0x0022c878 end=0x0022c890 symbol=FUN_0022c878 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

u8 FUN_0022c878(void)
{
  return *(u8 *)(DAT_003415a8 + 0xe050);
}
