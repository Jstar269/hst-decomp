/* HSTMATCH module=EBOOT.BIN start=0x000eec94 end=0x000eecc4 symbol=FUN_000eec94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00103628(PaneBase *, int);

/* Shows the Slot pane. */
void FUN_000eec94(PaneBase *pane)
{
  FUN_00103628(pane,1);
  pane->shown = 1;
}
