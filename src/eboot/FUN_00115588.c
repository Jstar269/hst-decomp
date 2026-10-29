/* HSTMATCH module=EBOOT.BIN start=0x00115588 end=0x001155c0 symbol=FUN_00115588 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pane_mode.h"

extern void FUN_001031e8();

/* Runs the base action unless the flag is set and the count is positive. */
void FUN_00115588(PaneModeObj *self)
{
  if (((self->flags & 8) == 0) || (self->unk88 < 1)) {
    FUN_001031e8();
  }
}
