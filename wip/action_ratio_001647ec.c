/* HSTMATCH module=EBOOT.BIN start=0x001647ec end=0x00164958 symbol=FUN_001647ec lang=c99 */
/* near miss: 82/91 words, 47 differ. Seventh clamp-family member: identical head to
   0x001644bc (table lookup, FUN_000d8334(_,2), +0xf8 term) and the same value-parameter
   Clamp helper, then `(c - lo) / (hi - lo)` normalised and clamped again into
   [DAT_002e0398, DAT_002e039c] with early returns. Retail re-reads lo/hi from the table for
   the division (the head's lo/hi are dead after the clamp) and materialises the return
   constant into $f0 BEFORE the compare, so the min/max comparisons load the same global
   twice (`lwc1 f0,920` then `lwc1 f1,920`). Ours keeps lo alive across the clamp and reloads
   it later, which shifts the whole division block. Ruled out so far: locals for lo/hi vs
   re-expressing the table reads inline (this file uses the inline form); the Clamp helper is
   confirmed correct by 0x001644bc. */
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern struct Tbl *DAT_0034150c;
extern struct Tbl *DAT_00341510;
extern char *DAT_0034b5d4;
extern float DAT_002e0398;
extern float DAT_002e039c;
extern float FUN_000d8334(int, int);

static inline float Clamp(float v, float lo, float hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

float FUN_001647ec(int param_1, int param_2)
{
    float v = *(float *)(param_1 + 0x50);
    float c;
    float t;
    float lo;
    float hi;

    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                            0x50);
        v += FUN_000d8334(param_2, 2);
        {
            int off = *(char *)(param_2 + 0xa0) * 0x14;
            v += *(float *)(off + (int)DAT_0034b5d4 + 0xf8);
        }
    }
    lo = *(float *)(DAT_00341510->base + 8);
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 8);
    c = Clamp(v, lo, hi);
    t = (c - *(float *)(DAT_00341510->base + 8)) /
        (*(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 8) -
         *(float *)(DAT_00341510->base + 8));
    if (t < DAT_002e0398)
        return DAT_002e0398;
    if (t > DAT_002e039c)
        return DAT_002e039c;
    return t;
}
// near miss from lane fm6 (unreviewed)
