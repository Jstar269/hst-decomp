/* HSTMATCH module=hstp_trans_main.prx start=0x0022da40 end=0x0022da94 symbol=FUN_0022da40 lang=c99 */
/* Clone of src/eboot/FUN_0021e4cc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/digit_panel.h"

extern int FUN_002bf370();

/* Store `flag` in unk1e4, set unk208, and clear unk208 again when `check` is set and unk200 >= the count FUN_002bf370 reports for unk170. */
void FUN_0022da40(DigitPanel *self,u8 flag,int check)
{
  int limit;
  int index;
  
  self->unk1e4 = flag;
  self->unk208 = 1;
  if ((check != 0) &&
     (index = self->unk200, limit = FUN_002bf370(self->unk170),
     index >= limit)) {
    self->unk208 = 0;
  }
}
