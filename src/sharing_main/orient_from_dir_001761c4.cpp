/* HSTMATCH module=hstp_trans_main.prx start=0x001761c4 end=0x001763f8 symbol=FUN_001761c4 lang=c++ */
/* Clone of src/eboot/orient_from_dir_0016a000.cpp (hstclone.py tag fm4c): addresses substituted; exact match verified; names and types await human review. */
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
float FUN_0000c6f4(float, float);
void FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float FUN_00022500(const Vec4 *, const Vec4 *);
void FUN_00022570(Vec4 *, const void *, const Vec4 *);
float FUN_00022e6c(float);
void FUN_0004d5f0(void *, const void *, float);
void FUN_0004d644(void *, const void *, float);
extern const float DAT_002cc260;
}

extern "C" void FUN_001761c4(Vec4 *out, Vec4 *p, float *pa, float *pb)
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

  float yaw = FUN_0000c6f4(p->v3.x - zero, p->v3.z - zero);
  origin = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
  dir = Vec4(p->v3.x, 0.0f, p->v3.z, 1.0f);
  FUN_0002245c(&d, &dir, &origin);
  v = d;
  float n = FUN_00022e6c(FUN_00022500(&v, &v));
  float yy = p->v3.y - zero;
  float pitch = zero == yy ? 1.5707964f : FUN_0000c6f4(n, yy);
  up.v3.y = FUN_00022e6c(FUN_00022500(p, p));
  up.v3.x = 0.0f;
  up.v3.z = 0.0f;
  up.w = 1.0f;
  FUN_0004d5f0(m, &DAT_002cc260, pitch + *pb);
  FUN_00022570(&up, m, &up);
  t = Vec4(up.v3.x, 0.0f, up.v3.z, 1.0f);
  float q = FUN_00022e6c(FUN_00022500(&t, &t));
  side = Vec4(0.0f, 0.0f, q, 1.0f);
  FUN_0004d644(m, &DAT_002cc260, yaw + *pa);
  FUN_00022570(&side, m, &side);
  up = Vec4(0.0f, up.v3.y, 0.0f, 1.0f);
  side = Vec4(side.v3.x, 0.0f, side.v3.z, 1.0f);
  FUN_00022440(&res, &side, &up);
  out->v3 = Xyz(res);
  out->w = 1.0f;
}
