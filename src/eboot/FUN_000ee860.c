/* HSTMATCH module=EBOOT.BIN start=0x000ee860 end=0x000ee890 symbol=FUN_000ee860 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_00103628(PaneBase *, int);

/* Shows the replay pane. */
void FUN_000ee860(PaneBase *pane)
{
  FUN_00103628(pane,1);
  pane->shown = 1;
}
