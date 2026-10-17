/* HSTMATCH module=hstp_trans_main.prx start=0x000ac150 end=0x000ac53c symbol=FUN_000ac150 lang=c++ */
extern "C" {
extern const float DAT_0037acac;
extern const float DAT_0037acb0;
extern float DAT_0037acb4;
extern char DAT_003ea460[];
extern int DAT_003ea5c4;
extern int DAT_003ea5c8;
extern float DAT_003ea5d4;
extern float DAT_003ea5dc;
extern void FUN_0002245c(void *dst);
extern float FUN_0016e74c(char *, int);
extern float FUN_001709a0(void *, int);
extern float FUN_001709e8(void *, int);
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
extern "C" Ctx *FUN_000b6e80(void *obj);

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

struct Vec4 {
    float x, y, z, w;
};

extern "C" int FUN_000ac150(Obj *param_1, int param_2, int param_3, unsigned char param_4, int param_5)
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
    FUN_0002245c(&local_20);
    local_10 = local_20;
    if (param_4 == (param_1->f150 == 0)) {
      local_10.x = max(DAT_0037acac, local_10.x);
    } else {
      local_10.x = min(DAT_0037acb0, local_10.x);
    }
    x = local_10.x;
    y = local_10.y;
    z = local_10.z;
    if (fabsf(x) < FUN_000b6e80(param_1)->f2c * 0.01f) {
      v = z - DAT_003ea5dc * 0.01f;
      res = 0.0f;
      av = fabsf(v);
      if (av > FUN_0016e74c(DAT_003ea460, 0) * 0.01f) {
        int sign;
        float w;
        float q;
        if (v < 0.0f) {
          sign = -1;
        } else {
          sign = 1;
        }
        w = v - (float)sign * (FUN_0016e74c(DAT_003ea460, 0) * 0.01f);
        if (w > 0.0f) {
          q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4);
        } else {
          q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8);
        }
        res = Min(q, DAT_0037acb4);
      }
      w1 = FUN_001709e8(FUN_000b6e80(param_1), param_1->f440) * 0.01f;
      w2 = FUN_001709a0(FUN_000b6e80(param_1), param_1->f440) * 0.01f;
      blend = (1.0f - (w2 + res * (w1 - w2))) * (FUN_000b6e80(param_1)->f2c * 0.01f);
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
    int inband;
    if (y > -(FUN_000b6e80(param_1)->f24 * 0.01f) && y < 0.0f) {
      inband = 1;
    } else {
      inband = 0;
    }
    if (inband) {
      ok = 0;
    } else {
      float t = FUN_000b6e80(param_1)->f1ac * 0.01f;
      if (y > (t + 1.0f) * -(FUN_000b6e80(param_1)->f24 * 0.01f) && y < 0.0f) {
        ok = 1;
      } else {
        ok = 0;
      }
    }
    if (ok) {
      return 1;
    }
  }
  return 0;
}
// NOT MATCHED (57 words; kept as a starting point). Exact so far: prologue, the Vec4 clamp, FP callee-saved numbering
// (f20 res, f21 x, f22 y, f23 z/v/w1, f24 av/w2: z must be a local read right after y), the whole blend arithmetic,
// the f1ac*0.01f temporary (`float t = ...->f1ac * 0.01f;` computed before the second getter call), `int` flags with
// positive `y > thr && y < 0.0f` conditions (as in float_band_check_000ac714.cpp).
// Open: the `ok` flag (`bnez v0,L; nop; b END; li v0,1; L: move v0,zero` then `beqzl v0,END; move v0,zero`) comes out as
// likely-branch `beqzl; li; move` + `bnezl ...; b END`, the same unsolved negation as wip/lane_band_check_000ada38.cpp.
