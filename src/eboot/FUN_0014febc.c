/* HSTMATCH module=EBOOT.BIN start=0x0014febc end=0x0014ff18 symbol=FUN_0014febc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003083cc;
extern u8 DAT_00308fcc;
extern void FUN_00000a00();

/* Deleting destructor: steps the vtable down to the base class and frees the object when flag > 0. */
VtableObj * FUN_0014febc(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00308fcc;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
