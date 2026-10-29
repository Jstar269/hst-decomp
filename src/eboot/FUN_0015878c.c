/* HSTMATCH module=EBOOT.BIN start=0x0015878c end=0x001587e8 symbol=FUN_0015878c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030840c;
extern u8 DAT_003086e4;
extern void FUN_00000a00();

/* Destructor shape: set this class's vtable, then the base class's; free the object when the flag is positive. */
VtableObj * FUN_0015878c(VtableObj *self,short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_003086e4;
    if (self != 0) {
      self->vtable = &DAT_0030840c;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
