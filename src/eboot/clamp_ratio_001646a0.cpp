/* HSTMATCH module=EBOOT.BIN start=0x001646a0 end=0x00164740 symbol=FUN_001646a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Matching idiom: the ratio must be an IN-PLACE divide of a variable that already holds
// the numerator (`float f = t - first; f = f / (last - first);`). The one-expression
// spelling `(t - first) / (last - first)` puts the numerator in the dead call-result FPR
// and swaps $f2/$f3 (4 words off).
#include "hst/stat_curve.h"

extern StatTable *DAT_00341510; // curve rows
extern float DAT_002e0388;
extern float DAT_002e038c;
extern "C" float FUN_00163aac();

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

// Ratio of the value between the first and last curve row, clamped to the global limits.
extern "C" float FUN_001646a0()
{
  float t = FUN_00163aac();
  StatTable *tab = DAT_00341510;
  StatCurveRow *rows = (StatCurveRow *)tab->base;
  float first = rows[0].col00;
  int n = tab->count - 1;
  float last = rows[n].col00;
  float f = t - first;
  f = f / (last - first);
  return Clamp(f, DAT_002e0388, DAT_002e038c);
}
