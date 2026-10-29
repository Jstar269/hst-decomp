/* HSTMATCH module=EBOOT.BIN start=0x000e74d4 end=0x000e74e4 symbol=FUN_000e74d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00022570();

/* Forwards its arguments with the last two swapped. */
void FUN_000e74d4(u32 self,u32 first,u32 second)
{
  FUN_00022570(self,second,first);
}
