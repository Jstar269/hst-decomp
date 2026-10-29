/* HSTMATCH module=EBOOT.BIN start=0x0008dba8 end=0x0008dd24 symbol=FUN_0008dba8 lang=c++ */
/* Hand-written reconstruction from the disassembly (wip/push_pair_0008dba8.c gave the field layout); exact match verified; matching idioms: Vec4 passed by value with only a default ctor (callee copies it into its frame), Item with a memberwise copy ctor placed by new(p) in an inline push_back(const Item&, Tag) with the out-of-line grow taking an empty Tag; names and types await human review. */
struct Tag {};
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
} __attribute__((aligned(16)));
struct Item {
  int a;
  unsigned char b;
  int c;
  Vec4 v;
  Item() {}
  Item(const Item &o) : a(o.a), b(o.b), c(o.c), v(o.v) {}
} __attribute__((aligned(16)));
inline void *operator new(unsigned, void *p) { return p; }
struct ItemVec;
extern "C" void FUN_0009103c(ItemVec *v, const Item *x, Tag t);
struct ItemVec {
  Item *data;
  unsigned size;
  unsigned cap;
  void push_back(const Item &x, Tag)
  {
    if (size < cap) {
      Item *p = data + size;
      new (p) Item(x);
      ++size;
    } else {
      FUN_0009103c(this, &x, Tag());
    }
  }
};
struct Self {
  ItemVec a;
  ItemVec b;
};

extern "C" void FUN_0008dba8(Self *self, int id, unsigned char flag, int kind, Vec4 v)
{
  Item item;
  item.a = id;
  item.b = flag;
  item.c = kind;
  item.v = v;
  self->a.push_back(item, Tag());
  if (kind == 1)
    self->b.push_back(item, Tag());
}
