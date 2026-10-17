/* HSTMATCH module=hstp_trans_main.prx start=0x00299ba4 end=0x00299cc8 symbol=FUN_00299ba4 lang=c++ */
/* Clone of src/eboot/dispatch_request_00288470.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (sibling of dispatch_request_00288414.cpp); exact match verified; names and types await human review. Matching idioms: the queued item is a 24-byte record of which only tag/count/f are written (the unwritten tail gives the 80-byte frame), the returned and position iterators are class temporaries with a user copy ctor (passed by reference), and the clamp is a const-reference max returning `a < b ? b : a`. */
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

extern "C" float DAT_003a7940;
extern "C" Sub *FUN_0029a28c(Obj *);
extern "C" void FUN_002775dc(float, Sub *);
extern "C" void FUN_00277604(Sub *, int);
extern "C" void FUN_00277650(Sub *);
extern "C" void FUN_0027761c(float, Sub *);
extern "C" void FUN_00277634(Sub *);
extern "C" Iter FUN_0029ace0(List *, Iter, Item *);

static inline const float &Max(const float &a, const float &b)
{
  return a < b ? b : a;
}

extern "C" void FUN_00299ba4(Obj *self, int count, float f)
{
  Item item;
  if (count < 1) {
    if (self->mode() == 4) {
      Sub *s = FUN_0029a28c(self);
      if (f >= 0.0f) {
        FUN_002775dc(f, s);
        FUN_00277604(s, 0);
        FUN_00277650(s);
      } else {
        FUN_002775dc(0.0f, s);
        FUN_00277604(s, 1);
        FUN_0027761c(Max(1.0f / -f, DAT_003a7940), s);
        FUN_00277634(s);
      }
    }
  } else {
    item.tag = 0x55;
    item.count = count;
    item.f = f;
    FUN_0029ace0(&self->list, Iter(&self->list.sentinel), &item);
  }
}
