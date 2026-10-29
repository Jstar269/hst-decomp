/* HSTMATCH module=EBOOT.BIN start=0x00093c7c end=0x00093cc8 symbol=FUN_00093c7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: typed the copied argument as a four-float record; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_000944c8();

/* Copy the four-float value and hand it, with the main model, to the setter for the unkb0 area. */
void FUN_00093c7c(ModelSet *self,Float4 *value)
{
  Float4 local;
  local = *value;
  FUN_000944c8(self->unkb0,&local,self->model[MODEL_SLOT_MAIN]);
}
