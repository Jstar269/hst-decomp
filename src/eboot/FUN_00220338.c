/* HSTMATCH module=EBOOT.BIN start=0x00220338 end=0x00220370 symbol=FUN_00220338 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/fade_pane.h"

extern void FUN_00103628();

/* Finishes the fade: runs the toggle with 1, sets the flag and returns the timer to idle. */
void FUN_00220338(FadePane *self)
{
  FUN_00103628(self,1);
  self->unk54 = 1;
  self->timer = FADE_IDLE;
}
