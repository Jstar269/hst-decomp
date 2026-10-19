/* HSTMATCH module=hstp_trans_main.prx start=0x001cb338 end=0x001cb560 symbol=FUN_001cb338 lang=c++ */
/* Clone of src/eboot/calc_ratio_clamped_001bd550.cpp (hstclone.py tag s10172123g8r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

template <typename T>
static inline const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

static inline float clamp(const float& v, const float& lo, const float& hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern unsigned long long DAT_003919e0;
extern float DAT_003919a0;
extern float DAT_003919a4;

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

extern "C" float FUN_001cb338(Container* param_1) {
    unsigned long long sum = (unsigned int)(param_1->count1 + param_1->count2);
    int count = (int)min(sum, DAT_003919e0);
    Elem* p = param_1->items;
    int sum_20 = 0;
    int sum_diff = 0;
    for (int i = 0; i < count; ++i, ++p) {
        sum_20 += p->f20;
        sum_diff += p->f30 - p->f34;
    }
    return sum_diff != 0 ? clamp(((float)sum_20 * 100.0f) / (float)sum_diff, DAT_003919a0, DAT_003919a4) : 0.0f;
}
