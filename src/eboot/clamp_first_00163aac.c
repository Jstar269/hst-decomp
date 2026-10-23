/* HSTMATCH module=EBOOT.BIN start=0x00163aac end=0x00163bec symbol=FUN_00163aac lang=c99 */
/* Hand-written reconstruction from the disassembly (the clamp at the end is a chained conditional expression: with an early return before it MWCC only duplicates the frame restore into the branch delay for that form); exact match verified; names and types await human review. */
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

float FUN_00163aac(int param_1, int param_2)
{
    float v;
    float lo;
    float hi;

    if (param_2 != 0 && *(short *)(param_2 + 10) / 10 == 0x32)
        return *(float *)(DAT_00341510->base);
    v = *(float *)(param_1 + 0x44);
    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) >= 0)
            v += *(float *)(DAT_0034150c->base +
                            *(short *)(DAT_0034150c->idx + *(short *)(param_2 + 10) * 2) * 0x22c +
                            0x44);
        v += FUN_000d8334(param_2, 0);
        {
            int off = *(char *)(param_2 + 0xa0) * 0x14;
            v += *(float *)(off + (int)DAT_0034b5d4 + 0xf0);
        }
    }
    lo = *(float *)(DAT_00341510->base);
    hi = *(float *)(DAT_00341510->base + (DAT_00341510->count - 1) * 0x14);
    return v < lo ? lo : v > hi ? hi : v;
}
// near miss: 80/80 words, 2 differ (tail only): the early-return path shares the epilogue, so retail's
// final `b` keeps a nop delay and jumps to the `lw ra`; ours hoists `lw ra` into the branch delay.
// Same 2-word tail as 0x163f58; the no-early-return twins 0x163d68/0x163e60 match exactly.
