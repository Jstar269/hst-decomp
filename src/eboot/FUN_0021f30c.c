/* HSTMATCH module=EBOOT.BIN start=0x0021f30c end=0x0021f338 symbol=FUN_0021f30c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/status_overlay.h"

extern void FUN_00103628();

/* Start the overlay: clear the done flag. */
void FUN_0021f30c(StatusOverlay *self)
{
  FUN_00103628(self,0);
  self->done = 0;
}
