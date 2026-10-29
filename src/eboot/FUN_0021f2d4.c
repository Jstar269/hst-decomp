/* HSTMATCH module=EBOOT.BIN start=0x0021f2d4 end=0x0021f30c symbol=FUN_0021f2d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/status_overlay.h"

extern void FUN_00103628();

/* Finish the overlay: flag it done and stop the timer. */
void FUN_0021f2d4(StatusOverlay *self)
{
  FUN_00103628(self,1);
  self->done = 1;
  self->timer = -1;
}
