/* HSTMATCH module=EBOOT.BIN start=0x001ba644 end=0x001ba78c symbol=FUN_001ba644 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the 24-byte record is zeroed by a placement new[] of chars, and the byte result of FUN_001baf80 is masked at the call site, int k = (unsigned char)F(...), which fixes the saved-register colouring); names and types await human review. */
struct Rec {
  int id;
  unsigned a, b, c, d;
  int e;
};
struct Info {
  unsigned short h0, h1, h2, h3;
  unsigned char x8, x9, xa;
};
struct Item {
  int pad;
  int x4;
};
struct Ops {
  char pad[0xf0];
  int (*get)();
};
struct Slot {
  unsigned char used;
  char pad[0x2f];
};
struct Owner {
  char pad0[4];
  Item **items;
  char pad8[8];
  unsigned char f10[4];
  unsigned char f14[4];
};

inline void *operator new[](unsigned int, void *p) { return p; }

extern "C" {
Ops *FUN_0019d474(void);
int FUN_0016b1dc(int);
Info *FUN_0016b3d8(int, int);
int FUN_0016b19c(int);
int FUN_001baf80(int);
int FUN_00204570(int);
void FUN_00205df4(Item *, int, Rec *, int, int, int, int);
}

extern "C" void FUN_001ba644(Owner *self, int idx, Slot **slots)
{
  if ((*slots)[idx].used != 0) {
    int id = FUN_0019d474()->get();
    int n = FUN_0016b1dc(id);
    Info *info = FUN_0016b3d8(id, n);
    Rec rec;
    new (&rec) char[sizeof(Rec)]();
    rec.id = id;
    rec.a = info->h0;
    rec.b = info->h1;
    rec.c = info->h2;
    rec.d = info->h3;
    rec.e = FUN_0016b19c(id);
    int k = (unsigned char)FUN_001baf80(self->items[idx]->x4);
    Item **slot = &self->items[idx];
    int t = FUN_00204570(rec.id);
    FUN_00205df4(*slot, k, &rec, info->x8 != 0, info->x9 != 0, info->xa != 0, t);
    self->f10[idx] = 1;
    self->f14[idx] = 1;
  }
}
