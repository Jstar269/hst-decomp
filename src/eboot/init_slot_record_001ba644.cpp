/* HSTMATCH module=EBOOT.BIN start=0x001ba644 end=0x001ba78c symbol=FUN_001ba644 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the 24-byte record is zeroed by a placement new[] of chars, and the byte result of FUN_001baf80 is masked at the call site, int k = (unsigned char)F(...), which fixes the saved-register colouring); names and types await human review. */
#include "hst/item_owner.h"

/* Rectangle-like argument of the apply call: id, four values from the config record, one more value. */
struct Rec {
  int id;
  unsigned v[4];
  int extra;
};
struct Ops {
  char pad[0xf0];
  int (*get)();
};

inline void *operator new[](unsigned int, void *p) { return p; }

extern "C" {
Ops *FUN_0019d474(void);
int FUN_0016b1dc(int);
SlotCfg *FUN_0016b3d8(int, int);
int FUN_0016b19c(int);
int FUN_001baf80(int);
int FUN_00204570(int);
void FUN_00205df4(OwnedItem *, int, Rec *, int, int, int, int);
}

/* Apply item `idx` from its slot record when the record is in use; the id comes from the singleton's get slot. */
extern "C" void FUN_001ba644(ItemOwner *self, int idx, ItemSlotRec **slots)
{
  if ((*slots)[idx].used != 0) {
    int id = FUN_0019d474()->get();
    int n = FUN_0016b1dc(id);
    SlotCfg *cfg = FUN_0016b3d8(id, n);
    Rec rec;
    new (&rec) char[sizeof(Rec)]();
    rec.id = id;
    rec.v[0] = cfg->v[0];
    rec.v[1] = cfg->v[1];
    rec.v[2] = cfg->v[2];
    rec.v[3] = cfg->v[3];
    rec.extra = FUN_0016b19c(id);
    int k = (unsigned char)FUN_001baf80(self->items[idx]->table_index);
    OwnedItem **slot = &self->items[idx];
    int t = FUN_00204570(rec.id);
    FUN_00205df4(*slot, k, &rec, cfg->unk08 != 0, cfg->unk09 != 0, cfg->unk0a != 0, t);
    self->unk10[idx] = 1;
    self->unk14[idx] = 1;
  }
}
