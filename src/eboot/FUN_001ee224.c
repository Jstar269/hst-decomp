/* HSTMATCH module=EBOOT.BIN start=0x001ee224 end=0x001ee234 symbol=FUN_001ee224 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386b0;
extern u32 FUN_001ef2e0();

void FUN_001ee224(void)
{
  FUN_001ef2e0(*(u32 *)(DAT_003386b0 + 0xa0));
}
