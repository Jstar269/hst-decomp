/* HSTMATCH module=EBOOT.BIN start=0x00220b4c end=0x00220b7c symbol=FUN_00220b4c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/fade_pane.h"

extern void FUN_00103628();

/* Runs the toggle with 1 and sets the flag. */
void FUN_00220b4c(FadeFlagPane *self)
{
  FUN_00103628(self,1);
  self->unk54 = 1;
}
