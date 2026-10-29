/* HSTMATCH module=hstp_trans_main.prx start=0x0020aa8c end=0x0020aaf4 symbol=FUN_0020aa8c lang=c99 */
/* Clone of src/eboot/FUN_000f7950.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_owner.h"

extern u8 DAT_003b2800;
extern void FUN_00000a00();
extern void FUN_0020ac00();
extern u32 * FUN_0001ed28();

/* Destructor: restores the vtable, releases the owned members and the base, frees the object if delete_flag > 0. */
MemberOwner * FUN_0020aa8c(MemberOwner *self,short delete_flag)
{
  if (self != (MemberOwner *)0x0) {
    self->vtable = &DAT_003b2800;
    FUN_0020ac00(self,1);
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
