/* HSTMATCH module=EBOOT.BIN start=0x000c7ed0 end=0x000c7fc0 symbol=FUN_000c7ed0 lang=c++ */
struct Tag {};
struct Obj { virtual void release(int flag, Tag t); };

extern "C" void FUN_000c7ed0(char *self)
{
  Obj **p;
  int n, i, m;
  *(int *)(self + 0x154) = 0;
  *(int *)(self + 0x158) = 0;
  *(int *)(self + 0x15c) = 0;
  *(int *)(self + 0x160) = 0;
  n = *(int *)(self + 0x1b8);
  p = *(Obj ***)(self + 0x1b4);
  m = (p == *(Obj ***)(self + 0x1b4) + *(int *)(self + 0x1b8)) ^ 1;
  while (m) {
    Obj *o = *p;
    if (o != 0) {
      o->release(1, Tag());
      *p = 0;
    }
    p++;
    m = (p == *(Obj ***)(self + 0x1b4) + *(int *)(self + 0x1b8)) ^ 1;
  }
  *(int *)(self + 0x1b8) -= n;
  for (i = 0; i < 10; i++) {
    Obj *o = *(Obj **)(self + 0x18c + i * 4);
    if (o != 0) {
      o->release(1, Tag());
      *(Obj **)(self + 0x18c + i * 4) = 0;
    }
  }
}
// near miss from lane dsn3 (unreviewed)
