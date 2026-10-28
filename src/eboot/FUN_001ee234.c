/* HSTMATCH module=EBOOT.BIN start=0x001ee234 end=0x001ee248 symbol=FUN_001ee234 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;

int FUN_001ee234(void)
{
  return *(int *)(DAT_003386b0 + 0xa0) + 0x10cc;
}
