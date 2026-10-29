/* HSTMATCH module=EBOOT.BIN start=0x00125d74 end=0x00125dd0 symbol=FUN_00125d74 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00308018;
extern void FUN_00000a00();
extern u32 * FUN_00060e7c();

/* Deleting destructor: sets its vtable, runs the base-class teardown, frees the object when flags > 0. */
VtableObj * FUN_00125d74(VtableObj *self,short flags)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00308018;
    FUN_00060e7c(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
