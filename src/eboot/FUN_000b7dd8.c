/* HSTMATCH module=EBOOT.BIN start=0x000b7dd8 end=0x000b7e34 symbol=FUN_000b7dd8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00307388;
extern u8 DAT_003073ac;
extern void FUN_00000a00();

/* Deleting destructor: resets the vtable down the class chain, frees obj when delete_flag is positive. */
VtableObj * FUN_000b7dd8(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_00307388;
    if (obj != (VtableObj *)0x0) {
      obj->vtable = &DAT_003073ac;
    }
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
