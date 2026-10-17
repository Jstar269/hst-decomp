/* HSTMATCH module=hstp_trans_main.prx start=0x000ab60c end=0x000ab68c symbol=FUN_000ab60c lang=c99 */

typedef struct {
    char pad[0x24];
    float f24;
} Ctx_000ab60c;

typedef struct {
    char pad[4];
    float f4;
} Obj_000ab60c;

extern float DAT_003ea53c;
extern Ctx_000ab60c *FUN_000b6e80(void *);

int FUN_000ab60c(void *param_1, Obj_000ab60c *param_2)
{
    Ctx_000ab60c *ctx = FUN_000b6e80(param_1);
    float limit = -(ctx->f24 * 0.01f) * (DAT_003ea53c * 0.01f);
    if (!(param_2->f4 > limit)) {
        return 0;
    }
    if (param_2->f4 < 0.0f) {
        return 1;
    }
    return 0;
}

// NEAR MISS: 30/32 words (scaled float band comparison twin of 0x000ab204; see MWCC-NOTES line 346).
// Retail loads the compared member param_2->f4 into $f1, evaluates -(ctx->f24 * 0.01f) into $f2,
// scales by DAT_003ea53c * 0.01f into $f0, then compares c.ngt.s $f1, $f0 followed by bc1tl
// with delay slot move v0, zero.
// The second branch tests param_2->f4 < 0.0f producing the characteristic unfilled-slot tail:
//   ab660: c.lt.s $f1, $f0
//   ab668: bc1f 0xab678; nop; b 0xab67c; li v0, 1; move v0, zero
// MWCC allocates $f2 for param_2->f4 and $f1 for the product (register swap), remaining 5-6 words off.
// near miss from lane u1r2-3 (unreviewed)
