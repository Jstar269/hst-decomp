/* HSTMATCH module=hstp_trans_main.prx start=0x000fd044 end=0x000fd0ac symbol=FUN_000fd044 lang=c99 */
/* Clone of src/eboot/FUN_000f7950.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_owner.h"

extern u8 DAT_003b0a48;
extern void FUN_00000a00();
extern void FUN_000fd524();
extern u32 * FUN_001087a8();

/* Destructor: restores the vtable, releases the owned members and the base, frees the object if delete_flag > 0. */
MemberOwner * FUN_000fd044(MemberOwner *self,short delete_flag)
{
  if (self != (MemberOwner *)0x0) {
    self->vtable = &DAT_003b0a48;
    FUN_000fd524(self,1);
    FUN_001087a8(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
