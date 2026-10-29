/* HSTMATCH module=EBOOT.BIN start=0x00164740 end=0x001647ec symbol=FUN_00164740 lang=c++ */
/* Hand-written reconstruction from the disassembly (the last row is addressed through a `StatCurveRow *` local, `StatCurveRow *lastRow = rows + n;`, which keeps retail's base-first addu where `rows[n].col04` gives index-first; matching idiom: the ratio is an in-place divide `f = t - first; f = f / (last - first);` as in the sibling src/eboot/clamp_ratio_001646a0.cpp; EBOOT twin of src/sharing_main/clamp_ratio_00170bc4.cpp); exact match verified; names and types await human review. */
#include "hst/stat_curve.h"

extern StatTable *DAT_00341510; /* curve rows */
extern float DAT_002e0390;
extern float DAT_002e0394;
extern "C" float FUN_00163bec(int, int, int, float, int);

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Ratio of the value between the first and last curve row, clamped to the global limits. */
extern "C" float FUN_00164740(int a, int b)
{
  float t = FUN_00163bec(a, b, 1, 100.0f, 0);
  StatTable *tab = DAT_00341510;
  StatCurveRow *rows = (StatCurveRow *)tab->base;
  float first = rows[0].col04;
  int n = tab->count - 1;
  StatCurveRow *lastRow = rows + n;
  float last = lastRow->col04;
  float f = t - first;
  f = f / (last - first);
  return Clamp(f, DAT_002e0390, DAT_002e0394);
}
