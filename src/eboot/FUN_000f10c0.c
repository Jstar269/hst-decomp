/* HSTMATCH module=EBOOT.BIN start=0x000f10c0 end=0x000f10ec symbol=FUN_000f10c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pane_shown.h"

extern void FUN_00103628();

/* Hides the pane and records it in the flag. */
void FUN_000f10c0(PaneShown54 *pane)
{
  FUN_00103628(pane,0);
  pane->shown = 0;
}
