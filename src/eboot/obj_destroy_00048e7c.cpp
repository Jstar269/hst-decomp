/* HSTMATCH module=EBOOT.BIN start=0x00048e7c end=0x00048ef8 symbol=FUN_00048e7c lang=c++ */
/* Hand-written reconstruction from the disassembly (lane km1 near miss, finished by lane wf20261026-e01-03: the third callee argument is an empty tag passed by value, `move v0,zero; seb a2,v0`); the duplicated `self != 0` tests stand for inlined destructor null checks (matching idiom: repeated null test); exact match verified; names and types await human review. */
struct Obj {
  void *f0;
  int f4;
};

struct Tag {};
extern "C" void FUN_00048ef8(Obj *, int, Tag);
extern "C" void FUN_00000a00(void *);

static inline void Free(void *p, Tag)
{
  FUN_00000a00(p);
}

extern "C" Obj *FUN_00048e7c(Obj *self, short flag)
{
  if (self != 0) {
    if (self != 0 && self != 0) {
      FUN_00048ef8(self, self->f4, Tag());
      if (self->f0 != 0) {
        Free(self->f0, Tag());
      }
    }
    if (flag > 0) {
      Free(self, Tag());
    }
  }
  return self;
}
