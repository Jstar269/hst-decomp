/* HSTMATCH module=hstp_trans_main.prx start=0x001c8a30 end=0x001c8a7c symbol=FUN_001c8a30 lang=c99 */
/* Clone of src/eboot/FUN_001bace8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/item_owner.h"

extern void FUN_002134e8();

/* Release item `index` and clear its flag bytes. */
void FUN_001c8a30(ItemOwner *self,int index)
{
  FUN_002134e8(self->items[index]);
  self->unk10[index] = 0;
  self->unk14[index] = 0;
}
