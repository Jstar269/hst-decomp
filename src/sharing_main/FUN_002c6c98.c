/* HSTMATCH module=hstp_trans_main.prx start=0x002c6c98 end=0x002c6cc4 symbol=FUN_002c6c98 lang=c99 */
/* Clone of src/eboot/FUN_0027e71c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/dtor_pair_obj.h"

extern u8 DAT_003b32bc;

/* Constructor: sets the vtable and clears the six words after it. */
DtorPairObj * FUN_002c6c98(DtorPairObj *self)
{
  self->vtable = &DAT_003b32bc;
  self->unk4 = 0;
  self->unk8 = 0;
  self->unkc = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  self->unk18 = 0;
  return self;
}
