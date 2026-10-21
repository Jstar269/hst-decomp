/* HSTMATCH module=hstp_trans_main.prx start=0x00139bd4 end=0x00139d0c symbol=FUN_00139bd4 lang=c++ */
/* Clone of src/eboot/build_view_basis_0012e67c.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of src/eboot/build_basis_0012e7b4.cpp (same Vec4 style). Matching idiom: t is declared before n (frame slots are given in declaration order from the frame top), t assigned afterwards. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern Vec4 DAT_002cc270;
extern Vec4 DAT_002cc280;
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
Vec4 *FUN_00022520(Vec4 *, const Vec4 *, const Vec4 *);
Vec4 *FUN_00022540(Vec4 *, const Vec4 *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_0002245c(&r, &a, &b);
  return r;
}

static inline Vec4 Cross(const Vec4 &a, const Vec4 &b)
{
  Vec4 r;
  FUN_00022520(&r, &a, &b);
  return r;
}

struct Obj {
  char pad00[0x90];
  Vec4 v90;
  Vec4 va0;
  Vec4 vb0;
  Vec4 vc0;
};

extern "C" void FUN_00139bd4(Obj *o)
{
  o->vb0 = Sub(o->v90, o->va0);
  if (FUN_00022500(&o->vb0, &o->vb0) < 1e-05f) {
    o->vb0.x = DAT_002cc280.x;
    o->vb0.y = DAT_002cc280.y;
    o->vb0.z = DAT_002cc280.z;
    o->vb0.w = DAT_002cc280.w;
  } else {
    FUN_00022540(&o->vb0, &o->vb0);
    o->vb0.w = 0.0f;
  }
  Vec4 t;
  Vec4 n;
  n.x = -DAT_002cc270.x;
  n.y = -DAT_002cc270.y;
  n.z = -DAT_002cc270.z;
  n.w = -DAT_002cc270.w;
  t = Cross(n, o->vb0);
  FUN_00022540(&o->vc0, &t);
  o->vc0.w = 0.0f;
}
