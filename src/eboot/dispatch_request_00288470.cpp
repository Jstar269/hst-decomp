/* HSTMATCH module=EBOOT.BIN start=0x00288470 end=0x00288594 symbol=FUN_00288470 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of dispatch_request_00288414.cpp. Matching idioms: the queued item is a 24-byte record of which only tag/count/f are written (the unwritten tail gives the 80-byte frame); the returned and position iterators are class temporaries with a user copy ctor (passed by reference); the clamp is a const-reference max returning `a < b ? b : a`. */
struct Node { Node *prev, *next; };
struct Iter {
  Node *node;
  Iter() {}
  Iter(Node *n) : node(n) {}
  Iter(const Iter &o) : node(o.node) {}
};
struct List { int size; Node sentinel; };
struct Item { int tag; int count; float f; int unused[3]; };

struct Obj {
  virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
  virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
  virtual int v8(); virtual int v9(); virtual int v10(); virtual int mode();
  char pad[0x64 - 4];
  List list;
};
struct Sub;

extern "C" float DAT_002fea18;
extern "C" Sub *FUN_00288af0(Obj *);
extern "C" void FUN_002666d4(float, Sub *);
extern "C" void FUN_002666fc(Sub *, int);
extern "C" void FUN_00266748(Sub *);
extern "C" void FUN_00266714(float, Sub *);
extern "C" void FUN_0026672c(Sub *);
extern "C" Iter FUN_00289544(List *, Iter, Item *);

static inline const float &Max(const float &a, const float &b)
{
  return a < b ? b : a;
}

extern "C" void FUN_00288470(Obj *self, int count, float f)
{
  Item item;
  if (count < 1) {
    if (self->mode() == 4) {
      Sub *s = FUN_00288af0(self);
      if (f >= 0.0f) {
        FUN_002666d4(f, s);
        FUN_002666fc(s, 0);
        FUN_00266748(s);
      } else {
        FUN_002666d4(0.0f, s);
        FUN_002666fc(s, 1);
        FUN_00266714(Max(1.0f / -f, DAT_002fea18), s);
        FUN_0026672c(s);
      }
    }
  } else {
    item.tag = 0x55;
    item.count = count;
    item.f = f;
    FUN_00289544(&self->list, Iter(&self->list.sentinel), &item);
  }
}
