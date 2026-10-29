/* HSTMATCH module=EBOOT.BIN start=0x00130b3c end=0x00130b48 symbol=FUN_00130b3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/timed_obj.h"

/* Restarts the timer with a new limit. */
void FUN_00130b3c(TimedObj *self,u32 limit)
{
  self->elapsed = 0;
  self->limit = limit;
}
