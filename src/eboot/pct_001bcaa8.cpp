/* HSTMATCH module=EBOOT.BIN start=0x001bcaa8 end=0x001bcb44 symbol=FUN_001bcaa8 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Twin of pct_001bca0c.cpp with the ratio taken from the object's fields at +0x30/+0x34 instead of
   the +0x28/+0x2c globals pair; same inlined clamp (upper test spelled !(v > hi) for c.ngt.s/bc1tl)
   and the same `int num = 0; num += ...;` zeroed accumulators that make MWCC emit `move a1,zero;
   move a2,zero; addu`. */
#include "hst/stat_record.h"

extern float DAT_002e9d58;
extern float DAT_002e9d5c;

static inline float Clamp(float v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Percentage 100 * num / den of two counters of the record, clamped to the two bounds; 0.0f when den is 0. */
extern "C" float FUN_001bcaa8(StatRecord *rec)
{
  int num = 0;
  int den = 0;
  num += rec->unk30;
  den += rec->unk34;
  if (den != 0) {
    return Clamp(100.0f * (float)num / (float)den, DAT_002e9d58, DAT_002e9d5c);
  }
  return 0.0f;
}
