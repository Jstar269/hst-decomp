/* HSTMATCH module=EBOOT.BIN start=0x000f0968 end=0x000f0994 symbol=FUN_000f0968 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern void FUN_00103628();

/* Mark the ace pane hidden. */
void FUN_000f0968(AcePane *self)
{
  FUN_00103628(self,0);
  self->base.shown = 0;
}
