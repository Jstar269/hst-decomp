/* HSTMATCH module=EBOOT.BIN start=0x00199c44 end=0x00199ca0 symbol=FUN_00199c44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030926c;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Deleting destructor: sets this class's vtable, runs the base destructor and frees when flag > 0. */
VtableObj * FUN_00199c44(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_0030926c;
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
