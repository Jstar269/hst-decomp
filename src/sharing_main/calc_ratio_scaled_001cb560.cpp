/* HSTMATCH module=hstp_trans_main.prx start=0x001cb560 end=0x001cb794 symbol=FUN_001cb560 lang=c++ */
/* Clone of src/eboot/calc_ratio_scaled_001bd778.cpp (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

template <typename T>
static inline const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

static inline float clamp(const float& v, const float& lo, const float& hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern unsigned long long DAT_003919e0;
extern float DAT_003919a8;
extern float DAT_003919ac;
extern float DAT_003919b0;
extern float DAT_003919b4;

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

extern "C" float FUN_001cb560(Container* param_1) {
    unsigned long long sum = (unsigned int)(param_1->count1 + param_1->count2);
    int count = (int)min(sum, DAT_003919e0);
    Elem* p = param_1->items;
    int sum_24 = 0;
    int sum_28 = 0;
    for (int i = 0; i < count; ++i, ++p) {
        sum_24 += p->f24;
        sum_28 += p->f28;
    }
    float ratio = 0.0f;
    if (sum_28 != 0) {
        ratio = clamp((float)sum_24 / (float)sum_28, DAT_003919a8, DAT_003919ac);
    }
    return clamp(100.0f * ratio, DAT_003919b0, DAT_003919b4);
}
