/* HSTMATCH module=EBOOT.BIN start=0x002260e0 end=0x00226118 symbol=FUN_002260e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_pane.h"

extern void FUN_00103628();

/* Marks the screen's pane as shown. */
void FUN_002260e0(SlotPaneScreen *screen)
{
  PaneSlotObj *pane;
  
  pane = screen->ctx->pane;
  FUN_00103628(pane,1);
  pane->shown = 1;
}
