/* HSTMATCH module=hstp_trans_main.prx start=0x0022f0ac end=0x0022f0e4 symbol=FUN_0022f0ac lang=c99 */
/* Clone of src/eboot/FUN_0021fb38.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/done_timer_obj.h"

extern void FUN_00108f54();

/* Finish the object: flag it done and stop the timer. */
void FUN_0022f0ac(DoneTimerObj *self)
{
  FUN_00108f54(self,1);
  self->done = 1;
  self->timer = -1;
}
