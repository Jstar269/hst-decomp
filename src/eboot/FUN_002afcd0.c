/* HSTMATCH module=EBOOT.BIN start=0x002afcd0 end=0x002afce0 symbol=FUN_002afcd0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034b5d8;

u8 FUN_002afcd0(void)
{
  return *(u8 *)(DAT_0034b5d8 + 0x168);
}
