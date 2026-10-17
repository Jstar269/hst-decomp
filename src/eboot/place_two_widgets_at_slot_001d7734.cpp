/* HSTMATCH module=EBOOT.BIN start=0x001d7734 end=0x001d7a14 symbol=FUN_001d7734 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: `!((lt != 0) ^ 1)` on a precomputed int `lt = st < 3` (a plainer `if (!b && lt)` or `b || st >= 3` changes the
   first call's layout); `bool` second parameter of FUN_000ffb3c (an int parameter adds an `andi a1,v0,0xff`); the second slot
   pointer's centre is `(short)(int)((float)cy2 + 30.0f)`. Same CenterX/MidX helpers as src/eboot/recenter_rects_0026b2f0.cpp. */
struct Rect {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
};

struct Sub { int x; };

struct Self {
  char pad0[0x54];
  unsigned state;
  char pad1[0x6c - 0x58];
  Rect *rects[26];
  int cur;
  char pad2[0x17c - 0xd8];
  Rect *w1;
  Sub sub;
  Rect *w2;
  char pad3[0x51c - 0x188];
  int count;
};

struct Mgr { char pad[0x80]; char sub[1]; };
extern Mgr *DAT_003415a8;

extern "C" bool FUN_0026ef04();
extern "C" int FUN_0026f4e4(void *);
extern "C" void FUN_000ffb3c(Rect *, bool);
extern "C" void FUN_0027fc70(Sub *, Rect *, int);

static inline short Width(const Rect *r) { return r->x1 - r->x0; }
static inline short Height(const Rect *r) { return r->y1 - r->y0; }
static inline short MidX(const Rect *r) { return (r->x0 + r->x1) / 2; }
static inline short MidY(const Rect *r) { return (r->y0 + r->y1) / 2; }

static inline void CenterX(Rect *r, short c)
{
  int w = Width(r);
  short nx = c - w / 2;
  short ox = r->x0;
  r->x0 = nx;
  r->x1 += nx - ox;
}

static inline void CenterY(Rect *r, short c)
{
  int h = Height(r);
  short ny = c - h / 2;
  short oy = r->y0;
  r->y0 = ny;
  r->y1 += ny - oy;
}

static inline void CenterAt(Rect *r, short cx, short cy)
{
  CenterX(r, cx);
  CenterY(r, cy);
}

extern "C" void FUN_001d7734(Self *self)
{
  bool b = !(FUN_0026ef04() != 0);
  unsigned st = self->state;
  bool show = true;
  int lt = st < 3;
  if (!b) { if (!((lt != 0) ^ 1)) show = false; }
  FUN_000ffb3c(self->w1, show);
  int idx = (self->count + 3 - self->cur) % self->count;
  Rect *r = self->rects[idx];
  short cy = r->y0 + 3;
  short cx = MidX(r);
  CenterAt(self->w1, cx, cy);
  FUN_0027fc70(&self->sub, self->w1, 1);
  bool c = false;
  if (b) {
    if (FUN_0026f4e4(DAT_003415a8->sub) != 0) c = true;
  }
  bool s = false;
  if (self->state < 6 && ((1 << self->state) & 0x29)) s = true;
  FUN_000ffb3c(self->w2, !(c && s) || idx != 0);
  r = self->rects[idx];
  short cy2 = MidY(r);
  short cx2 = MidX(r);
  CenterAt(self->w2, cx2, (short)(int)((float)cy2 + 30.0f));
}
