/* HSTMATCH module=EBOOT.BIN start=0x001bd550 end=0x001bd778 symbol=FUN_001bd550 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

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

struct Elem {
    char pad0[0x20];
    int f20;
    char pad1[0x30 - 0x24];
    int f30;
    int f34;
    char pad2[0xa0 - 0x38];
};

struct Container {
    char pad0[8];
    int count1;
    int count2;
    char pad1[0xc0 - 16];
    Elem items[1];
};

extern "C" float FUN_001bd550(Container* param_1) {
    unsigned long long sum = (unsigned int)(param_1->count1 + param_1->count2);
    int count = (int)min(sum, DAT_002e9da8);
    Elem* p = param_1->items;
    int sum_20 = 0;
    int sum_diff = 0;
    for (int i = 0; i < count; ++i, ++p) {
        sum_20 += p->f20;
        sum_diff += p->f30 - p->f34;
    }
    return sum_diff != 0 ? clamp(((float)sum_20 * 100.0f) / (float)sum_diff, DAT_002e9d68, DAT_002e9d6c) : 0.0f;
}
