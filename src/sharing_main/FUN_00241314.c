/* HSTMATCH module=hstp_trans_main.prx start=0x00241314 end=0x00241340 symbol=FUN_00241314 lang=c99 */
/* Clone of src/eboot/FUN_00231214.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/singleton_holder.h"

extern void FUN_00241348();

/* If the holder is pending, clear it (which notifies the target). */
void FUN_00241314(SingletonHolder *self)
{
  if (self->pending == HOLDER_PENDING_SET) {
    FUN_00241348(self,0);
  }
}
