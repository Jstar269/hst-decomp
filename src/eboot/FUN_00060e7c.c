/* HSTMATCH module=EBOOT.BIN start=0x00060e7c end=0x00060ed8 symbol=FUN_00060e7c lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030707c;
extern u8 DAT_0030708c;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_00060e7c(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_0030707c;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_0030708c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
