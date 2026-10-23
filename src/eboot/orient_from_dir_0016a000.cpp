/* HSTMATCH module=EBOOT.BIN start=0x0016a000 end=0x0016a234 symbol=FUN_0016a000 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec3 {
  float x, y, z;
};

struct Vec4 {
  Vec3 v3;
  float w;
  Vec4() {}
  Vec4(float a, float b, float c, float d)
  {
    v3.x = a;
    v3.y = b;
    v3.z = c;
    w = d;
  }
};

static inline Vec3 Xyz(const Vec4 &v) { return v.v3; }

extern "C" {
float FUN_0000c6dc(float, float);
void FUN_00022418(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_000224d8(const Vec4 *, const Vec4 *);
void FUN_00022548(Vec4 *, const void *, const Vec4 *);
float FUN_00022e44(float);
void FUN_0004d278(void *, const void *, float);
void FUN_0004d2cc(void *, const void *, float);
extern const float DAT_002bc410;
}

extern "C" void FUN_0016a000(Vec4 *out, Vec4 *p, float *pa, float *pb)
{
  float zero = 0.0f;
  Vec4 side;
  Vec4 up;
  float m[16];
  Vec4 t;
  Vec4 v;
  Vec4 dir;
  Vec4 origin;
  Vec4 d;
  Vec4 res;

  float yaw = FUN_0000c6dc(p->v3.x - zero, p->v3.z - zero);
  origin = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
  dir = Vec4(p->v3.x, 0.0f, p->v3.z, 1.0f);
  FUN_00022434(&d, &dir, &origin);
  v = d;
  float n = FUN_00022e44(FUN_000224d8(&v, &v));
  float yy = p->v3.y - zero;
  float pitch = zero == yy ? 1.5707964f : FUN_0000c6dc(n, yy);
  up.v3.y = FUN_00022e44(FUN_000224d8(p, p));
  up.v3.x = 0.0f;
  up.v3.z = 0.0f;
  up.w = 1.0f;
  FUN_0004d278(m, &DAT_002bc410, pitch + *pb);
  FUN_00022548(&up, m, &up);
  t = Vec4(up.v3.x, 0.0f, up.v3.z, 1.0f);
  float q = FUN_00022e44(FUN_000224d8(&t, &t));
  side = Vec4(0.0f, 0.0f, q, 1.0f);
  FUN_0004d2cc(m, &DAT_002bc410, yaw + *pa);
  FUN_00022548(&side, m, &side);
  up = Vec4(0.0f, up.v3.y, 0.0f, 1.0f);
  side = Vec4(side.v3.x, 0.0f, side.v3.z, 1.0f);
  FUN_00022418(&res, &side, &up);
  out->v3 = Xyz(res);
  out->w = 1.0f;
}
