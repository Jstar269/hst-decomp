/* HSTMATCH module=EBOOT.BIN start=0x001c0bcc end=0x001c0c0c symbol=FUN_001c0bcc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vtable_obj.h"

extern void FUN_00000a00();

/* Deleting-destructor shape without member cleanup: frees self when flag > 0. */
VtableObj * FUN_001c0bcc(VtableObj *self,short flag)
{
  if ((self != 0) && (0 < flag)) {
    FUN_00000a00();
  }
  return self;
}
