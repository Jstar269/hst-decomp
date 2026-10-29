/* HSTMATCH module=EBOOT.BIN start=0x0020b7a0 end=0x0020be58 symbol=FUN_0020b7a0 lang=c++ data=0x002ef8b8 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002ef8b8-0x002ef8d1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/chara_player.h"
#include "hst/match_cfg.h"

/* Shot parameters of one shot class: curve exponent and the low/high ends of the result range. */
struct ShotParams {
  float curve;     /* 0x00 */
  short low;       /* 0x04 */
  short high;      /* 0x06 */
};

/* Parameter block; two of them (a base and a per-player one) are added together. */
struct PowerParams {
  char pad0[0x1c];
  ShotParams shots[6];   /* 0x1c */
  short code_a;          /* 0x4c */
  short code_b;          /* 0x4e */
  char pad1[0x1c8 - 0x50];
  float curve;           /* 0x1c8 */
  float low;             /* 0x1cc */
  float high;            /* 0x1d0 */
};

extern "C" {
extern float DAT_002ef878;
extern float DAT_002ef87c;
extern float DAT_002ef880;
extern float DAT_002ef884;
extern float DAT_002ef888;
extern float DAT_002ef88c;
extern float DAT_002ef890;
extern float DAT_002ef894;
extern float DAT_002ef898;
extern float DAT_002ef89c;
extern float DAT_002ef8a0;
extern float DAT_002ef8a4;
extern float DAT_002ef8a8;
extern float DAT_002ef8ac;
extern float DAT_002ef8b0;
extern float DAT_002ef8b4;
extern MatchCfg *DAT_00338b44;

extern float FUN_0000ce3c(float, float);
extern u32 FUN_0001342c(void);
extern bool FUN_000a8494(CharaPlayer *, float *);
extern int FUN_002068e8(CharaPlayer *, int, int);
extern void FUN_0020b600(const char *, ...);
extern PowerParams *FUN_00215a20(CharaPlayer *);
extern PowerParams *FUN_00215a58(...);
}

static inline float Max(const float &a, const float &b)
{
  return !(a > b) ? b : a;
}

static inline float MaxV(const float &a, float b)
{
  return !(a > b) ? b : a;
}

static inline float Min(const float &a, const float &b)
{
  return !(a > b) ? a : b;
}

static inline const int &MaxInt(const int &a, const int &b)
{
  return a < b ? b : a;
}

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Compute a shot value for shot type `type` and kind `kind`: pick the curve/low/high parameters (base plus player),
   adjust them for lob and drop counts, then interpolate by `t` (random when 0). */
extern "C" int FUN_0020b7a0(CharaPlayer *self, int type, int kind, float factor, float t)
{
  float curve;
  float low;
  float high;

  if (DAT_00338b44->value90 == 1) {
    float s1 = FUN_00215a58()->curve;
    s1 = s1 + FUN_00215a20(self)->curve;
    curve = Max(DAT_002ef878, s1);

    float s2 = FUN_00215a58(self)->low;
    s2 = s2 + FUN_00215a20(self)->low;
    low = Max(DAT_002ef87c, s2);

    float s3 = FUN_00215a58(self)->high;
    s3 = s3 + FUN_00215a20(self)->high;
    high = Max(DAT_002ef880, s3);
  }
  else {
    float vec[4];
    vec[0] = factor;
    vec[1] = factor;
    vec[2] = factor;
    vec[3] = factor;
    bool second_set = FUN_000a8494(self, vec);
    bool is_lob = (kind == 0 && type == 2);
    bool is_drop = (kind == 6);
    int idx;
    if (second_set) {
      if (is_lob) {
        idx = 4;
      }
      else if (is_drop) {
        idx = 5;
      }
      else {
        idx = 3;
      }
    }
    else {
      if (is_lob) {
        idx = 1;
      }
      else if (is_drop) {
        idx = 2;
      }
      else {
        idx = 0;
      }
    }
    float s1 = FUN_00215a58(self)->shots[idx].curve;
    s1 = s1 + FUN_00215a20(self)->shots[idx].curve;
    curve = Max(DAT_002ef884, s1);

    int low_sum = FUN_00215a58(self)->shots[idx].low + FUN_00215a20(self)->shots[idx].low;
    low = MaxV(DAT_002ef888, (float)low_sum);

    int high_sum = FUN_00215a58(self)->shots[idx].high + FUN_00215a20(self)->shots[idx].high;
    high = MaxV(DAT_002ef88c, (float)high_sum);

    if (DAT_00338b44->flag45 != 0) {
      if (is_lob) {
        low = Min(low + (float)self->lob_count, DAT_002ef890);
        high = Min(high + 0.5f * (float)self->lob_count, DAT_002ef894);
        FUN_0020b600("not lob %d\n", self->lob_count);
      }
      if (is_drop) {
        low = Min(low + 0.4f * (float)self->drop_count, DAT_002ef898);
        high = Min(high + 0.2f * (float)self->drop_count, DAT_002ef89c);
        FUN_0020b600("not drop %d\n", self->drop_count);
      }
      float sign = 0.0f;
      if (type == 1) {
        sign = self->unk854 > 0 ? -1.0f : 1.0f;
      }
      else if (type == 0) {
        sign = self->unk858 > 0 ? -1.0f : 1.0f;
      }
      float d = sign * (float)MaxInt(self->unk854, self->unk858);
      if (d != 0.0f) {
        if (d > 0.0f) {
          d = d * 0.4f;
        }
        else {
          d = d * 0.5f;
        }
        low = Clamp(low + d, DAT_002ef8a0, DAT_002ef8a4);
        high = Clamp(high + d, DAT_002ef8a8, DAT_002ef8ac);
      }
    }
  }
  int code = FUN_002068e8(self, type, kind);
  int sum_a = FUN_00215a58(self)->code_a + FUN_00215a20(self)->code_a;
  if ((float)code == MaxV(DAT_002ef8b0, (float)sum_a)) {
    curve *= 1.2f;
    low *= 0.8f;
    high *= 0.8f;
  }
  else {
    int sum_b = FUN_00215a58(self)->code_b + FUN_00215a20(self)->code_b;
    if ((float)code == MaxV(DAT_002ef8b4, (float)sum_b)) {
      curve *= 0.8f;
      low *= 1.2f;
      high *= 1.2f;
    }
  }
  if (t == 0.0f) {
    u32 rnd = FUN_0001342c();
    t = FUN_0000ce3c(4.656613e-10f * (float)(int)(rnd & 0xfffff800), curve);
  }
  return (int)(low + t * (high - low));
}
