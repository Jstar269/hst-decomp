/* HSTMATCH module=hstp_trans_main.prx start=0x0012342c end=0x00123480 symbol=FUN_0012342c lang=c99 */
/* Clone of src/eboot/FUN_00118258.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u8 DAT_003b12c8;
extern DequeOwner * DAT_003e47a0;
extern u32 * FUN_0001ec44();
extern u32 FUN_00123530();
extern u32 FUN_001235f8();
extern void FUN_0012376c();

/* Constructor: builds the two containers and registers the object in the global DAT_003e47a0. */
DequeOwner * FUN_0012342c(DequeOwner *self)
{
  FUN_0001ec44();
  self->vtable = &DAT_003b12c8;
  FUN_001235f8(&self->deque2e0);
  FUN_00123530(&self->deque2f8);
  DAT_003e47a0 = self;
  FUN_0012376c(self);
  return self;
}
