/* HSTMATCH module=EBOOT.BIN start=0x001cd55c end=0x001cd584 symbol=FUN_001cd55c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/flow_state.h"

extern void FUN_0027bf24();

/* Release the owner's resource, if any. */
void FUN_001cd55c(FlowOwner *self)
{
  if (self->res != 0) {
    FUN_0027bf24(self->res->unk3c);
  }
}
