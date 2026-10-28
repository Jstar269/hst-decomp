/* HSTMATCH module=EBOOT.BIN start=0x001ff5a4 end=0x001ff5d0 symbol=FUN_001ff5a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003386c8;
extern void FUN_00281090();

void FUN_001ff5a4(void)
{
  if (DAT_003386c8 != 0) {
    FUN_00281090(*(u32 *)(DAT_003386c8 + 0x40));
  }
}
