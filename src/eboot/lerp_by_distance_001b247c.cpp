/* HSTMATCH module=EBOOT.BIN start=0x001b247c end=0x001b25bc symbol=FUN_001b247c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the default position is chosen with a ternary, the sqrt term is computed before the range subtraction, and the signature lists the pointers before the floats); names and types await human review. */
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));

extern "C" {
extern void *DAT_003313c4;
extern float DAT_002e9918;
extern float DAT_002e991c;
extern float DAT_002e9920;
Vec4 *FUN_00022434(Vec4 *, const Vec4 *, const Vec4 *);
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

extern "C" float FUN_001b247c(int unused, const Vec4 *ref, const Vec4 *pos, float a, float b, float lo, float hi)
{
  pos = pos ? pos : (const Vec4 *)((char *)DAT_003313c4 + 0x1d0);
  Vec4 d = *pos;
  Vec4 r;
  FUN_00022434(&r, &d, ref);
  float len = sqrtf(r.x * r.x + r.z * r.z);
  float range = hi - lo;
  float t = 1.0f - (len - lo) / Max(range, DAT_002e9918);
  float c = Clamp(t, DAT_002e991c, DAT_002e9920);
  return a + c * (b - a);
}
