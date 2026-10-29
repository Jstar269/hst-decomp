/* HSTMATCH module=EBOOT.BIN start=0x00093750 end=0x00093778 symbol=FUN_00093750 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00057b58();

/* Forward the argument to the main model's helper. */
void FUN_00093750(ModelSet *self,u32 *arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_00057b58(self->model[MODEL_SLOT_MAIN],arg);
  }
}
