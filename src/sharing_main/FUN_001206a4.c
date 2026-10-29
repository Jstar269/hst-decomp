/* HSTMATCH module=hstp_trans_main.prx start=0x001206a4 end=0x0012071c symbol=FUN_001206a4 lang=c99 */
/* Clone of src/eboot/FUN_00115788.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0ea4;
extern void FUN_00000a00();
extern u32 * FUN_001087a8();
extern int * FUN_001212c4();

/* Destructor: destroys the member object at 0x8c, runs the base destructor, frees the object when flag > 0. */
u32 * FUN_001206a4(u32 *self,short flag)
{
  u32 *member;
  
  if (self != (u32 *)0x0) {
    member = self + 0x23;
    *self = (unsigned int)(&DAT_003b0ea4);
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_001212c4(member,0);
    }
    FUN_001087a8(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
