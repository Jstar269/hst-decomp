/* HSTMATCH module=EBOOT.BIN start=0x000e9904 end=0x000e9980 symbol=FUN_000e9904 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/elem_owner.h"

#define ELEM_SIZE 0x50

extern u8 DAT_0030770c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000e99d4(ElemOwner *);
extern void FUN_000e7494();

/* Destructor: delete the member, destroy the two elements, run the base destructor, and free the object when `flag` is positive. */
ElemOwner * FUN_000e9904(ElemOwner *self,short flag)
{
  if (self != (ElemOwner *)0x0) {
    self->vtable = &DAT_0030770c;
    FUN_000e99d4(self);
    FUN_00000788(self->elem,FUN_000e7494,ELEM_SIZE,OWNER_ELEM_COUNT);
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
