/* HSTMATCH module=EBOOT.BIN start=0x000e3a10 end=0x000e3a74 symbol=FUN_000e3a10 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00307690;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_000e3b2c();

/* Deleting destructor: sets the class vtable, releases the members, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_000e3a10(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00307690;
    FUN_000e3b2c();
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
