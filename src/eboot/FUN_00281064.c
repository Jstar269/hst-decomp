/* HSTMATCH module=EBOOT.BIN start=0x00281064 end=0x00281090 symbol=FUN_00281064 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00338ac4;
extern void FUN_000bd704();

void FUN_00281064(void)
{
  if (DAT_00338ac4 != 0) {
    FUN_000bd704(DAT_00338ac4,0xffffffff);
  }
}
