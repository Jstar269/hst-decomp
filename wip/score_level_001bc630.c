/* HSTMATCH module=EBOOT.BIN start=0x001bc630 end=0x001bc748 symbol=FUN_001bc630 lang=c99 */
static inline int RoundI_001bc630(float x)
{
    if (x > 0.0f)
        return (int)(x + 0.5f);
    return -(int)(0.5f - x);
}

static inline int Level_001bc630(float f)
{
    int v = (int)f;
    if (v >= 1100)
        return 0;
    if (v >= 1000)
        return 1;
    if (v >= 900)
        return 2;
    if (v >= 800)
        return 3;
    if (f >= 700.0f)
        return 4;
    if (v >= 600)
        return 5;
    if (v >= 500)
        return 6;
    if (v >= 400)
        return 7;
    if (v >= 300)
        return 8;
    if (v >= 200)
        return 9;
    return 10;
}

int FUN_001bc630(float score)
{
    return Level_001bc630((float)RoundI_001bc630(score * 100.0f));
}
// 68/70 words, 49 differ: rounding preamble (RoundI returning int, int->float->int round trip at the call) is word-for-word exact; the ladder body differs only in comparison/return scheduling (retail puts `li v0,N` in the b delay slot and uses a plain bnez for the first test, mwcc hoists the next slti into a bnezl delay slot and keeps v in v1 instead of a0). Ruled out: assignment ladder with single return, early-return chain, plain (int) cast.
// near miss from lane ds11 (unreviewed)
