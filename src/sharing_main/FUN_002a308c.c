/* HSTMATCH module=hstp_trans_main.prx start=0x002a308c end=0x002a30f8 symbol=FUN_002a308c lang=c99 */
/* Clone of src/eboot/FUN_00291a80.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/material_set.h"

extern u8 DAT_003b30c4;

/* Constructor: installs the vtable and clears every member. */
MaterialSet * FUN_002a308c(MaterialSet *self)
{
  self->vtable = &DAT_003b30c4;
  self->owned = 0;
  self->res = 0;
  self->unk14 = 0;
  self->slot[0] = 0;
  self->slot[1] = 0;
  self->slot[2] = 0;
  self->slot[3] = 0;
  self->slot[4] = 0;
  self->slot[5] = 0;
  self->slot[6] = 0;
  self->unk14 = 0;
  self->unk4 = 0;
  self->unk8 = 0;
  self->unk34 = 0;
  self->unk38 = 0;
  self->unk3c = 0x3f800000;
  self->unk40 = 0;
  self->unk41 = 0;
  self->mode = 2;
  self->unk48 = 0;
  return self;
}
