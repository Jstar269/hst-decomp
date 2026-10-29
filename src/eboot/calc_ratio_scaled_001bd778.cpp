/* HSTMATCH module=EBOOT.BIN start=0x001bd778 end=0x001bd9ac symbol=FUN_001bd778 lang=c++ */
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
extern float DAT_002e9d70;
extern float DAT_002e9d74;
extern float DAT_002e9d78;
extern float DAT_002e9d7c;

#define PERCENT_SCALE 100.0f

/* Sums two fields over the first elements (the count of both lists, limited by a global) and returns their ratio as a clamped percentage. */
extern "C" float FUN_001bd778(RatioContainer* owner) {
    unsigned long long sum = (unsigned int)(owner->countA + owner->countB);
    int count = (int)min(sum, DAT_002e9da8);
    RatioElem* p = owner->items;
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < count; ++i, ++p) {
        sum_a += p->unk24;
        sum_b += p->unk28;
    }
    float ratio = 0.0f;
    if (sum_b != 0) {
        ratio = clamp((float)sum_a / (float)sum_b, DAT_002e9d70, DAT_002e9d74);
    }
    return clamp(PERCENT_SCALE * ratio, DAT_002e9d78, DAT_002e9d7c);
}
