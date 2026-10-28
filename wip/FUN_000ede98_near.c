/* HSTMATCH module=EBOOT.BIN start=0x000ede98 end=0x000edec0 symbol=FUN_000ede98 lang=c99 */
extern float fabsf(float);

float FUN_000ede98(float a, float b, float s, float lim)
{
    float d = b - a;
    if (!(fabsf(d) >= lim))
        return b;
    return a + s * d;
}
// NEAR (4 words, 40 bytes): retail's arm is a LIKELY branch (`bc1tl` with `mov.s $f12,$f13` in the delay,
// so f12 keeps `a` on the fall-through) and accumulates in f12. Ours emits `bc1t` + `nop` delay and
// accumulates in f13. Forms tried: `if (!(abs >= lim)) return b; return a + s*d;` (bc1t, 4 words off),
// assignment to the first parameter + single return (11 words), explicit else (12 words).
// near miss from lane dsn3 (unreviewed)
