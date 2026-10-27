/* HSTMATCH module=hstp_trans_main.prx start=0x001caa6c end=0x001cab4c symbol=FUN_001caa6c lang=c++ */
/* Hand-written reconstruction from the disassembly (ratio of the fields at +0x44/+0x48 clamped to [DAT_003919a8, DAT_003919ac], 0.0f when the divisor is 0, then 100 * ratio clamped to [DAT_003919b0, DAT_003919b4]; matching idiom: the two zero-initialised `+=` accumulators of the src/sharing_main/pct_001ca7f4.cpp family keep retail's `move aN,zero; addu`; the clamps are the const-reference Clamp of 0x113580); exact match verified; names and types await human review. */
struct Obj {
  char pad0[0x44];
  int f44;
  int f48;
};
extern float DAT_003919a8;
extern float DAT_003919ac;
extern float DAT_003919b0;
extern float DAT_003919b4;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001caa6c(Obj *o)
{
  int n = 0;
  int d = 0;
  n += o->f44;
  d += o->f48;
  float r = 0.0f;
  if (d != 0)
    r = Clamp((float)n / (float)d, DAT_003919a8, DAT_003919ac);
  return Clamp(100.0f * r, DAT_003919b0, DAT_003919b4);
}
