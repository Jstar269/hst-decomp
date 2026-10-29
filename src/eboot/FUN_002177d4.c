/* HSTMATCH module=EBOOT.BIN start=0x002177d4 end=0x0021780c symbol=FUN_002177d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Start the position block: four target values, duration `duration`, current = first two targets. */
void FUN_002177d4(Animator *self,short a,short b,short c,short d,int duration)
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
