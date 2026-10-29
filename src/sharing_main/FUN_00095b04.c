/* HSTMATCH module=hstp_trans_main.prx start=0x00095b04 end=0x00095b2c symbol=FUN_00095b04 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059d68();

/* Forward the argument to the main model's helper. */
void FUN_00095b04(ModelSet *self,u32 *arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_00059d68(self->model[MODEL_SLOT_MAIN],arg);
  }
}
