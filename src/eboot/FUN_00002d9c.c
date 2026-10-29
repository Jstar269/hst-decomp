/* HSTMATCH module=EBOOT.BIN start=0x00002d9c end=0x00002df8 symbol=FUN_00002d9c lang=c99 */
/* Clone of src/eboot/FUN_0008b1e8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00306f1c;
extern void FUN_00000a00();
extern u32 * FUN_00002c98();

/* Deleting destructor: sets the class vtable, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_00002d9c(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00306f1c;
    FUN_00002c98(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
