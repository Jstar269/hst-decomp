/* HSTMATCH module=hstp_trans_main.prx start=0x000bb0c8 end=0x000bb124 symbol=FUN_000bb0c8 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b0654;
extern u8 DAT_003b0678;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_000bb0c8(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_003b0654;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_003b0678;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
