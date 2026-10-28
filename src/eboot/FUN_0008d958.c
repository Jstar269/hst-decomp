/* HSTMATCH module=EBOOT.BIN start=0x0008d958 end=0x0008d964 symbol=FUN_0008d958 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002d2568;

void FUN_0008d958(u32 param_1)
{
  DAT_002d2568 = param_1;
}
