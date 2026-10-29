/* HSTMATCH module=EBOOT.BIN start=0x00217588 end=0x002175a4 symbol=FUN_00217588 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/animator.h"

/* Stop the counter and set its value to -steps * unit. */
void FUN_00217588(StepCounter *self,int steps)
{
  self->running = 0;
  self->value = -steps * self->unit;
}
