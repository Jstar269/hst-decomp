/* HSTMATCH module=hstp_trans_main.prx start=0x00244858 end=0x002448c4 symbol=FUN_00244858 lang=c99 */
/* Clone of src/eboot/FUN_00234758.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/holder.h"

extern u8 DAT_003b2b70;
extern void FUN_00000a00();
extern int * FUN_00171a30();

/* Deleting destructor of the base holder. */
HolderBase * FUN_00244858(HolderBase *self,short flags)
{
  u32 *member;
  
  if (self != (HolderBase *)0x0) {
    member = self->member08;
    self->vptr = (void *)(&DAT_003b2b70);
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_00171a30(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
