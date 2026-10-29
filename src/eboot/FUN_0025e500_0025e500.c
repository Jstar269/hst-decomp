/* HSTMATCH module=EBOOT.BIN start=0x0025e500 end=0x0025e568 symbol=FUN_0025e500 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: modeled the resource pointer at +0x20 as a direct field store; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u8 DAT_0030779c;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

/* Deleting destructor of a slot: resets the embedded object's vtable and runs its base destructor, then frees the slot when delete_flag > 0. */
SpawnedSlot * FUN_0025e500(SpawnedSlot *slot,short delete_flag)
{
  if (slot != 0) {
    if (&slot->obj != 0) {
      slot->obj.vtable = &DAT_0030779c;
      FUN_00100b24(&slot->obj,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(slot);
    }
  }
  return slot;
}
