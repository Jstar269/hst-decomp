/* HSTMATCH module=hstp_trans_main.prx start=0x0022687c end=0x002268b4 symbol=FUN_0022687c lang=c99 */
/* Clone of src/eboot/FUN_002177d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Start the position block: four target values, duration `duration`, current = first two targets. */
void FUN_0022687c(Animator *self,short a,short b,short c,short d,int duration)
{
  self->pos.head.active = 1;
  self->pos.head.done = 0;
  self->pos.head.duration = duration;
  self->pos.to[0] = a;
  self->pos.to[1] = b;
  self->pos.to[2] = c;
  self->pos.to[3] = d;
  self->pos.head.counter = 0;
  self->pos.cur[0] = self->pos.to[0];
  self->pos.cur[1] = self->pos.to[1];
  return;
}
