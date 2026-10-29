/* HSTMATCH module=EBOOT.BIN start=0x001644bc end=0x0016461c symbol=FUN_001644bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified (88/88 words).
   Sixth member of the 0x163xxx/0x164xxx clamp family, same record lookup (DAT_0034150c,
   0x22c stride) with the base at +0x50, FUN_000d8334's second argument 2 and the per-entry
   term at +0xf8, clamping against the +8 fields. New part: the clamp goes through an inline
   helper taking the three floats BY VALUE, `return v < lo ? lo : (!(v > hi) ? v : hi);` --
   the if/else-if/else form folds the final `c = v` into the same register and costs two words
   (bc1tl target and the mov.s destination). The tail is `res = 2.0f * c`, an optional scale by
   DAT_003414dc[level - 1] * 0.01f when 0 <= level - 1 < 2, then +0x2c added. Names and
   types await human review. */
#include "hst/stat_curve.h"

extern StatTable *DAT_0034150c; /* records, indexed by id */
extern StatTable *DAT_00341510; /* curve rows */
extern char *DAT_0034b5d4;
extern float DAT_003414dc[];    /* percent scale per level */
extern float FUN_000d8334(int, int);

static inline float Clamp(float v, float lo, float hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

float FUN_001644bc(int self, int level, int target)
{
    float v = *(float *)(self + 0x50);
    float lo;
    float hi;
    float c;
    float res;
    int n;

    if (target != 0) {
        if (*(short *)(target + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            DAT_0034150c->index[*(short *)(target + 10)] * STAT_RECORD_SIZE +
                            0x50);
        v += FUN_000d8334(target, 2);
        {
            int off = *(char *)(target + 0xa0) * 0x14;
            v += *(float *)(off + (int)DAT_0034b5d4 + 0xf8);
        }
    }
    lo = ((StatCurveRow *)DAT_00341510->base)->col08;
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * STAT_CURVE_ROW_SIZE + 8);
    c = Clamp(v, lo, hi);
    res = 2.0f * c;
    n = level - 1;
    if (n >= 0 && (unsigned)n < STAT_LEVEL_COUNT)
        res = res * (DAT_003414dc[n] * 0.01f);
    return *(float *)(self + 0x2c) + res;
}
