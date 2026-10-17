/* HSTMATCH module=hstp_trans_main.prx start=0x00139d0c end=0x00139df0 symbol=FUN_00139d0c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: typed Vec4/struct views, difference vector built by an inline Sub returning by value (scheduled copy), the fourth row copied field by field; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern Vec4 DAT_002cc270;
extern float DAT_00381f44;
extern float DAT_00381f48;
extern float DAT_00381f4c;
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022520(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022540(Vec4 *, const Vec4 *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}

struct Src {
  char pad00[0x90];
  Vec4 v90;
  Vec4 va0;
};

struct Dst {
  Vec4 f00;
  Vec4 f10;
  Vec4 f20;
  Vec4 f30;
  float f40, f44, f48;
};

extern "C" void FUN_00139d0c(Src *src, Dst *dst)
{
  dst->f20 = Sub(src->v90, src->va0);
  FUN_00022540(&dst->f20, &dst->f20);
  dst->f20.w = 0.0f;
  FUN_00022520(&dst->f00, &DAT_002cc270, &dst->f20);
  FUN_00022540(&dst->f00, &dst->f00);
  dst->f00.w = 0.0f;
  FUN_00022520(&dst->f10, &dst->f20, &dst->f00);
  dst->f30.x = src->va0.x;
  dst->f30.y = src->va0.y;
  dst->f30.z = src->va0.z;
  dst->f30.w = src->va0.w;
  dst->f40 = DAT_00381f44;
  dst->f44 = DAT_00381f48;
  dst->f48 = DAT_00381f4c;
}
