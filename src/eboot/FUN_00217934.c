/* HSTMATCH module=EBOOT.BIN start=0x00217934 end=0x00217940 symbol=FUN_00217934 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Clear the pair block's flags. */
void FUN_00217934(Animator *self)
{
  self->pair.head.active = 0;
  self->pair.head.done = 0;
}
