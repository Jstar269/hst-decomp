/* HSTMATCH module=EBOOT.BIN start=0x001fbb5c end=0x001fbbb8 symbol=FUN_001fbb5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309590;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Destructor: sets the vtable, runs the base-class destructor body, frees the object when flag > 0. */
VtableObj * FUN_001fbb5c(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309590;
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
