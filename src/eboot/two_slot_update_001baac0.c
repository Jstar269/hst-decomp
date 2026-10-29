/* HSTMATCH module=EBOOT.BIN start=0x001baac0 end=0x001bab98 symbol=FUN_001baac0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the flag byte is set with `if (b) 1 else 0` (truthy test; the `== 0` order puts the store in the other branch-likely slot); readability pass; exact match verified; names and types await human review. */
#include "hst/item_owner.h"

extern u8 FUN_001baf80();
extern void FUN_00206290();

/* Apply item slots 2 and 3 from their records when the record is in use. */
void FUN_001baac0(ItemOwner *self,ItemSlotRec **slots)
{
  u8 model;
  
  if ((*slots)[2].used != '\0') {
    model = FUN_001baf80(self->items[2]->table_index);
    FUN_00206290(self->items[2],model,(*slots)[2].src);
    self->unk10[2] = 1;
    self->unk14[2] = 1;
    if ((*slots)[2].flag) {
      self->unk18[2] = 1;
    }
    else {
      self->unk18[2] = 0;
    }
  }
  if ((*slots)[3].used != '\0') {
    model = FUN_001baf80(self->items[3]->table_index);
    FUN_00206290(self->items[3],model,(*slots)[3].src
                );
    self->unk10[3] = 1;
    self->unk14[3] = 1;
    if ((*slots)[3].flag) {
      self->unk18[3] = 1;
    }
    else {
      self->unk18[3] = 0;
    }
  }
}
