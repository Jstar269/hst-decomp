/* HSTMATCH module=EBOOT.BIN start=0x0015e33c end=0x0015e470 symbol=FUN_0015e33c lang=c++ */
struct Tag {};
struct Elem {
  virtual int probe(Tag t);
  virtual void release(int flag, Tag t);
};
struct Inner { int pad[5]; };

extern "C" void FUN_000009e4(void *p);
extern "C" void FUN_001602dc(void *p, int flag);
extern "C" void FUN_00000a00(void *p);
extern char DAT_0030908c[];
extern char DAT_003073ac[];

extern "C" void *FUN_0015e33c(char *self, short freeSelf)
{
  Elem **p;
  int n, m;
  if (self != 0) {
    *(char **)self = DAT_0030908c;
    n = *(int *)(self + 0x18);
    p = *(Elem ***)(self + 0x14);
    m = (p == *(Elem ***)(self + 0x14) + *(int *)(self + 0x18)) ^ 1;
    while (m) {
      Elem *e = *p;
      if (!e->probe(Tag())) {
        Elem *o = *p;
        if (o != 0) o->release(1, Tag());
      }
      p++;
      m = (p == *(Elem ***)(self + 0x14) + *(int *)(self + 0x18)) ^ 1;
    }
    *(int *)(self + 0x18) -= n;
    if (*(void **)(self + 8) != 0) {
      FUN_000009e4(*(void **)(self + 8));
      *(void **)(self + 8) = 0;
    }
    if (self + 0x14 != 0) FUN_001602dc(self + 0x14, 0);
    if (self != 0) *(char **)self = DAT_003073ac;
    if (freeSelf > 0) FUN_00000a00(self);
  }
  return self;
}
// near miss from lane dsn3 (unreviewed)
