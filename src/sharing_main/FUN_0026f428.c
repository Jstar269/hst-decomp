/* HSTMATCH module=hstp_trans_main.prx start=0x0026f428 end=0x0026f4c0 symbol=FUN_0026f428 lang=c99 */
/* Clone of src/eboot/FUN_0025e600.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u8 DAT_003b264c;
extern u8 DAT_003b2cb8;
extern u32 DAT_003f3af4;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_001087a8();
extern void FUN_0026f328();

/* Deleting destructor of the slot pane: sets the derived vtable, clears the global, destroys the slot array, sets the base vtable and runs the base destructor, then frees the object when delete_flag > 0. */
SpawnedSlotPane * FUN_0026f428(SpawnedSlotPane *self,short delete_flag)
{
  if (self != (SpawnedSlotPane *)0x0) {
    self->vtable = &DAT_003b2cb8;
    DAT_003f3af4 = 0;
    if (self->slot != (SpawnedSlot *)0x0) {
      FUN_00000788(self->slot,FUN_0026f328,SPAWNED_SLOT_SIZE,SPAWNED_SLOT_COUNT);
    }
    if (self != (SpawnedSlotPane *)0x0) {
      self->vtable = &DAT_003b264c;
      FUN_001087a8(self,0);
    }
    if (delete_flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
