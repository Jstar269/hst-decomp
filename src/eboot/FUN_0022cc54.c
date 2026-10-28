/* HSTMATCH module=EBOOT.BIN start=0x0022cc54 end=0x0022cc64 symbol=FUN_0022cc54 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415a8;

u32 FUN_0022cc54(void)
{
  return *(u32 *)(DAT_003415a8 + 0x80);
}
