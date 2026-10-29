/* HSTMATCH module=EBOOT.BIN start=0x000d8474 end=0x000d84e0 symbol=FUN_000d8474 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/elem_array_obj.h"

extern u8 DAT_003075e0;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000d8408();

/* Deleting destructor: destroy the element array, free the object when flag > 0. */
ElemArrayObj * FUN_000d8474(ElemArrayObj *self,short flag)
{
  if (self != (ElemArrayObj *)0x0) {
    self->vtable = (unsigned int)(&DAT_003075e0);
    FUN_00000788(self->elems,FUN_000d8408,ELEM_ARRAY_STRIDE,ELEM_ARRAY_COUNT);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
