/* HSTMATCH module=EBOOT.BIN start=0x00095d0c end=0x00095d64 symbol=FUN_00095d0c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vtable_obj.h"

extern void FUN_00000a00();
extern int * FUN_000b42f8();

/* Deleting destructor: tears the object down and frees it when flag > 0. */
VtableObj * FUN_00095d0c(VtableObj *self,short flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000b42f8(self,0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
