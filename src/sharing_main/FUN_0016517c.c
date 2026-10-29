/* HSTMATCH module=hstp_trans_main.prx start=0x0016517c end=0x001651d8 symbol=FUN_0016517c lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b1b54;
extern u8 DAT_003b16d8;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_0016517c(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_003b1b54;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_003b16d8;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
