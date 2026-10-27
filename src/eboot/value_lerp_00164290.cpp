/* HSTMATCH module=EBOOT.BIN start=0x00164290 end=0x0016442c symbol=FUN_00164290 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Member of the 0x163xxx/0x164xxx clamp family (cf. action_speed_001644bc.c): the value at +0x58
// plus the DAT_0034150c table term and FUN_000d8334(node, 4), clamped to the first/last row of
// DAT_00341510, then clamped to DAT_002e0380/384 and lerped between DAT_00341298 and DAT_00341294
// by v / 9. A node whose id / 10 == 50 takes the last row directly. One `&&` guard gives retail's
// shared else block (beqz + bnel into it); the inline Clamp takes the bounds by const reference,
// which is what reloads each global bound (retail's double lwc1), and `!(v > hi)` gives c.ngt.s.
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern "C" {
extern Tbl *DAT_0034150c;
extern Tbl *DAT_00341510;
extern float DAT_002e0380;
extern float DAT_002e0384;
extern float DAT_00341298;
extern float DAT_00341294;
float FUN_000d8334(int, int);
}

static inline float Clamp(float v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00164290(int param_1, int param_2)
{
    float v;

    if (param_2 != 0 && *(short *)(param_2 + 10) / 10 == 50) {
        v = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10);
    } else {
        float x = *(float *)(param_1 + 0x58);
        float lo;
        float hi;
        if (param_2 != 0) {
            if (*(short *)(param_2 + 10) >= 0)
                x += *(float *)(DAT_0034150c->base +
                                *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                                0x58);
            x += FUN_000d8334(param_2, 4);
        }
        lo = *(float *)(DAT_00341510->base + 0x10);
        hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10);
        v = Clamp(x, lo, hi);
    }
    v = Clamp(v, DAT_002e0380, DAT_002e0384);
    return DAT_00341298 + (v / 9.0f) * (DAT_00341294 - DAT_00341298);
}
