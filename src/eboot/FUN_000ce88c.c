/* HSTMATCH module=EBOOT.BIN start=0x000ce88c end=0x000ce8e8 symbol=FUN_000ce88c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030753c;
extern u8 DAT_00307550;
extern void FUN_00000a00();

/* Deleting destructor with the base destructor inlined: the derived vtable is set, then the base vtable; frees the object when delete_flag > 0. */
VtableObj * FUN_000ce88c(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00307550;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_0030753c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
