/* HSTMATCH module=EBOOT.BIN start=0x000a82b8 end=0x000a8494 symbol=FUN_000a82b8 lang=c++ */
/* Clone of src/sharing_main/blend_factor_000aacac.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: w2/w1 declared at the top (in that order) to get retail's f21/f22 for the two scaled values; the division is duplicated into both sign branches; fabsf is the abs.s intrinsic; Min is an inline const-reference helper. */
typedef int undefined4;

extern "C" {
extern float DAT_002d46ac;
extern char DAT_00341120[];
extern int DAT_00341284;
extern int DAT_00341288;
extern float DAT_00341294;
extern float DAT_0034129c;
extern int FUN_000b3c68(int);
extern float FUN_001621c0(char *, int);
extern float FUN_0016442c(int, int);
extern float FUN_00164474(int, int);
extern float fabsf(float);
}

static inline float Min(const float &a, const float &b)
{
  return !(a > b) ? a : b;
}

extern "C" float FUN_000a82b8(float param_1, int param_2)
{
  float w2;
  float w1;
  float v = param_1 - DAT_0034129c * 0.01f;
  float res = 0.0f;
  float av = fabsf(v);
  if (av > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
    int sign;
    if (v < 0.0f) {
      sign = -1;
    } else {
      sign = 1;
    }
    float w = v - (float)sign * (FUN_001621c0(DAT_00341120, 0) * 0.01f);
    float q;
    if (w > 0.0f) {
      q = w / (DAT_00341294 * 0.01f * (float)DAT_00341284);
    } else {
      q = w / (DAT_00341294 * 0.01f * (float)DAT_00341288);
    }
    res = Min(q, DAT_002d46ac);
  }
  w1 = FUN_00164474(FUN_000b3c68(param_2), *(int *)(param_2 + 0x440)) * 0.01f;
  w2 = FUN_0016442c(FUN_000b3c68(param_2), *(int *)(param_2 + 0x440)) * 0.01f;
  return (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b3c68(param_2) + 0x2c) * 0.01f);
}
