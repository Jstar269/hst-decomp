/* HSTMATCH module=EBOOT.BIN start=0x0022c0d4 end=0x0022c0f4 symbol=FUN_0022c0d4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

bool FUN_0022c0d4(void)
{
  return (*(u16 *)(DAT_003415a8 + 0xd504) & 1) != 0;
}
