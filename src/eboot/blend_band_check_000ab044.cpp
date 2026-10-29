/* HSTMATCH module=EBOOT.BIN start=0x000ab044 end=0x000ab458 symbol=FUN_000ab044 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip of the Sharing twin hstp_trans_main 0x000ada38 (unreviewed) restructured by hand: the blend test is a static inline bool Inside() ending in an if/else-assigned bool r, the second part a nested inline Second() (inline_depth(8)) with an if/else-assigned bool r, joined with ||; matching idiom: if/else bool r in both helpers; exact match verified; names and types await human review. */
#pragma inline_depth(8)
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

static inline bool Inside(int obj, float *off)
{
  float v;
  float res;
  float av;
  float w2;
  float w1;
  float blend;

  v = off[2] - DAT_0034129c * 0.01f;
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
  w1 = FUN_00164474(FUN_000b3c68(obj), *(int *)(obj + 0x440)) * 0.01f;
  w2 = FUN_0016442c(FUN_000b3c68(obj), *(int *)(obj + 0x440)) * 0.01f;
  blend = (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b3c68(obj) + 0x2c) * 0.01f);
  bool r;
  if (fabsf(off[0]) < blend) {
    r = true;
  } else {
    r = false;
  }
  return r;
}

static inline bool Second(int obj, float *off)
{
  bool r;
  if (fabsf(off[0]) < *(float *)(FUN_000b3c68(obj) + 0x2c) * 0.01f && !Inside(obj, off)) {
    r = true;
  } else {
    r = false;
  }
  return r;
}

/* True when the offset is inside the blended band, or inside the plain band but not the blended one. */
extern "C" bool FUN_000ab044(int obj, float *off)
{
  return Inside(obj, off) || Second(obj, off);
}
