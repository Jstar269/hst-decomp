/* HSTMATCH module=EBOOT.BIN start=0x002217f0 end=0x0022181c symbol=FUN_002217f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/lay_pane.h"

extern void FUN_00103628();

/* Counterpart of FUN_002217b8: clear the base state and the flag. */
void FUN_002217f0(PaneB *self)
{
  FUN_00103628(self,0);
  self->unk54 = 0;
}
