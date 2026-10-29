/* HSTMATCH module=EBOOT.BIN start=0x000f7950 end=0x000f79b8 symbol=FUN_000f7950 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_owner.h"

extern u8 DAT_0030777c;
extern void FUN_00000a00();
extern void FUN_000f7e30();
extern u32 * FUN_00102ea4();

/* Destructor: restores the vtable, releases the owned members and the base, frees the object if delete_flag > 0. */
MemberOwner * FUN_000f7950(MemberOwner *self,short delete_flag)
{
  if (self != (MemberOwner *)0x0) {
    self->vtable = &DAT_0030777c;
    FUN_000f7e30(self,1);
    FUN_00102ea4(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
