/* HSTMATCH module=EBOOT.BIN start=0x0019d30c end=0x0019d368 symbol=FUN_0019d30c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309250;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();

/* Deleting destructor: reset the vtable, run the base destructor, free self when flags > 0. */
VtableObj * FUN_0019d30c(VtableObj *self,short flags)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309250;
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
