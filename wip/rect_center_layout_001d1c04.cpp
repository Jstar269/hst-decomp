/* HSTMATCH module=EBOOT.BIN start=0x001d1c04 end=0x001d1e6c symbol=FUN_001d1c04 lang=c++ */
struct Rect {
  short pad0;
  short pad1;
  short x0;
  short y0;
  short x1;
  short y1;
};

struct PartVt {
  virtual void fn0();
  virtual void fn1();
  virtual void fn2();
  virtual void fn3();
  virtual void fn4();
  virtual void fn5();
  virtual void fn6();
  virtual void fn7();
  virtual void fn8();
  virtual void fn9();
  virtual void fn10();
};

struct Part : PartVt {
  char pad0[0xd8];
  int count;
};

struct Self {
  char pad0[0x54];
  unsigned char f54;
  unsigned char f55;
  char pad1[2];
  Part *f58;
  int f5c;
  char pad2[0xc];
  int f6c[2];
  int f70[2];
  short f74[2];
  short f78[2];
  float f7c[2];
};

extern int DAT_002cfc8c;
extern "C" void FUN_00103540(float);
extern "C" void FUN_001037c8(Self *, int);
extern "C" void FUN_0001dfe8(int, int);
extern "C" void FUN_0001e23c(int, int, int);
extern "C" void FUN_00103628(Self *, int);
extern "C" void FUN_000ffca4(int);
extern "C" void FUN_001d1bf0(int);
extern "C" int FUN_001d6240(int);
extern "C" void FUN_001d1f94(int, int);
extern "C" char *FUN_001d1f80(Self *, int);
extern "C" void FUN_00103480(Self *);

extern "C" void FUN_001d1c04(Self *self)
{
  FUN_00103540(1010.0f);
  FUN_001037c8(self, -1);
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  if (self->f58 != 0) {
    self->f58->fn10();
  }
  self->f54 = 1;
  self->f55 = 0;
  FUN_00103628(self, 0);
  self->f58->fn1();
  int n = self->f58->count;
  int i = 0;
  do {
    FUN_000ffca4(self->f6c[i]);
    float s = i == n ? 1.0f : 1.7f;
    self->f7c[i] = s;
    Rect *r = (Rect *)self->f6c[i];
    r->x0 = (short)(r->x0 * s);
    r->x1 = (short)(r->x1 * s);
    r->y0 = (short)(r->y0 * s);
    r->y1 = (short)(r->y1 * s);
    short half = (short)(r->x1 - r->x0);
    half = half / 2;
    short old = r->x0;
    short nx = (short)(self->f74[i] - half);
    r->x0 = nx;
    r->x1 = (short)(r->x1 + (short)(nx - old));
    short hh = (short)(r->y1 - r->y0);
    hh = hh / 2;
    short oldy = r->y0;
    short ny = (short)(self->f78[i] - hh);
    r->y0 = ny;
    r->y1 = (short)(r->y1 + (short)(ny - oldy));
    i++;
  } while (i < 2);
  self->f5c = 0;
  FUN_001d1bf0((int)self->f58);
  int v = FUN_001d6240(self->f6c[0]);
  FUN_001d1f94(self->f70[0], v);
  char *p = FUN_001d1f80(self, 0);
  *(float *)(p + 0x60) = -480.0f;
  FUN_00103480(self);
}
// NEAR MISS 2026-10-22: 150/154 words, 127 differ (ours | retail); one exploratory compile.
// Structure recovered: 1010.0f timer set, FUN_001037c8(self,-1), the two DAT_002cfc8c mode calls,
// vtable slot 10 on self->f58 (0x30), f54=1 / f55=0, FUN_00103628(self,0), vtable slot 2, then the
// two-iteration loop over self+0x6c/0x70 (rect pointers) and self+0x74/0x78 (target centres) that
// scales the four shorts by 1.7f (1.0f on the last index) and re-centres x0/x1, y0/y1, then
// f5c=0, FUN_001d1bf0(f58), FUN_001d6240(f6c[0]), FUN_001d1f94(f70[0],v), FUN_001d1f80(self,0)
// storing -480.0f at +0x60 and FUN_00103480(self).
// Still off: the short arithmetic (retail keeps `seh` pairs and the halving is `(d<0?d+1:d)>>1`,
// written here as a plain /2), the loop IV registers (s2=s4+4, s1=s4+2 vs retail's copy of self)
// and the `Rect*` load ordering, so the whole body is shifted from +0x0.
// near miss from lane fm4 (unreviewed)
