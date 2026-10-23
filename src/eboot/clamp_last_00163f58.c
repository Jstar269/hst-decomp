/* HSTMATCH module=EBOOT.BIN start=0x00163f58 end=0x00164080 symbol=FUN_00163f58 lang=c99 */
/* Hand-written reconstruction from the disassembly (same chained-conditional clamp tail as 0x163aac, which is what lets MWCC duplicate the frame restore into the early return's branch delay); exact match verified; names and types await human review. */
struct Tbl {
    int base;
    int count;
    int pad;
    int idx;
};
extern struct Tbl *DAT_0034150c;
extern struct Tbl *DAT_00341510;
extern float FUN_000d8334(int, int);

float FUN_00163f58(int param_1, int param_2)
{
    float v;
    float lo;
    float hi;

    if (param_2 != 0 && *(short *)(param_2 + 10) / 10 == 0x32)
        return *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10);
    v = *(float *)(param_1 + 0x58);
    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                            0x58);
        v += FUN_000d8334(param_2, 4);
    }
    lo = *(float *)(DAT_00341510->base + 0x10);
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14 + 0x10);
    return v < lo ? lo : v > hi ? hi : v;
}
// near miss: 74/74 words, 2 differ (tail only): retail's `b epilogue` keeps a nop delay and jumps to
// the `lw ra`; ours hoists `lw ra` into the branch delay and jumps past it. Ruled out: compound vs
// nested special-case test (same layout).
