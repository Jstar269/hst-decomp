/* HSTMATCH module=EBOOT.BIN start=0x001bc13c end=0x001bc3e4 symbol=FUN_001bc13c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/stat_record.h"

extern "C" {
extern float DAT_002e9d80;
extern float DAT_002e9d84;
extern float DAT_002e9d88;
extern float DAT_002e9d8c;
}

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

/* Sums the counters of n records, forms (unk2c-sum) / (unk30 - unk34 - unk38 sums), clamps it, scales it to a percentage and clamps again. */
extern "C" float FUN_001bc13c(StatRecord *rec, int n) {
    unsigned int total = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    for (int i = 0; i < n; i++, rec++) {
        total += rec->unk2c;
        b += rec->unk30;
        c += rec->unk34;
        d += rec->unk38;
    }

    int den = (b - c) - d;
    float ratio_clamped;
    if (den != 0) {
        float ratio = (float)total / (float)(unsigned int)den;
        ratio_clamped = Clamp(ratio, DAT_002e9d80, DAT_002e9d84);
    } else {
        ratio_clamped = 0.0f;
    }
    float percent = ratio_clamped * 100.0f;
    return Clamp(percent, DAT_002e9d88, DAT_002e9d8c);
}
