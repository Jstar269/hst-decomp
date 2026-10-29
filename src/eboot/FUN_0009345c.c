/* HSTMATCH module=EBOOT.BIN start=0x0009345c end=0x00093484 symbol=FUN_0009345c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_000550c8();

/* Forward the argument to the main model's helper (sibling of FUN_00093434). */
void FUN_0009345c(ModelSet *self,u32 *arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_000550c8(self->model[MODEL_SLOT_MAIN],arg);
  }
}
