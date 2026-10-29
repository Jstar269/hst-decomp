/* HSTMATCH module=hstp_trans_main.prx start=0x001006d8 end=0x001006f4 symbol=FUN_001006d8 lang=c99 */
/* Clone of src/eboot/FUN_000faf9c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/hud_scene.h"

/* Count the countdown down towards zero. */
void FUN_001006d8(HudScene *self)
{
  if (0 < self->countdown) {
    self->countdown = self->countdown + -1;
  }
}
