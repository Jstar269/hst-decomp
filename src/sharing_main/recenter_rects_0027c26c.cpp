/* HSTMATCH module=hstp_trans_main.prx start=0x0027c26c end=0x0027c50c symbol=FUN_0027c26c lang=c++ */
/* Clone of src/eboot/recenter_rects_0026b2f0.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Rect {
  char pad[4];
  short x0;
  short y0;
  short x1;
  short y1;
};

struct Inner {
  char pad[0x60];
  float v;
};

struct Obj {
  char pad0[4];
  Inner **inner;
  char pad1[0x54];
  int mode;
  char pad2[0x40];
  Rect *ra;
  Rect *rc;
  char pad3[4];
  Rect *rb;
  Rect *rd;
  char pad4[2];
  short xa;
  short xb;
};

extern "C" float fabsf(float);
extern "C" void FUN_00108dac(Obj *);
extern "C" void FUN_0027aa2c(Obj *, int);

static inline short Width(const Rect *r) { return r->x1 - r->x0; }
static inline short MidX(const Rect *r) { return (r->x0 + r->x1) / 2; }

static inline void CenterX(Rect *r, short c)
{
  int w = Width(r);
  short nx = c - w / 2;
  short ox = r->x0;
  r->x0 = nx;
  r->x1 += nx - ox;
}

static inline short StepToward(const Rect *r, short target)
{
  short c = MidX(r);
  short t = (short)((float)(target - c) * 0.5f);
  if (t < 1) c += 1; else c += t;
  return c;
}

extern "C" void FUN_0027c26c(Obj *self)
{
  short c = StepToward(self->ra, self->xa);
  CenterX(self->ra, c);
  CenterX(self->rb, c);

  short c2 = StepToward(self->rc, self->xb);
  CenterX(self->rc, c2);
  CenterX(self->rd, c2);

  float f = (*self->inner)->v;
  f = f + -f * 0.5f;
  if (fabsf(f) < 1.0f) f = 0.0f;
  (*self->inner)->v = f;
  FUN_00108dac(self);
  if (self->xb - c2 <= 0) {
    if (self->mode == 1) FUN_0027aa2c(self, 4);
    else FUN_0027aa2c(self, 7);
  }
}
