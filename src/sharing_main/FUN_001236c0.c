/* HSTMATCH module=hstp_trans_main.prx start=0x001236c0 end=0x0012376c symbol=FUN_001236c0 lang=c99 */
/* Clone of src/eboot/FUN_001184ec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u8 DAT_003b12c8;
extern DequeOwner * DAT_003e47a0;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_00123a9c();
extern void FUN_001244f0();
extern int FUN_00127df0();
extern int FUN_001281a0();

/* Destructor: clears the global, releases the pointer and both containers, runs the base destructor, frees when flag > 0. */
DequeOwner * FUN_001236c0(DequeOwner *self,short flag)
{
  DequeBox *box;
  
  if (self != (DequeOwner *)0x0) {
    self->vtable = &DAT_003b12c8;
    DAT_003e47a0 = 0;
    FUN_001244f0();
    FUN_00123a9c(self);
    box = &self->deque2f8;
    if ((box != (DequeBox *)0x0) && (box != (DequeBox *)0x0)) {
      FUN_001281a0(box,0);
    }
    box = &self->deque2e0;
    if ((box != (DequeBox *)0x0) && (box != (DequeBox *)0x0)) {
      FUN_00127df0(box,0);
    }
    FUN_0001ed28(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
