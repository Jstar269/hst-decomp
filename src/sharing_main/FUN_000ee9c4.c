/* HSTMATCH module=hstp_trans_main.prx start=0x000ee9c4 end=0x000ee9d8 symbol=FUN_000ee9c4 lang=c99 */
/* Clone of src/eboot/FUN_000e98f0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/elem_owner.h"

extern u8 DAT_002d10e0;

/* Constructor of an owner element: set the vtable pointer at +0x40. */
ElemSlot *FUN_000ee9c4(ElemSlot *self)
{
  self->vtable = &DAT_002d10e0;
  return self;
}
