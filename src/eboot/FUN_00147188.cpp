/* HSTMATCH module=EBOOT.BIN start=0x00147188 end=0x00147274 symbol=FUN_00147188 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(3)
struct Tag {};
struct Elem { int flags; int pad[9]; };
struct Cont { Elem *begin; int size; };
extern "C" void FUN_00000a00(void *p);
extern "C" void *FUN_00003004(void *p);
extern "C" void FUN_000030a8(void *p);
extern "C" void FUN_000039b0(void *p);

inline void notify(Elem *p, Tag t)
{
  FUN_000030a8(p);
}

extern "C" Cont *FUN_00147188(Cont *self, short freeSelf)
{
  int n;
  Elem *p;
  if (self != 0) {
    n = self->size;
    p = self->begin + n;
    self->size -= n;
    while (n != 0) {
      p--;
      if (p != 0) {
        if (p != 0) {
          if (p->flags & 1) {
      void *x;
      notify(p, Tag());
      x = (void *)((int *)FUN_00003004(p))[2];
      FUN_000039b0(p);
      FUN_00000a00(x);
          }
        }
      }
      n--;
    }
    if (self->begin != 0)
      FUN_00000a00(self->begin);
    if (freeSelf > 0)
      FUN_00000a00(self);
  }
  return self;
}
