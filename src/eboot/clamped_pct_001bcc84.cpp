/* HSTMATCH module=EBOOT.BIN start=0x001bcc84 end=0x001bcd64 symbol=FUN_001bcc84 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/clamped_pct_001caa6c.cpp: ratio of the fields at +0x44/+0x48 (num/den) clamped to [DAT_002e9d70, DAT_002e9d74], 0.0f when the divisor is 0, then 100 * ratio clamped to [DAT_002e9d78, DAT_002e9d7c]; matching idiom: the two zero-initialised `+=` accumulators of the src/eboot/pct_001bca0c.cpp family keep retail's `move aN,zero; addu`; the clamps are the const-reference Clamp of 0x113580); exact match verified; names and types await human review. */
#include "hst/stat_record.h"

extern float DAT_002e9d70;
extern float DAT_002e9d74;
extern float DAT_002e9d78;
extern float DAT_002e9d7c;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
  return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Ratio of two counters of the record, clamped, then scaled to a percentage and clamped again. */
extern "C" float FUN_001bcc84(StatRecord *rec)
{
  int num = 0;
  int den = 0;
  num += rec->unk44;
  den += rec->unk48;
  float ratio = 0.0f;
  if (den != 0)
    ratio = Clamp((float)num / (float)den, DAT_002e9d70, DAT_002e9d74);
  return Clamp(100.0f * ratio, DAT_002e9d78, DAT_002e9d7c);
}
