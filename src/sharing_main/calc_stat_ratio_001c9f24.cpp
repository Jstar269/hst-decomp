/* HSTMATCH module=hstp_trans_main.prx start=0x001c9f24 end=0x001ca1cc symbol=FUN_001c9f24 lang=c++ */
/* Clone of src/eboot/calc_stat_ratio_001bc13c.cpp (hstclone.py tag c162207): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern float DAT_003919b8;
extern float DAT_003919bc;
extern float DAT_003919c0;
extern float DAT_003919c4;
}

struct Record {
    char pad[44];
    unsigned int a;
    int b;
    int c;
    int d;
    char pad2[100];
};

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_001c9f24(Record *r, int n) {
    unsigned int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    for (int i = 0; i < n; i++, r++) {
        a += r->a;
        b += r->b;
        c += r->c;
        d += r->d;
    }

    int den = (b - c) - d;
    float f2;
    if (den != 0) {
        float ratio = (float)a / (float)(unsigned int)den;
        f2 = Clamp(ratio, DAT_003919b8, DAT_003919bc);
    } else {
        f2 = 0.0f;
    }
    float res = f2 * 100.0f;
    return Clamp(res, DAT_003919c0, DAT_003919c4);
}
