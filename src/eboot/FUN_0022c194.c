/* HSTMATCH module=EBOOT.BIN start=0x0022c194 end=0x0022c1ac symbol=FUN_0022c194 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003415a8;

u32 FUN_0022c194(void)
{
  return *(u32 *)(DAT_003415a8 + 0xd4d4);
}
