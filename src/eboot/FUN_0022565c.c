/* HSTMATCH module=EBOOT.BIN start=0x0022565c end=0x002256b8 symbol=FUN_0022565c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003097e4;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor: reset the vtable, run the base destructor, free the object when asked. */
VtableObj * FUN_0022565c(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_003097e4;
    FUN_00102ea4(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
