/* HSTMATCH module=EBOOT.BIN start=0x00115aa0 end=0x00115afc symbol=FUN_00115aa0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00307dd4;
extern void FUN_00000a00();
extern u32 * FUN_00102ea4();

/* Destructor: installs this class's vtable, runs the base destructor, frees the object when flag > 0. */
VtableObj * FUN_00115aa0(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00307dd4;
    FUN_00102ea4(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
