/* HSTMATCH module=hstp_trans_main.prx start=0x000aacac end=0x000aae88 symbol=FUN_000aacac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: w2/w1 declared at the top (in that order) to get retail's f21/f22 for the two scaled values; the division is duplicated into both sign branches; fabsf is the abs.s intrinsic; Min is an inline const-reference helper. */

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

extern "C" float FUN_000aacac(float param_1, int param_2)
{
  float w2;
  float w1;
  float v = param_1 - DAT_003ea5dc * 0.01f;
  float res = 0.0f;
  float av = fabsf(v);
  if (av > FUN_0016e74c(DAT_003ea460, 0) * 0.01f) {
    int sign;
    if (v < 0.0f) {
      sign = -1;
    } else {
      sign = 1;
    }
    float w = v - (float)sign * (FUN_0016e74c(DAT_003ea460, 0) * 0.01f);
    float q;
    if (w > 0.0f) {
      q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4);
    } else {
      q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8);
    }
    res = Min(q, DAT_0037acb4);
  }
  w1 = FUN_001709e8(FUN_000b6e80(param_2), *(int *)(param_2 + 0x440)) * 0.01f;
  w2 = FUN_001709a0(FUN_000b6e80(param_2), *(int *)(param_2 + 0x440)) * 0.01f;
  return (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b6e80(param_2) + 0x2c) * 0.01f);
}
