/* HSTMATCH module=EBOOT.BIN start=0x00293ae0 end=0x00293b7c symbol=FUN_00293ae0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of a ShopItemSet (ShopVec[8], 12-byte vectors, size at +4): body shrinks each vector by its own size through the out-of-line 0x294010 (empty tag by value), then the member-array destroy 0x788 with the vector deleting-dtor stub 0x293a74. Names provisional. */
#include "hst/shop_items.h"

struct Tag {};
extern "C" void FUN_00294010(ShopVec *, int, Tag);
extern "C" void FUN_00293a74();
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00000a00(void *);

extern "C" ShopItemSet *FUN_00293ae0(ShopItemSet *self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < SHOP_VEC_COUNT; i++) {
            FUN_00294010(&self->vecs[i], self->vecs[i].size, Tag());
        }
        FUN_00000788(self, (void *)FUN_00293a74, sizeof(ShopVec), SHOP_VEC_COUNT);
        if (flag > 0) {
            FUN_00000a00(self);
        }
    }
    return self;
}
