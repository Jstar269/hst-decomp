/* HSTMATCH module=EBOOT.BIN start=0x00217440 end=0x00217474 symbol=FUN_00217440 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

extern u8 DAT_003095cc;

/* Construct a StepCounter: vtable set, every counter field cleared. */
StepCounter * FUN_00217440(StepCounter *self)
{
  self->vtbl = &DAT_003095cc;
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
