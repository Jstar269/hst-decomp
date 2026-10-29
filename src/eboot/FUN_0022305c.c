/* HSTMATCH module=EBOOT.BIN start=0x0022305c end=0x00223094 symbol=FUN_0022305c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/dual_entry_pane.h"

extern void FUN_00103628();

/* Shows the pane. */
void FUN_0022305c(ChildPane *pane)
{
  FUN_00103628(pane,1);
  pane->active = 1;
  pane->unk60 = -1;
}
