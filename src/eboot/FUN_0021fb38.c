/* HSTMATCH module=EBOOT.BIN start=0x0021fb38 end=0x0021fb70 symbol=FUN_0021fb38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/done_timer_obj.h"

extern void FUN_00103628();

/* Finish the object: flag it done and stop the timer. */
void FUN_0021fb38(DoneTimerObj *self)
{
  FUN_00103628(self,1);
  self->done = 1;
  self->timer = -1;
}
