/* HSTMATCH module=hstp_trans_main.prx start=0x0024aa98 end=0x0024aac0 symbol=FUN_0024aa98 lang=c99 */
/* Clone of src/eboot/FUN_0023a900.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/hist_obj.h"

extern void FUN_0024c4d0();

/* Calls FUN_0024c4d0 on the sub-object when the mode word is positive. */
void FUN_0024aa98(HistObj *self)
{
  if (0 < self->unk3c) {
    FUN_0024c4d0(self->unk50);
  }
}
