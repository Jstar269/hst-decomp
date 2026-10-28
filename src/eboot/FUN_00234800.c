/* HSTMATCH module=EBOOT.BIN start=0x00234800 end=0x00234898 symbol=FUN_00234800 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/holder.h"

extern u8 DAT_00309898;
extern u8 DAT_003098a4;
extern void FUN_00000a00();
extern int * FUN_00165840();
extern int * FUN_00236fe8();

/* Deleting destructor of the derived holder: members, then base members, then free when flags > 0. */
HolderDerived * FUN_00234800(HolderDerived *self,short flags)
{
  u32 *member;
  
  if (self != (HolderDerived *)0x0) {
    member = self->member14;
    self->base.vptr = (void *)(&DAT_00309898);
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_00236fe8(member,0);
    }
    if (self != (HolderDerived *)0x0) {
      member = self->base.member08;
      self->base.vptr = (void *)(&DAT_003098a4);
      if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
        FUN_00165840(member,0);
      }
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
