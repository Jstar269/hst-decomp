/* HSTMATCH module=EBOOT.BIN start=0x0017bce8 end=0x0017bd64 symbol=FUN_0017bce8 lang=c99 */
/* Hand-written reconstruction from the disassembly (constant-trip i*4 loop keeps its multiplies via pragmas); exact match verified; names and types await human review. */
#include "hst/six_slot_owner.h"
#pragma opt_strength_reduction off
#pragma opt_unroll_loops off

extern void FUN_0005743c();

/* Passes each of the six slot values to the handle of the selected item. */
void FUN_0017bce8(SixSlotOwner *self,int sel)
{
  int handle = self->items[sel]->unk68;
  if (handle != 0) {
    for (int i = 0; i < SIX_SLOT_COUNT; i++) {
      FUN_0005743c(handle, i, self->slotValues[i], 0);
    }
  }
}
