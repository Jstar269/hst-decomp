/* HSTMATCH module=hstp_trans_main.prx start=0x001204a4 end=0x001204dc symbol=FUN_001204a4 lang=c99 */
/* Clone of src/eboot/FUN_00115588.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pane_mode.h"

extern void FUN_00108aec();

/* Runs the base action unless the flag is set and the count is positive. */
void FUN_001204a4(PaneModeObj *self)
{
  if (((self->flags & 8) == 0) || (self->unk88 < 1)) {
    FUN_00108aec();
  }
}
