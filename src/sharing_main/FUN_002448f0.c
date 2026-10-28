/* HSTMATCH module=hstp_trans_main.prx start=0x002448f0 end=0x0024492c symbol=FUN_002448f0 lang=c99 */
/* Clone of src/eboot/FUN_002347c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/holder.h"

extern u8 DAT_003b2b64;
extern u8 DAT_003b2b70;

/* Constructor of the derived holder: base vtable first, then the derived one, all members zeroed. */
HolderDerived * FUN_002448f0(HolderDerived *self)
{
  self->base.vptr = (void *)(&DAT_003b2b70);
  self->base.member08[0] = 0;
  self->base.member08[1] = 0;
  self->base.member08[2] = 0;
  self->base.unk04 = 0;
  self->base.vptr = (void *)(&DAT_003b2b64);
  self->member14[0] = 0;
  self->member14[1] = 0;
  self->member14[2] = 0;
  return self;
}
