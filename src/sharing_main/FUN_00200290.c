/* HSTMATCH module=hstp_trans_main.prx start=0x00200290 end=0x002002ac symbol=FUN_00200290 lang=c99 */
/* Clone of src/eboot/FUN_001f1e8c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/prize_screen.h"

/* On the first frame sets a flag byte. */
void FUN_00200290(PrizeScreen *self)
{
  if (self->unk44 == 0) {
    self->unk515 = 1;
  }
}
