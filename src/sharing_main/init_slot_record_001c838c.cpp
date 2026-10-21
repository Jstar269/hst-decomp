/* HSTMATCH module=hstp_trans_main.prx start=0x001c838c end=0x001c84d4 symbol=FUN_001c838c lang=c++ */
/* Clone of src/eboot/init_slot_record_001ba644.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the 24-byte record is zeroed by a placement new[] of chars, and the byte result of FUN_001c8cc8 is masked at the call site, int k = (unsigned char)F(...), which fixes the saved-register colouring); names and types await human review. */
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
Ops *FUN_001aa91c(void);
int FUN_001773a0(int);
Info *FUN_0017759c(int, int);
int FUN_00177360(int);
int FUN_001c8cc8(int);
int FUN_00212dd8(int);
void FUN_0021465c(Item *, int, Rec *, int, int, int, int);
}

extern "C" void FUN_001c838c(Owner *self, int idx, Slot **slots)
{
  if ((*slots)[idx].used != 0) {
    int id = FUN_001aa91c()->get();
    int n = FUN_001773a0(id);
    Info *info = FUN_0017759c(id, n);
    Rec rec;
    new (&rec) char[sizeof(Rec)]();
    rec.id = id;
    rec.a = info->h0;
    rec.b = info->h1;
    rec.c = info->h2;
    rec.d = info->h3;
    rec.e = FUN_00177360(id);
    int k = (unsigned char)FUN_001c8cc8(self->items[idx]->x4);
    Item **slot = &self->items[idx];
    int t = FUN_00212dd8(rec.id);
    FUN_0021465c(*slot, k, &rec, info->x8 != 0, info->x9 != 0, info->xa != 0, t);
    self->f10[idx] = 1;
    self->f14[idx] = 1;
  }
}
