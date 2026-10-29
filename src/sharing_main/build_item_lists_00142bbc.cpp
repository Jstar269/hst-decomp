/* HSTMATCH module=hstp_trans_main.prx start=0x00142bbc end=0x00142e8c symbol=FUN_00142bbc lang=c++ */
/* Clone of src/eboot/build_item_lists_00137570.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (Ghidra pseudocode from wip/FUN_00142bbc_00142bbc.c was only the starting point); exact match verified; matching idioms: index loop with opt_strength_reduction off, Item330::Mark() so the three flag stores share one reload, Vec4 aligned(16) locals, push_back with an empty Tag, by-value Vec2 setter (loads both floats first); names and types await human review. */
#pragma opt_strength_reduction off
struct Tag {};
struct Vec4 {
  float x, y, z, w;
} __attribute__((aligned(16)));
struct Item330 {
  char pad[0x3c];
  char f3c;
  char f3d;
  char pad1[0x301 - 0x3e];
  char f301;
  void Mark() { f3c = 1; f3d = 1; f301 = 1; }
};
struct Vec2 {
  float x, y;
  Vec2() {}
  Vec2(const Vec2 &o) : x(o.x), y(o.y) {}
};
struct Item280 {
  char pad[0x24c];
  Vec2 p;
  void SetP(Vec2 v) { p = v; }
};
struct Elem {
  int id;
  int a;
  int b;
  int c;
  float d;
  float e;
  int f;
  int g;
  int flag;
};
extern "C" void FUN_001480d0(void *v, Item330 *const *x, Tag t);
extern "C" void FUN_0014817c(void *v, Item280 *const *x, Tag t);
extern "C" void *FUN_00000bcc(unsigned n);
extern "C" Item330 *FUN_0024eecc(void *mem, int id);
extern "C" void FUN_0024ffa0(Item330 *o, int a, int b, int c, float d, float e, int f, int g);
extern "C" void FUN_0001ef34(void *self, void *obj);
extern "C" Item280 *FUN_0025b7a8(void *mem, int kind);
extern "C" void FUN_0025bc70(Item280 *o, const Vec4 *a, const Vec4 *b);

struct Item330Vec {
  Item330 **data;
  unsigned size;
  unsigned cap;
  void push_back(Item330 *const &x, Tag)
  {
    unsigned n = size;
    if (n < cap) {
      size = n + 1;
      data[size - 1] = x;
    } else {
      FUN_001480d0(this, &x, Tag());
    }
  }
};
struct Item280Vec {
  Item280 **data;
  unsigned size;
  unsigned cap;
  Item280 *&at(unsigned i) { return data[i]; }
  Item280 *&back() { return at(size - 1); }
  void push_back(Item280 *const &x, Tag)
  {
    if (size < cap) {
      ++size;
      back() = x;
    } else {
      FUN_0014817c(this, &x, Tag());
    }
  }
};
struct Self {
  char pad0[0x1350];
  Vec2 p1350;
  char pad1[0x1398 - 0x1358];
  Item330Vec items;
  Item280Vec walls;
  char pad2[0x13cc - 0x13b0];
  Elem *elems;
  unsigned elemCount;
};

extern "C" void FUN_00142bbc(Self *self)
{
  Item330 *o330;
  Item280 *o280;
  Vec4 vb;
  Vec4 va;
  for (int i = 0; i < self->elemCount; i++) {
    Item330 *mem = (Item330 *)FUN_00000bcc(0x330);
    if (mem)
      mem = FUN_0024eecc(mem, self->elems[i].id);
    o330 = mem;
    Elem *e = &self->elems[i];
    FUN_0024ffa0(o330, e->a, e->b, e->c, e->d, e->e, e->f, e->g);
    if (self->elems[i].flag != 0) {
      o330->Mark();
    }
    self->items.push_back(o330, Tag());
    FUN_0001ef34(self, o330);
  }
  {
    Item280 *mem = (Item280 *)FUN_00000bcc(0x280);
    if (mem)
      mem = FUN_0025b7a8(mem, 0xb);
    o280 = mem;
    vb.x = 12.0f; vb.y = 0.0f; vb.z = -9.12f; vb.w = 1.0f;
    va.x = -12.0f; va.y = 0.0f; va.z = -9.12f; va.w = 1.0f;
    FUN_0025bc70(o280, &vb, &va);
    o280->SetP(self->p1350);
    self->walls.push_back(o280, Tag());
    FUN_0001ef34(self, o280);
  }
  {
    Item280 *mem = (Item280 *)FUN_00000bcc(0x280);
    if (mem)
      mem = FUN_0025b7a8(mem, 0xc);
    o280 = mem;
    vb.x = 12.0f; vb.y = -3.0f; vb.z = -9.12f; vb.w = 1.0f;
    va.x = -12.0f; va.y = -3.0f; va.z = -9.12f; va.w = 1.0f;
    FUN_0025bc70(o280, &vb, &va);
    o280->SetP(self->p1350);
    self->walls.push_back(o280, Tag());
    FUN_0001ef34(self, o280);
  }
}
