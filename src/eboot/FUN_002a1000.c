/* HSTMATCH module=EBOOT.BIN start=0x002a1000 end=0x002a105c symbol=FUN_002a1000 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309ec0;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Destructor: sets its vtable, runs the base-class teardown, then frees the object when flags > 0. */
VtableObj * FUN_002a1000(VtableObj *self,short flags)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309ec0;
    FUN_00102ea4(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
