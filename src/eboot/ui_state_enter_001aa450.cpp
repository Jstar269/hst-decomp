/* HSTMATCH module=EBOOT.BIN start=0x001aa450 end=0x001aa558 symbol=FUN_001aa450 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review (matching idiom: each live range is its own local with a typed struct view, no variable reuse as in Ghidra, and the widget member read twice through `void **pp = &o->f84;`; supersedes the near miss wip/ui_state_enter_001aa450.c). */
/* Looks up an item id through the context getter (field +0x300), stores a value computed from it into the object at +0x3e8 (fields +0xf8, +0x138) and updates +0x24 of the object at +0xfc; then calls FUN_000ffb3c(widget at +0x84, 1) and, when FUN_001a4b74(ctx, 3) holds and the context field +0x388 is greater than 1, FUN_000ffb3c(widget, 0). */
struct Sub_001aa450 {
  char pad0[0xf8];
  void *fF8;
  char pad1[0x3c];
  int f138;
};
struct Link_001aa450 {
  char pad0[0x24];
  int f24;
  int f28;
};
struct Obj_001aa450 {
  char pad0[0x84];
  void *f84;
  char pad1[0x74];
  Link_001aa450 *fFC;
  char pad2[0x2e8];
  Sub_001aa450 *f3e8;
};
struct Ctx_001aa450 {
  char pad0[0x300];
  int f300;
  char pad1[0x80];
  int f384;
  int f388;
};
extern "C" Ctx_001aa450 *FUN_0019d474(void);
extern "C" int FUN_001a49f4(Ctx_001aa450 *, int);
extern "C" int FUN_001a4b74(Ctx_001aa450 *, int);
extern "C" void *FUN_001fea10(int, int, int);
extern "C" void FUN_0010d4a8(Sub_001aa450 *);
extern "C" void FUN_000ffb3c(void *, int);

extern "C" void FUN_001aa450(Obj_001aa450 *o)
{
  Ctx_001aa450 *c = FUN_0019d474();
  int idx = FUN_001a49f4(FUN_0019d474(), c->f300);
  if (idx == -1) {
    void *v = FUN_001fea10(0x13, 0, 5);
    Sub_001aa450 *s = o->f3e8;
    s->fF8 = v;
    s->f138 = 1;
    FUN_0010d4a8(s);
    o->fFC->f24 = o->fFC->f28 + 8;
  } else {
    void *v = FUN_001fea10(5, 0, idx);
    Sub_001aa450 *s = o->f3e8;
    s->fF8 = v;
    s->f138 = 1;
    FUN_0010d4a8(s);
    o->fFC->f24 = o->fFC->f28 + idx;
  }
  void **pp = &o->f84;
  FUN_000ffb3c(*pp, 1);
  if (FUN_001a4b74(FUN_0019d474(), 3) != 0 && FUN_0019d474()->f388 > 1) {
    FUN_000ffb3c(*pp, 0);
  }
}
