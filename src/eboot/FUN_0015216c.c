/* HSTMATCH module=EBOOT.BIN start=0x0015216c end=0x001521c8 symbol=FUN_0015216c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003083cc;
extern u8 DAT_00308c3c;
extern void FUN_00000a00();

/* Destructor: resets the vtable pointer to the base class, then frees the object when flags > 0. */
VtableObj * FUN_0015216c(VtableObj *self,short flags)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00308c3c;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
