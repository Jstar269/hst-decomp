/* HSTMATCH module=hstp_trans_main.prx start=0x00131b28 end=0x00131b34 symbol=FUN_00131b28 lang=c99 */
/* Clone of src/eboot/FUN_001268b8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ring_owner.h"

extern u32 FUN_00104f10();

/* Same ring call as the read above with the last argument set to 1. */
void FUN_00131b28(RingOwner *self,u32 buf,u32 len)
{
  FUN_00104f10(self->ring,buf,len,1);
}
