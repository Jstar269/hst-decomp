/* HSTMATCH module=EBOOT.BIN start=0x00106844 end=0x001068b0 symbol=FUN_00106844 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307a4c;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

/* Deleting destructor: switch to the base vtable, run the base destructor, free when delete_flag > 0. */
VtableObj * FUN_00106844(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00307a4c;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_0030779c;
      FUN_00100b24(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
