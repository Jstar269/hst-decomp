/* HSTMATCH module=EBOOT.BIN start=0x001ec1b4 end=0x001ec210 symbol=FUN_001ec1b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309480;
extern void FUN_00000a00();
extern VtableObj * FUN_00102ea4();

/* Deleting destructor: set the vtable, run the base destructor, free the object when flag > 0. */
VtableObj * FUN_001ec1b4(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309480;
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
