/* HSTMATCH module=EBOOT.BIN start=0x00223db0 end=0x00223de0 symbol=FUN_00223db0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern void FUN_00103628();

/* Shows the pane. */
void FUN_00223db0(DualEntryPane *pane)
{
  FUN_00103628(pane,1);
  pane->base.shown = 1;
}
