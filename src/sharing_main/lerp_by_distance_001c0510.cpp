/* HSTMATCH module=hstp_trans_main.prx start=0x001c0510 end=0x001c0650 symbol=FUN_001c0510 lang=c++ */
/* Clone of src/eboot/lerp_by_distance_001b247c.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the default position is chosen with a ternary, the sqrt term is computed before the range subtraction, and the signature lists the pointers before the floats); names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern void *DAT_003da704;
extern float DAT_00391430;
extern float DAT_00391434;
extern float DAT_00391438;
Vec4 *FUN_0002245c(Vec4 *, const Vec4 *, const Vec4 *);
float sqrtf(float);
}

static inline const float &Max(const float &a, const float &b)
{
  return a < b ? b : a;
}

static inline float Clamp(const float &value, const float &lo, const float &hi)
{
  return value < lo ? lo : (!(value > hi) ? value : hi);
}

extern "C" float FUN_001c0510(int unused, const Vec4 *ref, const Vec4 *pos, float a, float b, float lo, float hi)
{
  pos = pos ? pos : (const Vec4 *)((char *)DAT_003da704 + 0x1d0);
  Vec4 d = *pos;
  Vec4 r;
  FUN_0002245c(&r, &d, ref);
  float len = sqrtf(r.x * r.x + r.z * r.z);
  float range = hi - lo;
  float t = 1.0f - (len - lo) / Max(range, DAT_00391430);
  float c = Clamp(t, DAT_00391434, DAT_00391438);
  return a + c * (b - a);
}
