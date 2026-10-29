/* HSTMATCH module=EBOOT.BIN start=0x0021791c end=0x00217928 symbol=FUN_0021791c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the flags of the block at +0x3c. */
void FUN_0021791c(Animator *self)
{
  self->block3c.active = 0;
  self->block3c.done = 0;
}
