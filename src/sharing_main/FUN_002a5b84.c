/* HSTMATCH module=hstp_trans_main.prx start=0x002a5b84 end=0x002a5b90 symbol=FUN_002a5b84 lang=c99 */
/* Clone of src/eboot/FUN_002956e0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/ring_owner.h"

/* Reset the ring: clear both positions. */
void FUN_002a5b84(RingBuf *ring)
{
  ring->unk10 = 0;
  ring->unk0c = 0;
}
