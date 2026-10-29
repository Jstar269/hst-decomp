/* HSTMATCH module=EBOOT.BIN start=0x000fb504 end=0x000fb528 symbol=FUN_000fb504 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

#define STATUS_DONE 5

/* True when there is no status object or it has reached the done state. */
bool FUN_000fb504(ModeScreen *self)
{
  bool done;
  ModeStatusObj *status;
  
  status = self->core->status;
  done = true;
  if (status != 0) {
    done = status->unkb8 == STATUS_DONE;
  }
  return done;
}
