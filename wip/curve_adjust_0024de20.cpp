/* HSTMATCH module=EBOOT.BIN start=0x0024de20 end=0x0024de88 symbol=FUN_0024de20 lang=c99 */
extern "C" float FUN_0024dd8c(float, int);

extern "C" float FUN_0024de20(float value, int mode)
{
    value = FUN_0024dd8c(value, mode);
    if (value <= 0.0f) {
    } else if (!(value >= 1.0f)) {
        value = 0.79999995f * value + 0.1f;
    }
    return value;
}
// Near miss: only +0x54 differs (candidate mul.s $f0,$f1,$f0; retail mul.s $f0,$f0,$f1). Direct x*C and C*x spellings retained this operand order; x*=C changed the surrounding code and left eight words different.
// near miss from lane u4r4-2 (unreviewed)
