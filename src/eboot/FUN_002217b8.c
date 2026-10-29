/* HSTMATCH module=EBOOT.BIN start=0x002217b8 end=0x002217f0 symbol=FUN_002217b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lay_pane.h"

extern void FUN_00103628();

/* End of the animation: base state 1, flag raised, timer back to idle. */
void FUN_002217b8(PaneB *self)
{
  FUN_00103628(self,1);
  self->unk54 = 1;
  self->timer = PANE_TIMER_IDLE;
}
