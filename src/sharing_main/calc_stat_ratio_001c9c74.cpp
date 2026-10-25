/* HSTMATCH module=hstp_trans_main.prx start=0x001c9c74 end=0x001c9e38 symbol=FUN_001c9c74 lang=c++ */
/* Clone of src/eboot/calc_stat_ratio_001bbe8c.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern float DAT_003919a0;
extern float DAT_003919a4;
}

struct Record {
    char pad[32];
    int a;          // 0x20 (32)
    char pad2[12];  // 0x24..0x2f
    int b;          // 0x30 (48)
    int c;          // 0x34 (52)
    char pad3[104]; // total 160 (0xa0)
};

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001c9c74(Record *r, int n) {
    int sum_a = 0;
    int sum_diff = 0;

    for (int i = 0; i < n; i++, r++) {
        sum_a += r->a;
        sum_diff += r->b - r->c;
    }

    if (sum_diff != 0) {
        float ratio = ((float)sum_a * 100.0f) / (float)sum_diff;
        return Clamp(ratio, DAT_003919a0, DAT_003919a4);
    }

    return 0.0f;
}
