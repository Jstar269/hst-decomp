/* HSTMATCH module=EBOOT.BIN start=0x0026366c end=0x002636d8 symbol=FUN_0026366c lang=c99 */
/* Clone of src/eboot/FUN_001066ac.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309380;
extern u8 DAT_00309a54;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor: switch to the base vtable, run the base destructor, free when delete_flag > 0. */
VtableObj * FUN_0026366c(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309a54;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_00309380;
      FUN_00102ea4(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
