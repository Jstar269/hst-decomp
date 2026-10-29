/* HSTMATCH module=EBOOT.BIN start=0x002174bc end=0x00217548 symbol=FUN_002174bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: typed object view, the limit field read into a local first and reused as the divisor, and the finished arm (counter >= limit) written first; readability pass; exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Advance the counter one tick: ease `value` along steps * unit, snapping to the end value at the limit. */
void FUN_002174bc(StepCounter *self)
{
  int count;

  self->finished = 0;
  if (self->running != 0) {
    int lim = self->limit;
    count = self->counter + 1;
    self->counter = count;
    if (count >= lim) {
      self->running = 0;
      self->value = self->base + self->unit * self->steps;
      self->steps = 0;
      self->finished = 1;
    }
    else {
      self->value = self->base + self->steps * ((self->unit * count) / lim);
    }
  }
}
