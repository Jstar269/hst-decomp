/* HSTMATCH module=EBOOT.BIN start=0x00217910 end=0x0021791c symbol=FUN_00217910 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the position block's flags. */
void FUN_00217910(Animator *self)
{
  self->pos.head.active = 0;
  self->pos.head.done = 0;
}
