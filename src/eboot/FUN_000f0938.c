/* HSTMATCH module=EBOOT.BIN start=0x000f0938 end=0x000f0968 symbol=FUN_000f0938 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern void FUN_00103628();

/* Mark the ace pane shown. */
void FUN_000f0938(AcePane *self)
{
  FUN_00103628(self,1);
  self->base.shown = 1;
}
