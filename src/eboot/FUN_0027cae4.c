/* HSTMATCH module=EBOOT.BIN start=0x0027cae4 end=0x0027cb40 symbol=FUN_0027cae4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309c34;
extern void FUN_00000a00();
extern u32 * FUN_00060e7c();

/* Deleting destructor: sets the class vtable, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_0027cae4(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309c34;
    FUN_00060e7c(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
