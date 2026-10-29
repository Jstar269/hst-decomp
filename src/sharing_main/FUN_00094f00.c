/* HSTMATCH module=hstp_trans_main.prx start=0x00094f00 end=0x00094f28 symbol=FUN_00094f00 lang=c99 */
/* Clone of src/eboot/FUN_0009306c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_0005fd08();

/* Forward to the first model slot's helper when the slot is filled. */
void FUN_00094f00(ModelSet *self)
{
  if (self->model[0] != 0) {
    FUN_0005fd08(self->model[0]);
  }
}
