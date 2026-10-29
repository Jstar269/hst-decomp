/* HSTMATCH module=EBOOT.BIN start=0x00220370 end=0x0022039c symbol=FUN_00220370 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/fade_pane.h"

extern void FUN_00103628();

/* Starts the fade: runs the toggle with 0 and clears the flag. */
void FUN_00220370(FadePane *self)
{
  FUN_00103628(self,0);
  self->unk54 = 0;
}
