/* HSTMATCH module=EBOOT.BIN start=0x0022c860 end=0x0022c878 symbol=FUN_0022c860 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

u8 FUN_0022c860(void)
{
  return *(u8 *)(DAT_003415a8 + 0xe04f);
}
