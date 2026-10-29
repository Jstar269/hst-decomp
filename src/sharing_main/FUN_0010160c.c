/* HSTMATCH module=hstp_trans_main.prx start=0x0010160c end=0x00101620 symbol=FUN_0010160c lang=c99 */
/* Clone of src/eboot/FUN_000fbed0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

/* Set the active flag; activating also resets the timer. */
void FUN_0010160c(ModeScreen *self,int active)
{
  self->active = (char)active;
  if (active != 0) {
    self->timer = 0;
  }
}
