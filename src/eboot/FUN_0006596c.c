/* HSTMATCH module=EBOOT.BIN start=0x0006596c end=0x000659c8 symbol=FUN_0006596c lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003070dc;
extern u8 DAT_00307148;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_0006596c(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_003070dc;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_00307148;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
