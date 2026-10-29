/* HSTMATCH module=EBOOT.BIN start=0x002178ac end=0x002178d4 symbol=FUN_002178ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Start the pair block: two target values, duration `duration`, current = first target. */
void FUN_002178ac(Animator *self,short a,short b,int duration)
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
