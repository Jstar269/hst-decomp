/* HSTMATCH module=hstp_trans_main.prx start=0x000ee9d8 end=0x000eea54 symbol=FUN_000ee9d8 lang=c99 */
/* Clone of src/eboot/FUN_000e9904.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/elem_owner.h"

#define ELEM_SIZE 0x50

extern u8 DAT_003b09d8;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_000eeaa8(ElemOwner *);
extern void FUN_000ec490();

/* Destructor: delete the member, destroy the two elements, run the base destructor, and free the object when `flag` is positive. */
ElemOwner * FUN_000ee9d8(ElemOwner *self,short flag)
{
  if (self != (ElemOwner *)0x0) {
    self->vtable = &DAT_003b09d8;
    FUN_000eeaa8(self);
    FUN_00000788(self->elem,FUN_000ec490,ELEM_SIZE,OWNER_ELEM_COUNT);
    FUN_0001ed28(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
