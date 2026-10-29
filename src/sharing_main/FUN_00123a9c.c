/* HSTMATCH module=hstp_trans_main.prx start=0x00123a9c end=0x00123adc symbol=FUN_00123a9c lang=c99 */
/* Clone of src/eboot/FUN_001188c8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/deque_owner.h"

extern int FUN_0005c688();

/* Releases the owned object at +0xec, if any. */
void FUN_00123a9c(DequeOwner *self)
{
  void *owned;
  
  owned = self->unkec;
  if ((owned != 0) && (owned != 0)) {
    FUN_0005c688(owned,1);
    self->unkec = 0;
  }
}
