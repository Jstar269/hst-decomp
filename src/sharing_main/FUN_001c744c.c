/* HSTMATCH module=hstp_trans_main.prx start=0x001c744c end=0x001c7490 symbol=FUN_001c744c lang=c99 */
/* Clone of src/eboot/FUN_001b9760.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/owned_member_obj.h"

extern u8 DAT_003b25c4;
extern u32 * FUN_0001ec44();

/* Constructor: base init, vtable, and the owned member and flags cleared. */
OwnedMemberObj * FUN_001c744c(OwnedMemberObj *self)
{
  FUN_0001ec44();
  self->vtable = (unsigned int)(&DAT_003b25c4);
  self->member = 0;
  self->unk40 = 0;
  self->unk41 = 0;
  self->unk44 = 0;
  return self;
}
