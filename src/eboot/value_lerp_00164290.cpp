/* HSTMATCH module=EBOOT.BIN start=0x00164290 end=0x0016442c symbol=FUN_00164290 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Member of the 0x163xxx/0x164xxx clamp family (cf. action_speed_001644bc.c): the value at +0x58
// plus the record-table term and FUN_000d8334(target, 4), clamped to the first/last row of
// the curve table, then clamped to DAT_002e0380/384 and lerped between DAT_00341298 and DAT_00341294
// by v / 9. A target whose id / 10 == 50 takes the last row directly. One `&&` guard gives retail's
// shared else block (beqz + bnel into it); the inline Clamp takes the bounds by const reference,
// which is what reloads each global bound (retail's double lwc1), and `!(v > hi)` gives c.ngt.s.
#include "hst/stat_curve.h"

extern "C" {
extern StatTable *DAT_0034150c; // records, indexed by id
extern StatTable *DAT_00341510; // curve rows
extern float DAT_002e0380;
extern float DAT_002e0384;
extern float DAT_00341298;
extern float DAT_00341294;
float FUN_000d8334(int, int);
}

static inline float Clamp(float v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00164290(int self, int target)
{
    float v;

    if (target != 0 && *(short *)(target + 10) / STAT_ID_GROUP_DIVISOR == STAT_GROUP_LAST) {
        v = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * STAT_CURVE_ROW_SIZE + 0x10);
    } else {
        float x = *(float *)(self + 0x58);
        float lo;
        float hi;
        if (target != 0) {
            if (*(short *)(target + 10) >= 0)
                x += *(float *)(DAT_0034150c->base +
                                DAT_0034150c->index[*(short *)(target + 10)] * STAT_RECORD_SIZE +
                                0x58);
            x += FUN_000d8334(target, 4);
        }
        lo = ((StatCurveRow *)DAT_00341510->base)->col10;
        hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * STAT_CURVE_ROW_SIZE + 0x10);
        v = Clamp(x, lo, hi);
    }
    v = Clamp(v, DAT_002e0380, DAT_002e0384);
    return DAT_00341298 + (v / 9.0f) * (DAT_00341294 - DAT_00341298);
}
