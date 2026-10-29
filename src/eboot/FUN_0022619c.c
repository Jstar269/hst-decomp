/* HSTMATCH module=EBOOT.BIN start=0x0022619c end=0x002261f8 symbol=FUN_0022619c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309724;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor: sets the class vtable, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_0022619c(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309724;
    FUN_00102ea4(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
