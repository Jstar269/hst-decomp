/* HSTMATCH module=hstp_trans_main.prx start=0x0013c0f4 end=0x0013c100 symbol=FUN_0013c0f4 lang=c99 */
/* Clone of src/eboot/FUN_00130b3c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/timed_obj.h"

/* Restarts the timer with a new limit. */
void FUN_0013c0f4(TimedObj *self,u32 limit)
{
  self->elapsed = 0;
  self->limit = limit;
}
