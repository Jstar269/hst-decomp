/* HSTMATCH module=EBOOT.BIN start=0x0021d3c0 end=0x0021d3f8 symbol=FUN_0021d3c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/parts_pane.h"

extern void FUN_00103628(PartsPane *, int);

/* Shows the pane and clears its animation timer. */
void FUN_0021d3c0(PartsPane *self)
{
  FUN_00103628(self,1);
  self->base.shown = 1;
  self->timer = PARTS_TIMER_OFF;
}
