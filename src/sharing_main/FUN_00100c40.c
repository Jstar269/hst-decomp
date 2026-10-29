/* HSTMATCH module=hstp_trans_main.prx start=0x00100c40 end=0x00100c64 symbol=FUN_00100c40 lang=c99 */
/* Clone of src/eboot/FUN_000fb504.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

#define STATUS_DONE 5

/* True when there is no status object or it has reached the done state. */
bool FUN_00100c40(ModeScreen *self)
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
