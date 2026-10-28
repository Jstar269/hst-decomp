/* HSTMATCH module=EBOOT.BIN start=0x001c9e0c end=0x001c9e1c symbol=FUN_001c9e0c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034a678;
extern void FUN_00234158();

void FUN_001c9e0c(void)
{
  FUN_00234158(&DAT_0034a678,0x21);
}
