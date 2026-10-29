/* HSTMATCH module=EBOOT.BIN start=0x00164ac4 end=0x00164c60 symbol=FUN_00164ac4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the ratio is an in-place divide (`r = c - lo; r = r / (hi - lo);`); the clamp reads the table through a typed row (StatCurveRow) while the division uses raw offsets so the loads are not shared; `last = count - 1` kept as a local; the final clamp takes its bounds by pointer (double global load). */
#include "hst/stat_curve.h"

extern StatTable *DAT_0034150c; /* records, indexed by id */
extern StatTable *DAT_00341510; /* curve rows */
extern float DAT_002e03a8;
extern float DAT_002e03ac;
extern float FUN_000d8334(int, int);

static inline float Clamp(float v, float lo, float hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}
static inline float ClampR(float v, const float *lo, const float *hi)
{
    return v < *lo ? *lo : (!(v > *hi) ? v : *hi);
}

/* Position of the target's value along the curve, as a ratio clamped to the global limits. */
float FUN_00164ac4(int self, int target)
{
    float v;
    float c;
    float r;
    int count;
    char *base;
    int last;

    if (target != 0 && *(short *)(target + 10) / STAT_ID_GROUP_DIVISOR == STAT_GROUP_LAST) {
        count = DAT_00341510->count;
        base = DAT_00341510->base;
        last = count - 1;
        c = *(float *)(base + last * STAT_CURVE_ROW_SIZE + 0x10);
    } else {
        v = *(float *)(self + 0x58);
        if (target != 0) {
            if (*(short *)(target + 10) >= 0)
                v += *(float *)(DAT_0034150c->base +
                                DAT_0034150c->index[*(short *)(target + 10)] * STAT_RECORD_SIZE +
                                0x58);
            v += FUN_000d8334(target, 4);
        }
        count = DAT_00341510->count;
        base = DAT_00341510->base;
        last = count - 1;
        c = Clamp(v, ((StatCurveRow *)base)[0].col10, *(float *)(base + last * STAT_CURVE_ROW_SIZE + 0x10));
    }
    r = c - *(float *)(base + 0x10);
    r = r / (*(float *)(base + (count - 1) * STAT_CURVE_ROW_SIZE + 0x10) - *(float *)(base + 0x10));
    return ClampR(r, &DAT_002e03a8, &DAT_002e03ac);
}
