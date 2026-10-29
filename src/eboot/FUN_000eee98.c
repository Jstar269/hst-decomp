/* HSTMATCH module=EBOOT.BIN start=0x000eee98 end=0x000eeec8 symbol=FUN_000eee98 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00103628(PaneBase *, int);

/* Shows the Small pane. */
void FUN_000eee98(PaneBase *pane)
{
  FUN_00103628(pane,1);
  pane->shown = 1;
}
