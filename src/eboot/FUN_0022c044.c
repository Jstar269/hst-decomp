/* HSTMATCH module=EBOOT.BIN start=0x0022c044 end=0x0022c05c symbol=FUN_0022c044 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

int FUN_0022c044(void)
{
  return (int)*(short *)(DAT_003415a8 + 0xd4e4);
}
