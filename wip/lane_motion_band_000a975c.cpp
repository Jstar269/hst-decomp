/* HSTMATCH module=EBOOT.BIN start=0x000a975c end=0x000a9b48 symbol=FUN_000a975c lang=c++ */
extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
extern float DAT_002d46ac;
extern char DAT_00341120[];
extern int DAT_00341284;
extern int DAT_00341288;
extern float DAT_00341294;
extern float DAT_0034129c;
extern void FUN_00022434(void *dst);
extern float FUN_001621c0(char *, int);
extern float FUN_00164474(void *, int);
extern float FUN_0016442c(void *, int);
extern float fabsf(float);
}
struct Ctx {
    char pad00[0x24];
    float f24;
    char pad28[4];
    float f2c;
    char pad30[0x1ac - 0x30];
    float f1ac;
};
struct Obj {
    char pad00[0x150];
    int f150;
    char pad154[0x440 - 0x154];
    int f440;
};
extern "C" Ctx *FUN_000b3c68(void *obj);

template <typename T>
static inline const T &max(const T &a, const T &b) {
    return (a < b) ? b : a;
}

template <typename T>
static inline const T &min(const T &a, const T &b) {
    return (b < a) ? b : a;
}

static inline float Min(const float &a, const float &b)
{
  return !(a > b) ? a : b;
}

static inline bool YBand_000a975c(Obj *param_1, float y)
{
    int inband;
    if (y > -(FUN_000b3c68(param_1)->f24 * 0.01f) && y < 0.0f)
        inband = 1;
    else
        inband = 0;
    float t;
    bool r;
    if (inband == 0 &&
        (t = FUN_000b3c68(param_1)->f1ac * 0.01f,
         y > (t + 1.0f) * -(FUN_000b3c68(param_1)->f24 * 0.01f)) && y < 0.0f)
        r = true;
    else
        r = false;
    return r;
}

struct Vec4 {
    float x, y, z, w;
};

extern "C" int FUN_000a975c(Obj *param_1, int param_2, int param_3, unsigned char param_4, int param_5)
{
  if (param_5 == 1) {
    Vec4 local_10;
    Vec4 local_20;
    float v;
    float y;
    float x;
    float z;
    float res;
    float av;
    float w2;
    float w1;
    float blend;
    int ok;
    bool in2;
    FUN_00022434(&local_20);
    local_10 = local_20;
    if (param_4 == (param_1->f150 == 0)) {
      local_10.x = max(DAT_002d46a4, local_10.x);
    } else {
      local_10.x = min(DAT_002d46a8, local_10.x);
    }
    x = local_10.x;
    y = local_10.y;
    z = local_10.z;
    if (fabsf(x) < FUN_000b3c68(param_1)->f2c * 0.01f) {
      v = z - DAT_0034129c * 0.01f;
      res = 0.0f;
      av = fabsf(v);
      if (av > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
        int sign;
        float w;
        float q;
        if (v < 0.0f) {
          sign = -1;
        } else {
          sign = 1;
        }
        w = v - (float)sign * (FUN_001621c0(DAT_00341120, 0) * 0.01f);
        if (w > 0.0f) {
          q = w / (DAT_00341294 * 0.01f * (float)DAT_00341284);
        } else {
          q = w / (DAT_00341294 * 0.01f * (float)DAT_00341288);
        }
        res = Min(q, DAT_002d46ac);
      }
      w1 = FUN_00164474(FUN_000b3c68(param_1), param_1->f440) * 0.01f;
      w2 = FUN_0016442c(FUN_000b3c68(param_1), param_1->f440) * 0.01f;
      blend = (1.0f - (w2 + res * (w1 - w2))) * (FUN_000b3c68(param_1)->f2c * 0.01f);
      in2 = fabsf(x) < blend;
      if (in2) {
        ok = 0;
      } else {
        ok = 1;
      }
    } else {
      ok = 0;
    }
    if (!ok) {
      return 0;
    }
    if (YBand_000a975c(param_1, y)) {
      return 1;
    }
  }
  return 0;
}
// EBOOT NEAR MISS: 251/251 words, 10 differing words; first mismatch at +0x10c.
// Retargeted Sharing data to DAT_002d46a4/0x2d46a8/0x2d46ac, DAT_00341120,
// DAT_00341284/0x341288/0x341294/0x34129c and helpers to FUN_00022434,
// FUN_001621c0, FUN_00164474/0x0016442c, FUN_000b3c68.
// The prologue, Vec4 clamp, FPR numbering, blend arithmetic, and threshold math
// match. Remaining differences are the `bc1fl` branch target at +0x10c and the
// boolean branch tree around the blend and y-band checks near +0x2c0.
// Tried: direct flag assignments and inversions, a shared return value, early
// returns, int/bool helper returns, separate y-band helpers, and nested helper
// layouts. The best source uses a `YBand` bool helper with an int inband flag and
// a short-circuit second threshold test; the Sharing twin notes also document the
// unresolved negation branch and explain the two-helper recipe tried here.
// near miss from lane lnm2 (unreviewed)
