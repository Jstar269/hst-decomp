/* HSTMATCH module=EBOOT.BIN start=0x001ee200 end=0x001ee210 symbol=FUN_001ee200 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;

u32 FUN_001ee200(void)
{
  return *(u32 *)(DAT_003386b0 + 0xa0);
}
