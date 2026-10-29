/* HSTMATCH module=EBOOT.BIN start=0x001184ec end=0x00118598 symbol=FUN_001184ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern u8 DAT_00307ffc;
extern DequeOwner * DAT_0033b460;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001188c8();
extern void FUN_0011931c();
extern int FUN_0011cc1c();
extern int FUN_0011cfcc();

/* Destructor: clears the global, releases the pointer and both containers, runs the base destructor, frees when flag > 0. */
DequeOwner * FUN_001184ec(DequeOwner *self,short flag)
{
  DequeBox *box;
  
  if (self != (DequeOwner *)0x0) {
    self->vtable = &DAT_00307ffc;
    DAT_0033b460 = 0;
    FUN_0011931c();
    FUN_001188c8(self);
    box = &self->deque2f8;
    if ((box != (DequeBox *)0x0) && (box != (DequeBox *)0x0)) {
      FUN_0011cfcc(box,0);
    }
    box = &self->deque2e0;
    if ((box != (DequeBox *)0x0) && (box != (DequeBox *)0x0)) {
      FUN_0011cc1c(box,0);
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
