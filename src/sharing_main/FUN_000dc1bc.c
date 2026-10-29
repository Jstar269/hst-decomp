/* HSTMATCH module=hstp_trans_main.prx start=0x000dc1bc end=0x000dc20c symbol=FUN_000dc1bc lang=c99 */
/* Clone of src/eboot/FUN_000d83b8.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/elem_array_obj.h"

extern u8 DAT_003b08ac;
extern void FUN_000007f4();
extern void FUN_000dc20c();
extern void FUN_000dc264();

/* Constructor: set the vtable and construct the element array. */
ElemArrayObj * FUN_000dc1bc(ElemArrayObj *self)
{
  self->vtable = (unsigned int)(&DAT_003b08ac);
  FUN_000007f4((int)self->elems,FUN_000dc264,FUN_000dc20c,ELEM_ARRAY_STRIDE,ELEM_ARRAY_COUNT);
  return self;
}
