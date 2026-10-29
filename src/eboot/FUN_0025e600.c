/* HSTMATCH module=EBOOT.BIN start=0x0025e600 end=0x0025e698 symbol=FUN_0025e600 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag t0) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u8 DAT_00309380;
extern u8 DAT_003099d0;
extern u32 DAT_0034a7c4;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();
extern void FUN_0025e500();

/* Deleting destructor of the slot pane: sets the derived vtable, clears the global, destroys the slot array, sets the base vtable and runs the base destructor, then frees the object when delete_flag > 0. */
SpawnedSlotPane * FUN_0025e600(SpawnedSlotPane *self,short delete_flag)
{
  if (self != (SpawnedSlotPane *)0x0) {
    self->vtable = &DAT_003099d0;
    DAT_0034a7c4 = 0;
    if (self->slot != (SpawnedSlot *)0x0) {
      FUN_00000788(self->slot,FUN_0025e500,SPAWNED_SLOT_SIZE,SPAWNED_SLOT_COUNT);
    }
    if (self != (SpawnedSlotPane *)0x0) {
      self->vtable = &DAT_00309380;
      FUN_00102ea4(self,0);
    }
    if (delete_flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
