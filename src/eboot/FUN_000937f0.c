/* HSTMATCH module=EBOOT.BIN start=0x000937f0 end=0x00093818 symbol=FUN_000937f0 lang=c99 */
/* Clone of src/eboot/FUN_00093434.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00058f38();

/* Forward the argument to the main model's helper. */
void FUN_000937f0(ModelSet *self,u32 *arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_00058f38(self->model[MODEL_SLOT_MAIN],arg);
  }
}
