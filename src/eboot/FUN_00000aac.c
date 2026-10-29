/* HSTMATCH module=EBOOT.BIN start=0x00000aac end=0x00000b08 symbol=FUN_00000aac lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00306ee8;
extern u8 DAT_00306ed8;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_00000aac(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_00306ee8;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_00306ed8;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
