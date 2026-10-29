/* HSTMATCH module=hstp_trans_main.prx start=0x00094ccc end=0x00094ce4 symbol=FUN_00094ccc lang=c99 */
/* Clone of src/eboot/FUN_00092e38.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/char_model.h"

/* Sets the flag on model item 2, if present, to 0. */
void FUN_00094ccc(CharModel *self)
{
  if (self->item[2] != 0) {
    self->item[2]->unk170 = 0;
  }
}
