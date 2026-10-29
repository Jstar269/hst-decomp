/* HSTMATCH module=EBOOT.BIN start=0x00115c24 end=0x00115c90 symbol=FUN_00115c24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307e7c;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();

/* Destructor: steps the vtable down the class chain, runs the base destructor, frees the object when flag > 0. */
VtableObj * FUN_00115c24(VtableObj *self,short flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00307e7c;
    if (self != (VtableObj *)0x0) {
      self->vtable = &DAT_0030779c;
      FUN_00100b24(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
