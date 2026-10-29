/* HSTMATCH module=hstp_trans_main.prx start=0x00100be8 end=0x00100c0c symbol=FUN_00100be8 lang=c99 */
/* Clone of src/eboot/FUN_000fb4ac.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

/* Store a byte in the core's first target, if there is one. */
void FUN_00100be8(ModeScreen *self,u8 value)
{
  ModeTarget *target;
  
  if ((self->core != 0) &&
     (target = self->core->targetA, target != 0)) {
    target->unk870 = value;
  }
}
