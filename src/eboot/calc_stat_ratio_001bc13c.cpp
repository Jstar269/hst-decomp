/* HSTMATCH module=EBOOT.BIN start=0x001bc13c end=0x001bc3e4 symbol=FUN_001bc13c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" {
extern float DAT_002e9d80;
extern float DAT_002e9d84;
extern float DAT_002e9d88;
extern float DAT_002e9d8c;
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

extern "C" float FUN_001bc13c(Record *r, int n) {
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
        f2 = Clamp(ratio, DAT_002e9d80, DAT_002e9d84);
    } else {
        f2 = 0.0f;
    }
    float res = f2 * 100.0f;
    return Clamp(res, DAT_002e9d88, DAT_002e9d8c);
}
