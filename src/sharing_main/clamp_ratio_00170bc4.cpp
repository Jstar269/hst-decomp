/* HSTMATCH module=hstp_trans_main.prx start=0x00170bc4 end=0x00170c70 symbol=FUN_00170bc4 lang=c++ */
/* Hand-written reconstruction from the disassembly (the last row is addressed through a `StatCurveRow *` local, `StatCurveRow *lastRow = rows + n;`, which keeps retail's base-first addu where `rows[n].col04` gives index-first; matching idiom: the ratio is an in-place divide `f = t - first; f = f / (last - first);` as in the sibling src/eboot/clamp_ratio_001646a0.cpp; EBOOT twin of src/sharing_main/clamp_ratio_00170bc4.cpp); exact match verified; names and types await human review. */
#include "hst/stat_curve.h"

extern StatTable *DAT_003ea850; /* curve rows */
extern float DAT_0038794c;
extern float DAT_00387950;
extern "C" float FUN_0017020c(int, int, int, float, int);

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Ratio of the value between the first and last curve row, clamped to the global limits. */
extern "C" float FUN_00170bc4(int a, int b)
{
  float t = FUN_0017020c(a, b, 1, 100.0f, 0);
  StatTable *tab = DAT_003ea850;
  StatCurveRow *rows = (StatCurveRow *)tab->base;
  float first = rows[0].col04;
  int n = tab->count - 1;
  StatCurveRow *lastRow = rows + n;
  float last = lastRow->col04;
  float f = t - first;
  f = f / (last - first);
  return Clamp(f, DAT_0038794c, DAT_00387950);
}
