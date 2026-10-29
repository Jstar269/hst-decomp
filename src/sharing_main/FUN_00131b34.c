/* HSTMATCH module=hstp_trans_main.prx start=0x00131b34 end=0x00131b48 symbol=FUN_00131b34 lang=c99 */
/* Clone of src/eboot/FUN_001268c4.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ring_owner.h"

/* Bytes available in the ring. */
int FUN_00131b34(RingOwner *self)
{
  return self->ring->unk10 - self->ring->unk0c;
}
