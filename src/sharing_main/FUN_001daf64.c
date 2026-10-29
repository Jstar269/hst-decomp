/* HSTMATCH module=hstp_trans_main.prx start=0x001daf64 end=0x001dafb4 symbol=FUN_001daf64 lang=c99 */
/* Clone of src/eboot/FUN_001cc830.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

extern u32 DAT_003e48b4;
extern void FUN_001db01c();
extern char FUN_002980f8();

/* Hands the second name buffer to a global service, then clears it. */
void FUN_001daf64(NameBoxOwner *self)
{
  FUN_002980f8(DAT_003e48b4 + 0x1320,self->nameB,1);
  self->nameB[0] = 0;
  *(u8 *)(self->panel->unk20 + 0x6d) = 0;
  FUN_001db01c(self);
}
