/* HSTMATCH module=hstp_trans_main.prx start=0x0028ae34 end=0x0028ae60 symbol=FUN_0028ae34 lang=c99 */
/* Clone of src/eboot/FUN_00279b50.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

/* Counts the countdown down; sets timedOut when it reaches zero. */
void FUN_0028ae34(ModeMenu *self)
{
  int remaining;
  
  if ((0 < self->countdown) &&
     (remaining = self->countdown + -1, self->countdown = remaining, remaining < 1)) {
    self->countdown = 0;
    self->timedOut = 1;
  }
}
