/* HSTMATCH module=EBOOT.BIN start=0x000eecc4 end=0x000eecf0 symbol=FUN_000eecc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00103628(PaneBase *, int);

/* Hides the Slot pane. */
void FUN_000eecc4(PaneBase *pane)
{
  FUN_00103628(pane,0);
  pane->shown = 0;
}
