/* HSTMATCH module=hstp_trans_main.prx start=0x0015af84 end=0x0015afe0 symbol=FUN_0015af84 lang=c99 */
/* Clone of src/eboot/FUN_000b7dd8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b16bc;
extern u8 DAT_003b172c;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_0015af84(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_003b16bc;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_003b172c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
