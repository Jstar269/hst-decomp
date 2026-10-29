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

/* Camera: target, eye and the basis vectors derived from them. */
struct CameraObj {
  char pad00[0x90];
  Vec4 target;
  Vec4 eye;
  Vec4 forward;
  Vec4 right;
};

/* Builds the forward vector (eye to target, normalised) and the right vector from it. */
extern "C" void FUN_0012e67c(CameraObj *cam)
{
  cam->forward = Sub(cam->target, cam->eye);
  if (FUN_000224d8(&cam->forward, &cam->forward) < 1e-05f) {
    cam->forward.x = DAT_002bc430.x;
    cam->forward.y = DAT_002bc430.y;
    cam->forward.z = DAT_002bc430.z;
    cam->forward.w = DAT_002bc430.w;
  } else {
    FUN_00022518(&cam->forward, &cam->forward);
    cam->forward.w = 0.0f;
  }
  Vec4 t;
  Vec4 n;  /* negated up vector */
  n.x = -DAT_002bc420.x;
  n.y = -DAT_002bc420.y;
  n.z = -DAT_002bc420.z;
  n.w = -DAT_002bc420.w;
  t = Cross(n, cam->forward);
  FUN_00022518(&cam->right, &t);
  cam->right.w = 0.0f;
}
