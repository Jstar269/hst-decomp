/* HSTMATCH module=hstp_trans_main.prx start=0x002264e8 end=0x0022651c symbol=FUN_002264e8 lang=c99 */
/* Clone of src/eboot/FUN_00217440.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/animator.h"

extern u8 DAT_003b2898;

/* Construct a StepCounter: vtable set, every counter field cleared. */
StepCounter * FUN_002264e8(StepCounter *self)
{
  self->vtbl = &DAT_003b2898;
  self->unk04 = 0;
  self->unit = 0;
  self->value = 0;
  self->running = 0;
  self->finished = 0;
  self->steps = 0;
  self->base = 0;
  self->counter = 0;
  return self;
}
