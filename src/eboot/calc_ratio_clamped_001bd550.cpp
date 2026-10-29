/* HSTMATCH module=EBOOT.BIN start=0x001bd550 end=0x001bd778 symbol=FUN_001bd550 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#include "hst/ratio_container.h"

template <typename T>
static inline const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

static inline float clamp(const float& v, const float& lo, const float& hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern unsigned long long DAT_002e9da8;
extern float DAT_002e9d68;
extern float DAT_002e9d6c;

#define PERCENT_SCALE 100.0f

/* Sums two fields over the first elements (the count of both lists, limited by a global) and returns unk20 / (unk30 - unk34) as a clamped percentage; 0 when the difference is 0. */
extern "C" float FUN_001bd550(RatioContainer* owner) {
    unsigned long long sum = (unsigned int)(owner->countA + owner->countB);
    int count = (int)min(sum, DAT_002e9da8);
    RatioElem* p = owner->items;
    int sum_a = 0;
    int sum_diff = 0;
    for (int i = 0; i < count; ++i, ++p) {
        sum_a += p->unk20;
        sum_diff += p->unk30 - p->unk34;
    }
    return sum_diff != 0 ? clamp(((float)sum_a * PERCENT_SCALE) / (float)sum_diff, DAT_002e9d68, DAT_002e9d6c) : 0.0f;
}
