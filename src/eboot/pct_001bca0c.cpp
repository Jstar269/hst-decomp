/* HSTMATCH module=EBOOT.BIN start=0x001bca0c end=0x001bcaa8 symbol=FUN_001bca0c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inlined float clamp helper with the upper bound test spelled !(v > hi) so MWCC emits c.ngt.s/bc1tl; readability pass; exact match verified; names and types await human review. */
#include "hst/stat_record.h"

extern float DAT_002e9d50;
extern float DAT_002e9d54;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Percentage 100 * num / den of two counters of the record, clamped to the two bounds; 0.0f when den is 0. */
extern "C" float FUN_001bca0c(StatRecord *rec)
{
  int num = 0;
  int den = 0;
  num += rec->unk28;
  den += rec->unk2c;
  if (den != 0) {
    return Clamp(100.0f * (float)num / (float)den, DAT_002e9d50, DAT_002e9d54);
  }
  return 0.0f;
}
