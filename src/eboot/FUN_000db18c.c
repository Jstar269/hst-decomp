/* HSTMATCH module=EBOOT.BIN start=0x000db18c end=0x000db1c4 symbol=FUN_000db18c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();

/* Free the buffer of a record when its owns-buffer bit (bit 0 of the first word) is set. */
void FUN_000db18c(u32 unused,u32 *record)
{
  if (((record != (u32 *)0x0) && (record != (u32 *)0x0)) && ((*record & 1) != 0)) {
    FUN_00000a00(record[2]);
  }
}
