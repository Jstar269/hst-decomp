/* HSTMATCH module=EBOOT.BIN start=0x001ee87c end=0x001ee8bc symbol=FUN_001ee87c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vtable_obj.h"

extern void FUN_00000a00();

/* Deleting destructor: frees the object when flags is positive. */
VtableObj *FUN_001ee87c(VtableObj *self,short flags)
{
  if ((self != 0) && (0 < flags)) {
    FUN_00000a00();
  }
  return self;
}
