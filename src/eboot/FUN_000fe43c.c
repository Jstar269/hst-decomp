/* HSTMATCH module=EBOOT.BIN start=0x000fe43c end=0x000fe448 symbol=FUN_000fe43c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002d88bc;

void FUN_000fe43c(u32 param_1)
{
  DAT_002d88bc = param_1;
}
