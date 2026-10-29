/* HSTMATCH module=EBOOT.BIN start=0x001baecc end=0x001baef8 symbol=FUN_001baecc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/item_owner.h"

/* The unk171 byte of the first target of item `index`, 0 when it has none. */
u8 FUN_001baecc(ItemOwner *self,int index)
{
  u8 result;
  ItemTarget *target;
  
  target = self->items[index]->inner->target_a;
  result = 0;
  if (target != 0) {
    result = target->unk171;
  }
  return result;
}
