/* HSTMATCH module=hstp_trans_main.prx start=0x00226630 end=0x0022664c symbol=FUN_00226630 lang=c99 */
/* Clone of src/eboot/FUN_00217588.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Stop the counter and set its value to -steps * unit. */
void FUN_00226630(StepCounter *self,int steps)
{
  self->running = 0;
  self->value = -steps * self->unit;
}
