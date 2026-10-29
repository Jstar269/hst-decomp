/* HSTMATCH module=EBOOT.BIN start=0x001bcb44 end=0x001bcbe0 symbol=FUN_001bcb44 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Third member of the pct_001bca0c family: ratio from the object's fields at +0x38/+0x3c, bounds in
   DAT_002e9d60/DAT_002e9d64.  Same inlined clamp, same zeroed `num +=`/`den +=` accumulators. */
#include "hst/stat_record.h"

extern float DAT_002e9d60;
extern float DAT_002e9d64;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Percentage 100 * num / den of two counters of the record, clamped to the two bounds; 0.0f when den is 0. */
extern "C" float FUN_001bcb44(StatRecord *rec)
{
  int num = 0;
  int den = 0;
  num += rec->unk38;
  den += rec->unk3c;
  if (den != 0) {
    return Clamp(100.0f * (float)num / (float)den, DAT_002e9d60, DAT_002e9d64);
  }
  return 0.0f;
}
