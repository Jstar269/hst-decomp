/* HSTMATCH module=hstp_trans_main.prx start=0x001c8c40 end=0x001c8c6c symbol=FUN_001c8c40 lang=c99 */
/* Clone of src/eboot/FUN_001baef8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/item_owner.h"

/* The unk171 byte of the second target of item `index`, 0 when it has none. */
u8 FUN_001c8c40(ItemOwner *self,int index)
{
  u8 result;
  ItemTarget *target;
  
  target = self->items[index]->inner->target_b;
  result = 0;
  if (target != 0) {
    result = target->unk171;
  }
  return result;
}
