/* HSTMATCH module=EBOOT.BIN start=0x00164ac4 end=0x00164c60 symbol=FUN_00164ac4 lang=c++ */
// NEAR 101/103 words, 6-word residue in the head only (tail from 0x164c04 matches exactly).
// Retail keeps DAT_00341510->count in a1 live into the normalisation, base in a0, and the
// clamped value in f1; ours picks v0 for count, v1 for the table pointer and f0 for the value,
// so the normalisation reloads base+0x10 via a hoisted addiu instead of the 16(a0) displacement.
// Structure that IS right: the 0x32 case as the if-body assigning the result and the
// calculation in the else (no goto), `v` merged across both arms, the table clamp taking
// lo/hi by const reference (single loads), and the normalisation re-reading the table
// expressions inline (f = v - first; f = f / (last - first); then Clamp by ref).
// Ruled out: p/n locals (103/103 but base/count order and f0 home wrong), lo/hi locals at
// function scope or inside the else (99 words: the 0x32 load lands in f4 and a mov.s is
// inserted), lo/hi chained ternary (107: the hi expression is re-evaluated per arm),
// float-declaration order v/f and f/v (identical codegen), a separate c local (coalesced).
// Next lever to try: make MWCC keep count in a1 (e.g. via a third use of the count after the
// divide) or force the f1 home for the merged value.

struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};

extern "C" Tbl *DAT_0034150c;
extern "C" Tbl *DAT_00341510;
extern "C" float DAT_002e03a8;
extern "C" float DAT_002e03ac;
extern "C" float FUN_000d8334(int, int);

static inline float Clamp(float v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

extern "C" float FUN_00164ac4(int param_1, int param_2)
{
    float v;
    float f;

    if (param_2 != 0 && *(short *)(param_2 + 10) / 10 == 0x32) {
        v = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10);
    } else {
        v = *(float *)(param_1 + 0x58);
        if (param_2 != 0) {
            if (*(short *)(param_2 + 10) >= 0)
                v += *(float *)(DAT_0034150c->base +
                                *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                                0x58);
            v += FUN_000d8334(param_2, 4);
        }
        v = Clamp(v, *(float *)(DAT_00341510->base + 0x10),
                     *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10));
    }
    f = v - *(float *)(DAT_00341510->base + 0x10);
    f = f / (*(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10) -
             *(float *)(DAT_00341510->base + 0x10));
    return Clamp(f, DAT_002e03a8, DAT_002e03ac);
}
// near miss from lane fm7 (unreviewed)
