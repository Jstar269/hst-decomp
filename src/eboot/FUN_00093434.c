/* HSTMATCH module=EBOOT.BIN start=0x00093434 end=0x0009345c symbol=FUN_00093434 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00055044();

/* Forward the argument to the main model's helper. */
void FUN_00093434(ModelSet *self,u32 *arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_00055044(self->model[MODEL_SLOT_MAIN],arg);
  }
}
