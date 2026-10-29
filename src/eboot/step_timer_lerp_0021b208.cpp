/* HSTMATCH module=EBOOT.BIN start=0x0021b208 end=0x0021b2f4 symbol=FUN_0021b208 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: non-const float DAT globals, inline const-ref Clamp, Obj/Inner structs; readability pass; exact match verified; names and types await human review. */

extern float DAT_002f0028;
extern float DAT_002f002c;
extern float DAT_002f0030;
extern float DAT_002f0034;
extern float DAT_002f0038;
extern float DAT_002f003c;
extern float DAT_002f0040;

extern "C" void FUN_00102c54(void *);
extern "C" void FUN_00103128(void *);

static inline float Clamp(const float &v, const float &lo, const float &hi) {
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct Inner {
    char pad[0x60];
    float unk60;           /* 0x60, eased between two constants */
    char pad2[0x78 - 0x64];
    float unk78;           /* 0x78, eased between two constants */
};

struct Obj {
    char pad[0x64];
    Inner *inner;          /* 0x64 */
    char pad2[0x8c - 0x68];
    int count;             /* 0x8c, ticks remaining */
};

/* Per-frame: counts down and lerps two inner values by the clamped progress. */
extern "C" void FUN_0021b208(Obj *self) {
    if (self->count > 0) {
        self->count--;
        float progress = (DAT_002f0028 - (float)self->count) / DAT_002f0028;
        float clamped = Clamp(progress, DAT_002f002c, DAT_002f0030);
        self->inner->unk60 = DAT_002f0034 + clamped * (DAT_002f0038 - DAT_002f0034);
        self->inner->unk78 = DAT_002f003c + clamped * (DAT_002f0040 - DAT_002f003c);
        FUN_00102c54(self->inner);
    }
    FUN_00103128(self);
}
