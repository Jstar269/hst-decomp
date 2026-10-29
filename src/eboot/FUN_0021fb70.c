/* HSTMATCH module=EBOOT.BIN start=0x0021fb70 end=0x0021fb9c symbol=FUN_0021fb70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/done_timer_obj.h"

extern void FUN_00103628();

/* Start the object: clear the done flag. */
void FUN_0021fb70(DoneTimerObj *self)
{
  FUN_00103628(self,0);
  self->done = 0;
}
