/* HSTMATCH module=EBOOT.BIN start=0x001ba78c end=0x001ba8a8 symbol=FUN_001ba78c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/item_owner.h"

extern int FUN_0016b1dc(int id);
extern SlotCfg *FUN_0016b3d8(int id, int prev);
extern int FUN_0016b19c(int id);
extern unsigned char FUN_001baf80(int index);
extern int FUN_00204570(int id);
extern void FUN_00205df4(OwnedItem *item, unsigned char mode, int *rect, int a, int b, int c, int d);

/* Apply item slot 1 from its slot record: build the rectangle (id, four values, FUN_0016b19c result) and hand it to the item. */
void FUN_001ba78c(ItemOwner *self, ItemSlotRec **slots)
{
    ItemSlotRec *rec = *slots + 1;
    if (rec->used == 0)
        return;
    int id = rec->src->id;
    SlotCfg *cfg = FUN_0016b3d8(id, FUN_0016b1dc(id));
    int rect[6] = {0};
    rect[0] = id;
    SlotSrc *src = (*slots)[1].src;
    rect[1] = src->v[0];
    rect[2] = src->v[1];
    rect[3] = src->v[2];
    rect[4] = src->v[3];
    rect[5] = FUN_0016b19c(id);
    unsigned char mode = FUN_001baf80(self->items[1]->table_index);
    OwnedItem **slot = &self->items[1];
    int v = FUN_00204570(rect[0]);
    FUN_00205df4(*slot, mode, rect, cfg->unk08 != 0,
                 cfg->unk09 != 0, cfg->unk0a != 0, v);
    self->unk10[1] = 1;
    self->unk14[1] = 1;
}
