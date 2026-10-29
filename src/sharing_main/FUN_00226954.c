/* HSTMATCH module=hstp_trans_main.prx start=0x00226954 end=0x0022697c symbol=FUN_00226954 lang=c99 */
/* Clone of src/eboot/FUN_002178ac.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Start the pair block: two target values, duration `duration`, current = first target. */
void FUN_00226954(Animator *self,short a,short b,int duration)
{
  self->pair.head.active = 1;
  self->pair.head.done = 0;
  self->pair.head.duration = duration;
  self->pair.to[0] = a;
  self->pair.to[1] = b;
  self->pair.head.counter = 0;
  self->pair.cur = self->pair.to[0];
  return;
}
