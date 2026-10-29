/* HSTMATCH module=EBOOT.BIN start=0x00093c08 end=0x00093c30 symbol=FUN_00093c08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_00059100();

/* Forward the argument to the main model's helper (sibling of FUN_00093be0). */
void FUN_00093c08(ModelSet *self,int arg)
{
  if (self->model[MODEL_SLOT_MAIN] != 0) {
    FUN_00059100(self->model[MODEL_SLOT_MAIN],arg);
  }
}
