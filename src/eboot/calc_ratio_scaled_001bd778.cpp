/* HSTMATCH module=EBOOT.BIN start=0x001bd778 end=0x001bd9ac symbol=FUN_001bd778 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

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

struct Elem {
    char pad0[0x24];
    int f24;
    int f28;
    char pad1[0xa0 - 0x2c];
};

struct Container {
    char pad0[8];
    int count1;
    int count2;
    char pad1[0xc0 - 16];
    Elem items[1];
};

extern "C" float FUN_001bd778(Container* param_1) {
    unsigned long long sum = (unsigned int)(param_1->count1 + param_1->count2);
    int count = (int)min(sum, DAT_002e9da8);
    Elem* p = param_1->items;
    int sum_24 = 0;
    int sum_28 = 0;
    for (int i = 0; i < count; ++i, ++p) {
        sum_24 += p->f24;
        sum_28 += p->f28;
    }
    float ratio = 0.0f;
    if (sum_28 != 0) {
        ratio = clamp((float)sum_24 / (float)sum_28, DAT_002e9d70, DAT_002e9d74);
    }
    return clamp(100.0f * ratio, DAT_002e9d78, DAT_002e9d7c);
}
