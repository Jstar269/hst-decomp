/* HSTMATCH module=EBOOT.BIN start=0x000543c4 end=0x00054464 symbol=FUN_000543c4 lang=c++ */
/* Clone of src/sharing_main/vec4_diff_length_00054f10.cpp (hstclone.py tag u5fr2e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
Vec4 *FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
float FUN_00022e44(float);
void *FUN_0002e7d0(void *);
}

static inline Vec4 Sub(const Vec4 &a, const Vec4 &b) {
  Vec4 r;
  FUN_00022418(&r, &a, &b);
  return r;
}

static inline float Length(const Vec4 &v) {
  return FUN_00022e44(FUN_000224d8(&v, &v));
}

typedef struct Obj {
  char pad[8];
  char *f8;
} Obj;

extern "C" float FUN_000543c4(Obj *self)
{
  Vec4 v2;
  Vec4 v1;
  const Vec4 *pts = *(const Vec4 **)FUN_0002e7d0(self->f8 + 16);
  v1 = Sub(pts[0], pts[1]);
  v2 = Sub(v1, pts[2]);
  return Length(v2);
}
