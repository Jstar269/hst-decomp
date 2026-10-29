/* HSTMATCH module=EBOOT.BIN start=0x0009306c end=0x00093094 symbol=FUN_0009306c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/model_set.h"

extern void FUN_0005ef18();

/* Forward to the first model slot's helper when the slot is filled. */
void FUN_0009306c(ModelSet *self)
{
  if (self->model[0] != 0) {
    FUN_0005ef18(self->model[0]);
  }
}
