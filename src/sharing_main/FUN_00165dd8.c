/* HSTMATCH module=hstp_trans_main.prx start=0x00165dd8 end=0x00165e34 symbol=FUN_00165dd8 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b2050;
extern u8 DAT_003b16d8;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_00165dd8(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_003b2050;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_003b16d8;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
