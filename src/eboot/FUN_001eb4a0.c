/* HSTMATCH module=EBOOT.BIN start=0x001eb4a0 end=0x001eb4fc symbol=FUN_001eb4a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003094a0;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor: sets the vtable, runs the base destructor, frees obj when delete_flag is positive. */
VtableObj * FUN_001eb4a0(VtableObj *obj,short delete_flag)
{
  if (obj != (VtableObj *)0x0) {
    obj->vtable = &DAT_003094a0;
    FUN_00102ea4(obj,0);
    if (0 < delete_flag) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
