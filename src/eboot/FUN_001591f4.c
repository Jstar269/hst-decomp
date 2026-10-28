/* HSTMATCH module=EBOOT.BIN start=0x001591f4 end=0x00159250 symbol=FUN_001591f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003083cc;
extern u8 DAT_00308af4;
extern void FUN_00000a00();

VtableObj * FUN_001591f4(VtableObj *self,short delete_flag)
{
  /* Destructor shape: set this class's vtable, then the base class's; free the object when the flag is positive. */
  if (self != 0) {
    self->vtable = &DAT_00308af4;
    if (self != 0) {
      self->vtable = &DAT_003083cc;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
