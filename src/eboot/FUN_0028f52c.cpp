/* HSTMATCH module=EBOOT.BIN start=0x0028f52c end=0x0028f5bc symbol=FUN_0028f52c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309d98;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00254114(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Object with an owned polymorphic member at +0x3c. */
struct OwnerObj {
  const void *vtable;       /* 0x00 */
  char pad4[0x3c - 4];
  VC_0 *owned;              /* 0x3c deleted by the destructor */
};

/* Deleting destructor: sets the vtable, deletes the owned member, runs the base destructors, frees the object when delete_flag > 0. */
extern "C" OwnerObj * FUN_0028f52c(OwnerObj *self,short delete_flag)
{
  VC_0 *member;
  
  if (self != (OwnerObj *)0x0) {
    self->vtable = &DAT_00309d98;
    member = self->owned;
    if (member != (VC_0 *)0x0) {
      delete member;
      self->owned = 0;
    }
    FUN_00254114();
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
