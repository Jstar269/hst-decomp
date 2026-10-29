/* HSTMATCH module=EBOOT.BIN start=0x0014d3fc end=0x0014d458 symbol=FUN_0014d3fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030837c;
extern u8 DAT_003083cc;
extern void FUN_00000a00();

/* Destructor: resets the vtable down the class chain, frees the object when flag > 0. */
VtableObj * FUN_0014d3fc(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_0030837c;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
