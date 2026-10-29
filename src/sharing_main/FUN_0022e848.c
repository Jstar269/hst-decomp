/* HSTMATCH module=hstp_trans_main.prx start=0x0022e848 end=0x0022e880 symbol=FUN_0022e848 lang=c99 */
/* Clone of src/eboot/FUN_0021f2d4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/status_overlay.h"

extern void FUN_00108f54();

/* Finish the overlay: flag it done and stop the timer. */
void FUN_0022e848(StatusOverlay *self)
{
  FUN_00108f54(self,1);
  self->done = 1;
  self->timer = -1;
}
