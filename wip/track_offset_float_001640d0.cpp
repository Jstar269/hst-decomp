/* HSTMATCH module=EBOOT.BIN start=0x001640d0 end=0x00164290 symbol=FUN_001640d0 lang=c++ */
extern "C" int *DAT_0034150c;
extern "C" int *DAT_00341510;
extern "C" float DAT_002e0378;
extern "C" float DAT_002e037c;
extern "C" float DAT_0034128c;
extern "C" float DAT_00341290;
extern "C" float DAT_003414e4;
extern "C" float FUN_000d8334(int, int);

static inline float Clamp(float v, const float &lo, const float &hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

extern "C" float FUN_001640d0(int param_1, int param_2, unsigned param_3)
{
    float v;
    float lo;
    float hi;

    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) / 10 == 0x32) {
            v = *(float *)(*DAT_00341510 + (DAT_00341510[1] - 1) * 0x14 + 0x10);
            goto tail;
        }
    }
    v = *(float *)(param_1 + 0x58);
    if (param_2 != 0) {
        if (*(short *)(param_2 + 10) >= 0)
            v = v + *(float *)(*DAT_0034150c
                               + *(short *)(DAT_0034150c[3] + *(short *)(param_2 + 10) * 2) * 0x22c
                               + 0x58);
        v = v + FUN_000d8334(param_2, 4);
    }
    lo = *(float *)(*DAT_00341510 + 0x10);
    hi = *(float *)(*DAT_00341510 + (DAT_00341510[1] - 1) * 0x14 + 0x10);
    v = v < lo ? lo : (v > hi ? hi : v);
tail:
    v = Clamp(v, DAT_002e0378, DAT_002e037c);
    v = DAT_00341290 + (v / 9.0f) * (DAT_0034128c - DAT_00341290);
    if (param_3 - 1 < 2)
        v = v + DAT_003414e4;
    return v;
}
// near miss: 112/112 words, 10 differing -- only FP register naming: retail uses $f2 for the
// first clamp's value/lo and $f1 for the second (global) clamp, ours uses $f1 and $f3.
// Shape notes: the param_2==0 test must be written as `if (param_2 != 0) { if (k/10 == 0x32) {...;
// goto tail; } }` followed by the fall-through `v = *(float*)(param_1+0x58)` (writing it as an
// if/else inverts the first branch to bnez and changes the `bnel` polarity). Both clamps are
// needed: the first is an inline ternary over two float locals, the second is an inline helper
// taking the two globals by const& (that is what produces the double `lwc1` of DAT_002e0378 and
// DAT_002e037c and the `c.ngt.s`/`bc1tl` shape). The `k/10` division is a signed divide by 10
// (mult by 0x66666667 + sra/srl correction).
// near miss from lane fm8 (unreviewed)
