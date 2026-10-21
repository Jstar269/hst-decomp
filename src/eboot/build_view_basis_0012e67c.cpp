/* HSTMATCH module=EBOOT.BIN start=0x0012e67c end=0x0012e7b4 symbol=FUN_0012e67c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of src/eboot/build_basis_0012e7b4.cpp (same Vec4 style). Matching idiom: t is declared before n (frame slots are given in declaration order from the frame top), t assigned afterwards. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern Vec4 DAT_002bc420;
extern Vec4 DAT_002bc430;
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
Vec4 *FUN_000224f8(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022518(Vec4 *, const Vec4 *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022434(&r, &a, &b);
  return r;
}

static inline Vec4 Cross(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_000224f8(&r, &a, &b);
  return r;
}

struct Obj {
  char pad00[0x90];
  Vec4 v90;
  Vec4 va0;
  Vec4 vb0;
  Vec4 vc0;
};

extern "C" void FUN_0012e67c(Obj *o)
{
  o->vb0 = Sub(o->v90, o->va0);
  if (FUN_000224d8(&o->vb0, &o->vb0) < 1e-05f) {
    o->vb0.x = DAT_002bc430.x;
    o->vb0.y = DAT_002bc430.y;
    o->vb0.z = DAT_002bc430.z;
    o->vb0.w = DAT_002bc430.w;
  } else {
    FUN_00022518(&o->vb0, &o->vb0);
    o->vb0.w = 0.0f;
  }
  Vec4 t;
  Vec4 n;
  n.x = -DAT_002bc420.x;
  n.y = -DAT_002bc420.y;
  n.z = -DAT_002bc420.z;
  n.w = -DAT_002bc420.w;
  t = Cross(n, o->vb0);
  FUN_00022518(&o->vc0, &t);
  o->vc0.w = 0.0f;
}
