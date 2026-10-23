/* HSTMATCH module=EBOOT.BIN start=0x00164958 end=0x00164ac4 symbol=FUN_00164958 lang=c99 */
/* near miss: 82/91 words, 47 differ. Twin of 0x001647ec with +0x54/+0xc/+0xfc, FUN_000d8334(_,3)
   and [DAT_002e03a0, DAT_002e03a4]: identical head, same value-parameter Clamp, then
   `(c - lo) / (hi - lo)` and a second early-return clamp. Retail keeps lo in f0 and hi in f1
   and puts the clamp result in f0 (`mov.s f0,f1`), so the division reloads lo into f2 and hi
   into f1 after the clamp; ours keeps lo in f1 and hi in f3 and folds the result into f20,
   which shifts every following word. The same source shape is exact in 0x001644bc, so the
   difference is the expression the clamp feeds (a subtraction/division here, a multiply there).
   Ruled out: locals vs inline table re-reads for the division, Clamp inline inside the division
   expression, and an unused `c` local. */
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern struct Tbl *DAT_0034150c;
extern struct Tbl *DAT_00341510;
extern char *DAT_0034b5d4;
extern float DAT_002e03a0;
extern float DAT_002e03a4;
extern float FUN_000d8334(int, int);

static inline float Clamp(float v, float lo, float hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

float FUN_00164958(int param_1, int param_2)
{
    float v = *(float *)(param_1 + 0x54);
    float c;
    float t;
    float lo;
    float hi;

    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                            0x54);
        v += FUN_000d8334(param_2, 3);
        {
            int off = *(char *)(param_2 + 0xa0) * 0x14;
            v += *(float *)(off + (int)DAT_0034b5d4 + 0xfc);
        }
    }
    lo = *(float *)(DAT_00341510->base + 0xc);
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0xc);
    c = Clamp(v, lo, hi);
    t = (Clamp(v, lo, hi) - *(float *)(DAT_00341510->base + 0xc)) /
        (*(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0xc) -
         *(float *)(DAT_00341510->base + 0xc));
    if (t < DAT_002e03a0)
        return DAT_002e03a0;
    if (t > DAT_002e03a4)
        return DAT_002e03a4;
    return t;
}
// near miss from lane fm6 (unreviewed)
