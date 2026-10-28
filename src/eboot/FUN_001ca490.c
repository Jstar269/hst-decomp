/* HSTMATCH module=EBOOT.BIN start=0x001ca490 end=0x001ca4a0 symbol=FUN_001ca490 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034a678;
extern void FUN_00234158();

void FUN_001ca490(void)
{
  FUN_00234158(&DAT_0034a678,0x1f);
}
