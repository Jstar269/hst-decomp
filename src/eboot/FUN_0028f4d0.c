/* HSTMATCH module=EBOOT.BIN start=0x0028f4d0 end=0x0028f52c symbol=FUN_0028f4d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309d64;
extern void FUN_00000a00();
extern u32 * FUN_00258180();

/* Deleting destructor: sets the vtable, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_0028f4d0(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309d64;
    FUN_00258180(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
