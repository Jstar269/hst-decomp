/* HSTMATCH module=hstp_trans_main.prx start=0x000d2984 end=0x000d29e0 symbol=FUN_000d2984 lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b07c4;
extern void FUN_00000a00();
extern u32 * FUN_00057904();

/* Deleting destructor: sets the class vtable, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_000d2984(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_003b07c4;
    FUN_00057904(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
