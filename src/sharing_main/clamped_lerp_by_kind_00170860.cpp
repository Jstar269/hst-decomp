/* HSTMATCH module=hstp_trans_main.prx start=0x00170860 end=0x00170910 symbol=FUN_00170860 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Clamp the value from 0x1706b0 (arguments passed through) to [0x387934, 0x387938] through an inline clamp taking
   const references (gives retail's double load of each bound), map v/9 linearly from 0x3ea5d0 towards 0x3ea5cc,
   and add the bonus 0x3ea824 for kind 1 or 2. */
extern "C" {
extern float DAT_00387934; /* lower bound */
extern float DAT_00387938; /* upper bound */
extern float DAT_003ea5cc;
extern float DAT_003ea5d0;
extern float DAT_003ea824;
float FUN_001706b0(void *a, void *b);
}

inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00170860(void *a, void *b, int kind)
{
  float v = Clamp(FUN_001706b0(a, b), DAT_00387934, DAT_00387938);
  float r = DAT_003ea5d0 + (v / 9.0f) * (DAT_003ea5cc - DAT_003ea5d0);
  if (kind == 1 || kind == 2) {
    r += DAT_003ea824;
  }
  return r;
}
