/* HSTMATCH module=EBOOT.BIN start=0x00048e7c end=0x00048ef8 symbol=FUN_00048e7c lang=c++ */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
struct Obj {
  void *f0;
  int f4;
};

extern "C" void FUN_00048ef8(Obj *, int, signed char);
extern "C" void FUN_00000a00(void *);

struct Tag {};

static inline void Free(void *p, Tag)
{
  FUN_00000a00(p);
}

extern "C" Obj *FUN_00048e7c(Obj *self, short flag)
{
  if (self != 0) {
    if (self != 0 && self != 0) {
      FUN_00048ef8(self, self->f4, 0);
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
// near miss from lane km1 (unreviewed)
