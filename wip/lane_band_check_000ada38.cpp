/* HSTMATCH module=hstp_trans_main.prx start=0x000ada38 end=0x000ade4c symbol=FUN_000ada38 lang=c++ */
extern "C" {
extern float DAT_0037acb4;
extern char DAT_003ea460[];
extern int DAT_003ea5c4;
extern int DAT_003ea5c8;
extern float DAT_003ea5d4;
extern float DAT_003ea5dc;
extern int FUN_000b6e80(int);
extern float FUN_0016e74c(char *, int);
extern float FUN_001709a0(int, int);
extern float FUN_001709e8(int, int);
extern float fabsf(float);
}

static inline float Min(const float &a, const float &b)
{
  return !(a > b) ? a : b;
}

extern "C" bool FUN_000ada38(int param_1, float *param_2)
{
  float v;
  float res;
  float av;
  float w2;
  float w1;
  float blend;
  bool cond1;

  v = param_2[2] - DAT_003ea5dc * 0.01f;
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
  w1 = FUN_001709e8(FUN_000b6e80(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
  w2 = FUN_001709a0(FUN_000b6e80(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
  blend = (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b6e80(param_1) + 0x2c) * 0.01f);
  cond1 = fabsf(param_2[0]) < blend;
  if (!cond1) {
    if (fabsf(param_2[0]) < *(float *)(FUN_000b6e80(param_1) + 0x2c) * 0.01f) {
      float v2;
      float res2;
      float av2;
      float w2b;
      float w1b;
      float blend2;
      bool in2;
      v2 = param_2[2] - DAT_003ea5dc * 0.01f;
      res2 = 0.0f;
      av2 = fabsf(v2);
      if (av2 > FUN_0016e74c(DAT_003ea460, 0) * 0.01f) {
        int sign;
        float w;
        float q;
        if (v2 < 0.0f) {
          sign = -1;
        } else {
          sign = 1;
        }
        w = v2 - (float)sign * (FUN_0016e74c(DAT_003ea460, 0) * 0.01f);
        if (w > 0.0f) {
          q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4);
        } else {
          q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8);
        }
        res2 = Min(q, DAT_0037acb4);
      }
      w1b = FUN_001709e8(FUN_000b6e80(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
      w2b = FUN_001709a0(FUN_000b6e80(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
      blend2 = (1.0f - (w2b + res2 * (w1b - w2b))) * (*(float *)(FUN_000b6e80(param_1) + 0x2c) * 0.01f);
      in2 = fabsf(param_2[0]) < blend2;
      if (!in2) {
        return true;
      }
    }
    return false;
  }
  return cond1;
}
// NEAR MISS (12 words, one spot): the whole function is exact (frame, FP callee-saved numbering f20=res, f21=av/w1,
// f22=v/w2 in BOTH inline expansions, bool materialisations, the branchy `bnez v0,L; nop; b END; li v0,1; L: move v0,zero`
// for the second comparison) except the trailing `andi v0,v0,0xff` that retail executes after that join (and skips
// via `bnezl v0,END; lw ra` on the first-comparison exit): ours returns the constants straight to the epilogue
// (`bnez v0,END; nop` for the first exit).
// Matching idioms: separate locals (v2, res2, ... declared in the same order) for the second expansion; w1/w2 declared
// after av (see blend_range_check_000ab274.cpp); results returned as `if (!in2) return true; ... return false;`.
// Ruled out for the missing andi: bool/uchar/int result variables (`r = !in2` folds to sltu+xori; an `r` assigned before
// the calls lives in an s-register), `Inside()||(A&&!Inside())` and inline-helper forms, unsigned char flag (sltu after jr).
