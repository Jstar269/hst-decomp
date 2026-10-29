/* HSTMATCH module=hstp_trans_main.prx start=0x001a6738 end=0x001a6794 symbol=FUN_001a6738 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b2538;
extern void FUN_00000a00();
extern u32 * FUN_001087a8();

/* Deleting destructor: sets the class vtable, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_001a6738(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_003b2538;
    FUN_001087a8(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
