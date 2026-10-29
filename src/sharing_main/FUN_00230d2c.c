/* HSTMATCH module=hstp_trans_main.prx start=0x00230d2c end=0x00230d64 symbol=FUN_00230d2c lang=c99 */
/* Clone of src/eboot/FUN_0021f2d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/status_overlay.h"

extern void FUN_00108f54();

/* Finish the overlay: flag it done and stop the timer. */
void FUN_00230d2c(StatusOverlay *self)
{
  FUN_00108f54(self,1);
  self->done = 1;
  self->timer = -1;
}
