/* HSTMATCH module=EBOOT.BIN start=0x001644bc end=0x0016461c symbol=FUN_001644bc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified (88/88 words).
   Sixth member of the 0x163xxx/0x164xxx clamp family, same table lookup (DAT_0034150c,
   0x22c stride) with the base at +0x50, FUN_000d8334's second argument 2 and the per-entry
   term at +0xf8, clamping against the +8 fields. New part: the clamp goes through an inline
   helper taking the three floats BY VALUE, `return v < lo ? lo : (!(v > hi) ? v : hi);` --
   the if/else-if/else form folds the final `c = v` into the same register and costs two words
   (bc1tl target and the mov.s destination). The tail is `res = 2.0f * c`, an optional scale by
   DAT_003414dc[param_2 - 1] * 0.01f when 0 <= param_2 - 1 < 2, then +0x2c added. Names and
   types await human review. */
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern struct Tbl *DAT_0034150c;
extern struct Tbl *DAT_00341510;
extern char *DAT_0034b5d4;
extern float DAT_003414dc[];
extern float FUN_000d8334(int, int);

static inline float Clamp(float v, float lo, float hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

float FUN_001644bc(int param_1, int param_2, int param_3)
{
    float v = *(float *)(param_1 + 0x50);
    float lo;
    float hi;
    float c;
    float res;
    int n;

    if (param_3 != 0) {
        if (*(short *)(param_3 + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            *(short *)(DAT_0034150c->idx + *(short *)(param_3 + 10) * 2) * 0x22c +
                            0x50);
        v += FUN_000d8334(param_3, 2);
        {
            int off = *(char *)(param_3 + 0xa0) * 0x14;
            v += *(float *)(off + (int)DAT_0034b5d4 + 0xf8);
        }
    }
    lo = *(float *)(DAT_00341510->base + 8);
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 8);
    c = Clamp(v, lo, hi);
    res = 2.0f * c;
    n = param_2 - 1;
    if (n >= 0 && (unsigned)n < 2)
        res = res * (DAT_003414dc[n] * 0.01f);
    return *(float *)(param_1 + 0x2c) + res;
}
