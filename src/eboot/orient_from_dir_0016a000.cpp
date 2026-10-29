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

/* Rebuilds a vector of the same length as pos with its pitch and yaw shifted by *pitch_add and *yaw_add. */
extern "C" void FUN_0016a000(Vec4 *out, Vec4 *pos, float *yaw_add, float *pitch_add)
{
  float zero = 0.0f;
  Vec4 side;
  Vec4 up;
  float rot[16];
  Vec4 t;
  Vec4 v;
  Vec4 dir;
  Vec4 origin;
  Vec4 d;
  Vec4 res;

  float yaw = FUN_0000c6dc(pos->v3.x - zero, pos->v3.z - zero);
  origin = Vec4(0.0f, 0.0f, 0.0f, 0.0f);
  dir = Vec4(pos->v3.x, 0.0f, pos->v3.z, 1.0f);
  FUN_00022434(&d, &dir, &origin);
  v = d;
  float horiz_len = FUN_00022e44(FUN_000224d8(&v, &v));
  float dy = pos->v3.y - zero;
  float pitch = zero == dy ? 1.5707964f : FUN_0000c6dc(horiz_len, dy);
  up.v3.y = FUN_00022e44(FUN_000224d8(pos, pos));
  up.v3.x = 0.0f;
  up.v3.z = 0.0f;
  up.w = 1.0f;
  FUN_0004d278(rot, &DAT_002bc410, pitch + *pitch_add);
  FUN_00022548(&up, rot, &up);
  t = Vec4(up.v3.x, 0.0f, up.v3.z, 1.0f);
  float side_len = FUN_00022e44(FUN_000224d8(&t, &t));
  side = Vec4(0.0f, 0.0f, side_len, 1.0f);
  FUN_0004d2cc(rot, &DAT_002bc410, yaw + *yaw_add);
  FUN_00022548(&side, rot, &side);
  up = Vec4(0.0f, up.v3.y, 0.0f, 1.0f);
  side = Vec4(side.v3.x, 0.0f, side.v3.z, 1.0f);
  FUN_00022418(&res, &side, &up);
  out->v3 = Xyz(res);
  out->w = 1.0f;
}
