/* HSTMATCH module=EBOOT.BIN start=0x0014ba1c end=0x0014ba78 symbol=FUN_0014ba1c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030840c;
extern u8 DAT_00308428;
extern void FUN_00000a00();

/* Deleting destructor: switch to the base vtable and free when delete_flag > 0. */
VtableObj * FUN_0014ba1c(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00308428;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_0030840c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
