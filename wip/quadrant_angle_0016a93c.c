/* HSTMATCH module=EBOOT.BIN start=0x0016a93c end=0x0016aafc symbol=FUN_0016a93c lang=c99 */
extern float FUN_0000b8a8(float);
extern float fabsf(float);

float FUN_0016a93c(float *param_1, float *param_2)
{
    float dx = param_2[0] - param_1[0];
    float dz = param_2[2] - param_1[2];

    if (dx >= 0.0f && dz >= 0.0f) {
        if (dz == 0.0f)
            dz = 0.001f;
        return 360.0f - 57.29578f * FUN_0000b8a8(dx / fabsf(dz));
    } else if (dx >= 0.0f && dz < 0.0f) {
        if (dz == 0.0f)
            dz = 0.001f;
        return 180.0f + 57.29578f * FUN_0000b8a8(dx / fabsf(dz));
    } else if (dx < 0.0f && dz >= 0.0f) {
        if (dz == 0.0f)
            dz = 0.001f;
        return 57.29578f * FUN_0000b8a8(-dx / fabsf(dz));
    } else {
        if (dz == 0.0f)
            dz = 0.001f;
        return 180.0f - 57.29578f * FUN_0000b8a8(-dx / fabsf(dz));
    }
}
// near miss: 108/112 words (4 short - one word per arm), 102 differing.
// Structure SOLVED: the dispatch is a four-way `&&` chain, not nested if/else. Retail tests six
// times, alternating dx, dz, dx, dz, dx, dz (`bc1t`, `bc1tl`, `bc1tl`, `bc1f`, `bc1fl`, `bc1t`),
// which only a chain of compound conditions can produce:
//   if (dx >= 0 && dz >= 0) A; else if (dx >= 0 && dz < 0) B; else if (dx < 0 && dz >= 0) C; else D;
// A = 360 - 57.29578f*atanf(dx/|dz|), B = 180 + K*atanf(dx/|dz|), C = K*atanf(-dx/|dz|),
// D = 180 - K*atanf(-dx/|dz|). A nested if/else, a switch, and a shared-test chain all give a
// different test sequence (nested if/else: 93 words).
// Remaining delta, per arm: retail's `dz == 0.0f -> 0.001f` guard is laid out with the then-block
// OUT of line (`bc1tl` over `b`, the `abs.s` duplicated into both arms); every spelling we tried
// compiles to `bc1fl` with the then-block inline and a single `abs.s` at the join, one word short.
// Tried: `if (dz == 0) dz = 0.001f;`, `if (!(dz != 0)) ..`, `else dz = dz;`, the ternary
// `dz = dz == 0 ? 0.001f : dz;`, `fabsf(dz == 0 ? 0.001f : dz)`, and a `static __inline AbsNz(dz)`
// helper - all 108 words. The float registers also differ (retail dx=f2, dz=f3; ours dx=f3, dz=f1).
// near miss from lane fm9 (unreviewed)
