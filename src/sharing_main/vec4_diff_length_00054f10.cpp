/* HSTMATCH module=hstp_trans_main.prx start=0x00054f10 end=0x00054fb0 symbol=FUN_00054f10 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
float FUN_00022e6c(float);
void *FUN_0002e7f8(void *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b) {
  Vec4 r;
  FUN_00022440(&r, &a, &b);
  return r;
}

static inline float Length(const Vec4 &v) {
  return FUN_00022e6c(FUN_00022500(&v, &v));
}

typedef struct Obj {
  char pad[8];
  char *f8;
} Obj;

extern "C" float FUN_00054f10(Obj *self)
{
  Vec4 v2;
  Vec4 v1;
  const Vec4 *pts = *(const Vec4 **)FUN_0002e7f8(self->f8 + 16);
  v1 = Sub(pts[0], pts[1]);
  v2 = Sub(v1, pts[2]);
  return Length(v2);
}
