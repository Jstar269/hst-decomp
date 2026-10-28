/* HSTMATCH module=hstp_trans_main.prx start=0x0024492c end=0x002449c4 symbol=FUN_0024492c lang=c99 */
/* Clone of src/eboot/FUN_00234800.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/holder.h"

extern u8 DAT_003b2b64;
extern u8 DAT_003b2b70;
extern void FUN_00000a00();
extern int * FUN_00171a30();
extern int * FUN_0024714c();

/* Deleting destructor of the derived holder: members, then base members, then free when flags > 0. */
HolderDerived * FUN_0024492c(HolderDerived *self,short flags)
{
  u32 *member;
  
  if (self != (HolderDerived *)0x0) {
    member = self->member14;
    self->base.vptr = (void *)(&DAT_003b2b64);
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_0024714c(member,0);
    }
    if (self != (HolderDerived *)0x0) {
      member = self->base.member08;
      self->base.vptr = (void *)(&DAT_003b2b70);
      if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
        FUN_00171a30(member,0);
      }
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
