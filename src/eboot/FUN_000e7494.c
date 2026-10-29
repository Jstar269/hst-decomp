/* HSTMATCH module=EBOOT.BIN start=0x000e7494 end=0x000e74d4 symbol=FUN_000e7494 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vtable_obj.h"

extern void FUN_00000a00();

/* Deleting-destructor shape without member cleanup: frees self when flag > 0. */
VtableObj * FUN_000e7494(VtableObj *self,short flag)
{
  if ((self != 0) && (0 < flag)) {
    FUN_00000a00();
  }
  return self;
}
