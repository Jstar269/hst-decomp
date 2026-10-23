/* HSTMATCH module=EBOOT.BIN start=0x00163d68 end=0x00163e60 symbol=FUN_00163d68 lang=c99 */
/* Hand-written reconstruction from the disassembly (the offset of the last term is a block-scoped local, which flips MWCC's add operand order); exact match verified; names and types await human review. */
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

float FUN_00163d68(int param_1, int param_2)
{
    float v = *(float *)(param_1 + 0x50);
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
    if (v < lo)
        return lo;
    if (v > hi)
        return hi;
    return v;
}
