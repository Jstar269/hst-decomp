/* HSTMATCH module=hstp_trans_main.prx start=0x00131af4 end=0x00131b28 symbol=FUN_00131af4 lang=c99 */
/* Clone of src/eboot/FUN_00126884.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ring_owner.h"

extern u32 FUN_00104f10();

/* Read up to *len bytes from the ring into dst; *len receives the count read. */
void FUN_00131af4(RingOwner *self,u32 dst,u32 *len)
{
  u32 count;
  
  count = FUN_00104f10(self->ring,dst,*len,0);
  *len = count;
}
