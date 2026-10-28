/* HSTMATCH module=EBOOT.BIN start=0x00234758 end=0x002347c4 symbol=FUN_00234758 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/holder.h"

extern u8 DAT_003098a4;
extern void FUN_00000a00();
extern int * FUN_00165840();

/* Deleting destructor of the base holder. */
HolderBase * FUN_00234758(HolderBase *self,short flags)
{
  u32 *member;
  
  if (self != (HolderBase *)0x0) {
    member = self->member08;
    self->vptr = (void *)(&DAT_003098a4);
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_00165840(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
