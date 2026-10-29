/* HSTMATCH module=EBOOT.BIN start=0x00223de0 end=0x00223e18 symbol=FUN_00223de0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern void FUN_000ffb3c();
extern void FUN_00103628();

/* Clears the shown flag and calls the layer helper with 1. */
void FUN_00223de0(DualEntryPane *pane)
{
  FUN_00103628(pane,0);
  pane->base.shown = 0;
  FUN_000ffb3c(pane->layer,1);
}
