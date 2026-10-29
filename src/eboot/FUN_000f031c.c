/* HSTMATCH module=EBOOT.BIN start=0x000f031c end=0x000f0350 symbol=FUN_000f031c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern void FUN_00103628();

/* Show the fade-cycle pane with its fade level at zero. */
void FUN_000f031c(FadeCyclePane *self)
{
  FUN_00103628(self,1);
  self->base.shown = 1;
  self->scale = 0.0f;
}
