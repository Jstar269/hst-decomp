/* HSTMATCH module=hstp_trans_main.prx start=0x0009f31c end=0x0009f640 symbol=FUN_0009f31c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: FUN_00056008 returns a 64-byte Mat4 of which only r0 is read (gives the 128-byte frame, sret at sp+64); the second `ctx->body` is read through the identical-layout Ctx2 so MWCC does not CSE it with q; Height(q) and b->TopY() are named locals to fix evaluation order; `x >= y` / `y > x` spellings pick c.nge.s / c.ngt.s. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
  Vec4 &operator+=(const Vec4 &b);
} __attribute__((aligned(16)));

struct Mat4 {
  Vec4 r0, r1, r2, r3;
};

struct Sub10 {
  char pad[0x10];
  float f10;
};
struct Node8 {
  char pad[8];
  float y;
};
struct Link {
  Node8 *n;
};
struct Actor {
  char pad0[0xa4];
  Sub10 *fa4;
  char pad00[0xc0 - 0xa8];
  unsigned char fc0;
  char pad1[0xc4 - 0xc1];
  float fc4;
  float fc8;
  char pad2[0xd0 - 0xcc];
  float fd0;
};
struct Body {
  char pad0[0xf4];
  Link *f0f4;
  char pad1[0x108 - 0xf8];
  float f108;
  char pad2[0x128 - 0x10c];
  Link *f128;
  char pad3[0x13c - 0x12c];
  float f13c;
  float TopY() { return f0f4 ? f0f4->n->y : 0.0f; }
  float Top2Y() { return f128 ? f128->n->y : 0.0f; }
};
struct Ctx {
  char pad[0x50];
  Actor *actor;
  char pad1[4];
  Body *body;
};
struct Ctx2 {
  char pad[0x50];
  Actor *actor;
  char pad1[4];
  Body *body;
};
struct Obj {
  char pad0[0x168];
  unsigned rng;
  char pad1[0x500 - 0x16c];
  int count;
  int arg;
  char pad2[0x570 - 0x508];
  Vec4 v570;
  Vec4 v580;
  char pad3[0x5bc - 0x590];
  Ctx *ctx;
};

extern Vec4 DAT_0037aa74;
extern "C" {
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_000224c0(Vec4 *, const Vec4 *, float);
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
Mat4 FUN_00056008(Body *, const Vec4 &);
void FUN_000b52a4(float, Obj *, int, int);
void FUN_0005fe20(float, Actor *, int);
void FUN_0005ff00(float, Actor *);
void FUN_00059ac0(Body *, int, int);
void FUN_00058814(float, float, float, Body *, int, int);
}

inline Vec4 &Vec4::operator+=(const Vec4 &b)
{
  FUN_00022440(this, this, &b);
  return *this;
}
inline Vec4 operator*(const Vec4 &v, float s)
{
  Vec4 r;
  FUN_000224c0(&r, &v, s);
  return r;
}

inline float Height(Body *b) { return b ? b->f108 : 0.0f; }
inline float Top(Body *b) { return b ? b->TopY() : 0.0f; }
inline float Reach(Body *b) { return b ? b->f13c : 0.0f; }
inline float Top2(Body *b) { return b ? b->Top2Y() : 0.0f; }
inline float Dur(Actor *a) { Sub10 *s = a->fa4; return s ? s->f10 : 0.0f; }

extern "C" void FUN_0009f31c(Obj *self)
{
  Mat4 m = FUN_00056008(self->ctx->body, DAT_0037aa74);
  float len = FUN_00022e6c(FUN_00022500(&m.r0, &m.r0));
  self->v580 += self->v570 * (len * 100.0f * 0.049999997f);
  if (self->count > 0) {
    if (--self->count == 0) {
      FUN_000b52a4(0.0f, self, self->arg, 0);
      Actor *a = self->ctx->actor;
      if (a != 0) {
        FUN_0005fe20(0.0f, a, 0xe2);
        a->fc0 = 0;
        FUN_0005ff00(Dur(a), a);
      }
    }
  } else if (self->count == 0) {
    Body *q = self->ctx->body;
    float cur = Height(q);
    if (cur >= Top(q) - 15.0f) {
      Body *b = ((Ctx2 *)self->ctx)->body;
      if (b != 0) {
        float r = Reach(q);
        if (Top2(q) - 15.0f > r) {
          FUN_00059ac0(b, 1, 0);
          float t = b->TopY();
          float h = b->f108 - t;
          FUN_00058814(h, h + 15.0f, h - r, b, 0, 0xe2);
          Actor *a = self->ctx->actor;
          if (a != 0) {
            a->fc0 = 0;
            FUN_0005ff00(Dur(a), a);
          }
        }
      }
    }
  }
  Actor *a = self->ctx->actor;
  if (a->fc8 >= Dur(a)) {
    self->rng = self->rng * 0x343fd + 0x269ec3;
    if ((float)((self->rng >> 16) & 0x7fff) * (1.0f / 32768.0f) < 0.006666667f) {
      FUN_0005fe20(0.0f, self->ctx->actor, 0xe2);
      self->ctx->actor->fc0 = 0;
      FUN_0005ff00(0.0f, self->ctx->actor);
      self->ctx->actor->fd0 = self->ctx->actor->fc4;
    }
  }
}
