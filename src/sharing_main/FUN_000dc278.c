/* HSTMATCH module=hstp_trans_main.prx start=0x000dc278 end=0x000dc2e4 symbol=FUN_000dc278 lang=c99 */
/* Clone of src/eboot/FUN_000d8474.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/elem_array_obj.h"

extern u8 DAT_003b08ac;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000dc20c();

/* Deleting destructor: destroy the element array, free the object when flag > 0. */
ElemArrayObj * FUN_000dc278(ElemArrayObj *self,short flag)
{
  if (self != (ElemArrayObj *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b08ac);
    FUN_00000788(self->elems,FUN_000dc20c,ELEM_ARRAY_STRIDE,ELEM_ARRAY_COUNT);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
