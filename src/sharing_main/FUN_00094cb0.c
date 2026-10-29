/* HSTMATCH module=hstp_trans_main.prx start=0x00094cb0 end=0x00094ccc symbol=FUN_00094cb0 lang=c99 */
/* Clone of src/eboot/FUN_00092e1c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/char_model.h"

/* Sets the flag on model item 2, if present, to 1. */
void FUN_00094cb0(CharModel *self)
{
  if (self->item[2] != 0) {
    self->item[2]->unk170 = 1;
  }
}
