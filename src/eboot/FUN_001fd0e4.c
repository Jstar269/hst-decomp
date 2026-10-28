/* HSTMATCH module=EBOOT.BIN start=0x001fd0e4 end=0x001fd110 symbol=FUN_001fd0e4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a13c;
extern void FUN_001fdb80();

void FUN_001fd0e4(void)
{
  if (DAT_0034a13c != 0) {
    FUN_001fdb80(DAT_0034a13c);
  }
}
