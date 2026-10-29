/* HSTMATCH module=EBOOT.BIN start=0x000ede98 end=0x000edec0 symbol=FUN_000ede98 lang=c99 */
extern float fabsf(float);
float FUN_000ede98(float a, float b, float s, float lim)
{
    float d = b - a;
    a = b;
    if (fabsf(d) >= lim)
        a = a + s * d;
    return a;
}
// NEAR (1 word, 40 bytes): everything matches except the branch L bit - ours `bc1t`, retail `bc1tl`. Both
// have `mov.s $f12,$f13` in the delay slot and accumulate into f12, so the code motion is the same; mwcc
// just declines the likely form here. Ruled out: ternary assigned to `a` (same bc1t), `if (a >= lim) a = ...`
// with else (11 words), negated/mirrored compares (c.nlt forms, 11-12 words). The winning shape is the
// in-place accumulate: `a = b; if (fabs(d) >= lim) a = a + s * d; return a;` - it puts the result in the
// first parameter register and sinks the `a = b` copy into the branch delay (was 4 words off before).
// improved by lane dsn3 (unreviewed): 4 -> 1 differing words
