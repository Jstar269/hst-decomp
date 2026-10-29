/* HSTMATCH module=EBOOT.BIN start=0x00150ed0 end=0x00150f2c symbol=FUN_00150ed0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003083cc;
extern u8 DAT_00308e08;
extern void FUN_00000a00();

/* Destructor: resets the vtable down the class chain, frees the object when flag > 0. */
VtableObj * FUN_00150ed0(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00308e08;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
