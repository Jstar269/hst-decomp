/* HSTMATCH module=hstp_trans_main.prx start=0x0028ae08 end=0x0028ae18 symbol=FUN_0028ae08 lang=c99 */
/* Clone of src/eboot/FUN_00279b24.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

#define COUNTDOWN_START 0x1e

/* Starts the countdown that FUN_00279b50 ticks. */
void FUN_0028ae08(ModeMenu *self)
{
  self->countdown = COUNTDOWN_START;
  self->timedOut = 0;
}
