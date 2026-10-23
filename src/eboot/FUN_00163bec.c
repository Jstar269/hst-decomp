/* HSTMATCH module=EBOOT.BIN start=0x00163bec end=0x00163d68 symbol=FUN_00163bec lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified (95/95 words).
   Large sibling of 0x00163e60/0x00163d68: same table lookup (DAT_0034150c, 0x22c stride)
   but the base value is at +0x4c, the per-entry term at +0xf4 and FUN_000d8334's second
   argument is 1; the float parameter is the FOURTH formal, ahead of the last int, which is
   what puts mov.s before the a3 move; clamping uses the +4 fields; names await human review. */
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern struct Tbl *DAT_0034150c;
extern struct Tbl *DAT_00341510;
extern char *DAT_0034b5d4;
extern float FUN_000d8334(int, int);

float FUN_00163bec(int param_1, int param_2, int param_3, float param_4, int param_5)
{
    float v = *(float *)(param_1 + 0x4c);
    float lo;
    float hi;

    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                            0x4c);
        v += FUN_000d8334(param_2, 1);
        {
            int off = *(char *)(param_2 + 0xa0) * 0x14;
            v += *(float *)(off + (int)DAT_0034b5d4 + 0xf4);
        }
    }
    if (param_3 == 0) {
        if (param_5 != 0)
            v *= *(float *)(param_1 + 0x94) * 0.01f;
        else
            v *= *(float *)(param_1 + 0x88) * 0.01f;
    }
    v *= param_4 * 0.01f;
    lo = *(float *)(DAT_00341510->base + 4);
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 4);
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}
