/* HSTMATCH module=EBOOT.BIN start=0x00263558 end=0x002635b4 symbol=FUN_00263558 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309a04;
extern void FUN_00000a00();
extern u32 * FUN_00258180();

/* Deleting destructor: set the vtable, run the base destructor, free the memory when delete_flag is positive. */
VtableObj * FUN_00263558(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00309a04;
    FUN_00258180(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
