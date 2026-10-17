/* HSTMATCH module=EBOOT.BIN start=0x001bcbe0 end=0x001bcc84 symbol=FUN_001bcbe0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* 100 * n / d clamped to [DAT_002e9d68, DAT_002e9d6c], or 0.0f when d is 0. Matching idioms: the two sums are by-value parameters of a static inline helper that are modified and called with (0, 0) (a literal 0 + x folds away, a modified inline parameter keeps `move aN,zero; addu`), statement order n before d, and the nonzero arm first; the clamp is the const-reference Clamp of 0x113580. */
struct Obj {
  char pad0[0x40];
  int f40;
  char pad1[0xc];
  int f50;
  int f54;
};
extern float DAT_002e9d68;
extern float DAT_002e9d6c;

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
    r = Clamp((float)n * 100.0f / (float)d, DAT_002e9d68, DAT_002e9d6c);
  } else {
    r = 0.0f;
  }
  return r;
}

extern "C" float FUN_001bcbe0(Obj *o)
{
  return Calc(o, 0, 0);
}
