/* HSTMATCH module=hstp_trans_main.prx start=0x001b7a1c end=0x001b7b24 symbol=FUN_001b7a1c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review (matching idiom: each live range is its own local with a typed struct view, no variable reuse as in Ghidra, and the widget member read twice through `void **pp = &o->f84;`). */
/* Looks up an item id through the context getter (field +0x300), stores a value computed from it into the object at +0x3e8 (fields +0xf8, +0x138) and updates +0x24 of the object at +0xfc; then calls FUN_00105470(widget at +0x84, 1) and, when FUN_001b2140(ctx, 3) holds and the context field +0x388 is greater than 1, FUN_00105470(widget, 0). */
struct Sub_001b7a1c {
  char pad0[0xf8];
  void *fF8;
  char pad1[0x3c];
  int f138;
};
struct Link_001b7a1c {
  char pad0[0x24];
  int f24;
  int f28;
};
struct Obj_001b7a1c {
  char pad0[0x84];
  void *f84;
  char pad1[0x74];
  Link_001b7a1c *fFC;
  char pad2[0x2e8];
  Sub_001b7a1c *f3e8;
};
struct Ctx_001b7a1c {
  char pad0[0x300];
  int f300;
  char pad1[0x80];
  int f384;
  int f388;
};
extern "C" Ctx_001b7a1c *FUN_001aa91c(void);
extern "C" int FUN_001b1fc0(Ctx_001b7a1c *, int);
extern "C" int FUN_001b2140(Ctx_001b7a1c *, int);
extern "C" void *FUN_0020d1e0(int, int, int);
extern "C" void FUN_00113a50(Sub_001b7a1c *);
extern "C" void FUN_00105470(void *, int);

extern "C" void FUN_001b7a1c(Obj_001b7a1c *o)
{
  Ctx_001b7a1c *c = FUN_001aa91c();
  int idx = FUN_001b1fc0(FUN_001aa91c(), c->f300);
  if (idx == -1) {
    void *v = FUN_0020d1e0(0x13, 0, 5);
    Sub_001b7a1c *s = o->f3e8;
    s->fF8 = v;
    s->f138 = 1;
    FUN_00113a50(s);
    o->fFC->f24 = o->fFC->f28 + 8;
  } else {
    void *v = FUN_0020d1e0(5, 0, idx);
    Sub_001b7a1c *s = o->f3e8;
    s->fF8 = v;
    s->f138 = 1;
    FUN_00113a50(s);
    o->fFC->f24 = o->fFC->f28 + idx;
  }
  void **pp = &o->f84;
  FUN_00105470(*pp, 1);
  if (FUN_001b2140(FUN_001aa91c(), 3) != 0 && FUN_001aa91c()->f388 > 1) {
    FUN_00105470(*pp, 0);
  }
}
