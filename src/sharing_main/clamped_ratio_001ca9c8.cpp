/* HSTMATCH module=hstp_trans_main.prx start=0x001ca9c8 end=0x001caa6c symbol=FUN_001ca9c8 lang=c++ */
/* Clone of src/eboot/clamped_ratio_001bcbe0.cpp (hstclone.py tag s10170158a4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* 100 * n / d clamped to [DAT_003919a0, DAT_003919a4], or 0.0f when d is 0. Matching idioms: the two sums are by-value parameters of a static inline helper that are modified and called with (0, 0) (a literal 0 + x folds away, a modified inline parameter keeps `move aN,zero; addu`), statement order n before d, and the nonzero arm first; the clamp is the const-reference Clamp of 0x113580. */
struct Obj {
  char pad0[0x40];
  int f40;
  char pad1[0xc];
  int f50;
  int f54;
};
extern float DAT_003919a0;
extern float DAT_003919a4;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

static inline float Calc(Obj *o, int n, int d)
{
  n += o->f40;
  d += o->f50 - o->f54;
  float r;
  if (d != 0) {
    r = Clamp((float)n * 100.0f / (float)d, DAT_003919a0, DAT_003919a4);
  } else {
    r = 0.0f;
  }
  return r;
}

extern "C" float FUN_001ca9c8(Obj *o)
{
  return Calc(o, 0, 0);
}
