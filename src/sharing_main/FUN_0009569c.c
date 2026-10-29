/* HSTMATCH module=hstp_trans_main.prx start=0x0009569c end=0x000956c4 symbol=FUN_0009569c lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059ac0();

/* Forward the argument to the main model's helper. */
void FUN_0009569c(ModelSet *self,u32 *arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_00059ac0(self->model[MODEL_SLOT_MAIN],arg);
  }
}
