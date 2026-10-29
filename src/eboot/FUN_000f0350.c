/* HSTMATCH module=EBOOT.BIN start=0x000f0350 end=0x000f0384 symbol=FUN_000f0350 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/ingame_panes.h"

extern void FUN_00103628();

/* Hide the fade-cycle pane with its fade level at one. */
void FUN_000f0350(FadeCyclePane *self)
{
  FUN_00103628(self,0);
  self->base.shown = 0;
  self->scale = 1.0f;
}
