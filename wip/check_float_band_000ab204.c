/* HSTMATCH module=hstp_trans_main.prx start=0x000ab204 end=0x000ab274 symbol=FUN_000ab204 lang=c99 */

typedef struct {
    char pad[0x24];
    float f24;
} Ctx_000ab204;

typedef struct {
    char pad[4];
    float f4;
} Obj_000ab204;

extern Ctx_000ab204 *FUN_000b6e80(void *);

int FUN_000ab204(void *param_1, Obj_000ab204 *param_2)
{
    Ctx_000ab204 *ctx = FUN_000b6e80(param_1);
    float limit = -(ctx->f24 * 0.01f);
    if (!(param_2->f4 > limit)) {
        return 0;
    }
    if (param_2->f4 < 0.0f) {
        return 1;
    }
    return 0;
}

// NEAR MISS: 27/28 words (float band comparison family: 0x000ab204, twin 0x000ab60c; see MWCC-NOTES line 346).
// Retail loads the compared member param_2->f4 into $f1 and the 0.01f constant into $f2,
// then compares c.ngt.s $f1, $f0 followed by bc1tl with delay slot move v0, zero.
// The second branch tests param_2->f4 < 0.0f producing the characteristic unfilled-slot tail:
//   ab248: c.lt.s $f1, $f0
//   ab250: bc1f 0xab260; nop; b 0xab264; li v0, 1; move v0, zero
// MWCC allocates $f2 for param_2->f4 and $f1 for the constant (register swap), remaining 5-6 words off.
// near miss from lane u1r2-3 (unreviewed)
