/* HSTMATCH module=EBOOT.BIN start=0x000d83b8 end=0x000d8408 symbol=FUN_000d83b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/elem_array_obj.h"

extern u8 DAT_003075e0;
extern void FUN_000007f4();
extern void FUN_000d8408();
extern void FUN_000d8460();

/* Constructor: set the vtable and construct the element array. */
ElemArrayObj * FUN_000d83b8(ElemArrayObj *self)
{
  self->vtable = (unsigned int)(&DAT_003075e0);
  FUN_000007f4((int)self->elems,FUN_000d8460,FUN_000d8408,ELEM_ARRAY_STRIDE,ELEM_ARRAY_COUNT);
  return self;
}
