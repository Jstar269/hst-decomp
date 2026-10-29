/* HSTMATCH module=EBOOT.BIN start=0x00217928 end=0x00217934 symbol=FUN_00217928 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the colour block's flags. */
void FUN_00217928(Animator *self)
{
  self->color.head.active = 0;
  self->color.head.done = 0;
}
