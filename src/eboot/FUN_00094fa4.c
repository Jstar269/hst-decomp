/* HSTMATCH module=EBOOT.BIN start=0x00094fa4 end=0x00094fe0 symbol=FUN_00094fa4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00307278;
extern u32 * FUN_00056b98();
extern void FUN_0009503c();

/* Constructor: runs the base constructor, sets the class vtable, then finishes the setup. */
VtableObj * FUN_00094fa4(VtableObj *self)
{
  FUN_00056b98();
  self->vtable = &DAT_00307278;
  FUN_0009503c(self);
  return self;
}
