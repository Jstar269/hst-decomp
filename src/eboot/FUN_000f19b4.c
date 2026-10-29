/* HSTMATCH module=EBOOT.BIN start=0x000f19b4 end=0x000f19e4 symbol=FUN_000f19b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pane_shown.h"

extern void FUN_00103628();

/* Shows the pane and records it in the flag. */
void FUN_000f19b4(PaneShown78 *pane)
{
  FUN_00103628(pane,1);
  pane->shown = 1;
}
