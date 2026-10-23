/* HSTMATCH module=EBOOT.BIN start=0x0010b06c end=0x0010b150 symbol=FUN_0010b06c lang=c99 */
struct Rec {
    int w0;
    int w1;
    int w2;
    int w3;
    short h0;
    short h1;
    short h2;
    short h3;
    short h4;
    short pad;
    int w4;
    int w5;
};
extern void FUN_00101630(int, struct Rec *, int);
extern void FUN_000ffca4(int);
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off

void FUN_0010b06c(int param_1, struct Rec *param_2)
{
    struct Rec local[3];
    struct Rec *dst;
    unsigned int i;
    int j;

    for (i = 0, dst = local; i < 3; i++, dst++) {
        dst->w0 = param_2->w0;
        dst->w1 = param_2->w1;
        dst->w2 = param_2->w2;
        dst->w3 = param_2->w3;
        dst->h0 = param_2->h0;
        dst->h1 = param_2->h1;
        dst->h2 = param_2->h2;
        dst->h3 = param_2->h3;
        dst->h4 = param_2->h4;
        dst->w4 = param_2->w4;
        dst->w5 = param_2->w5;
        dst->w3 = i + 0x2c;
    }
    FUN_00101630(param_1, local, 3);
    for (j = 0; j < *(int *)(param_1 + 0x14); j++)
        FUN_000ffca4(*(int *)(*(int *)(param_1 + 0x10) + j * 4));
}
// near miss: 57/57 words, 18 differ, all one register swap: MWCC puts the copy loop's byte counter
// in a2 and the destination pointer in a3, retail has the counter in a3 and the pointer in a2. The
// explicit `dst` pointer (with `opt_strength_reduction off`) is what reproduces retail's pointer
// induction (`addiu a2,sp,20` before the loop, `addiu a2,a2,36` in the `bnez` delay) AND the second
// loop's per-iteration `sll`; with strength reduction ON the first loop comes out right by itself
// (induction in a2) but the second loop becomes a byte-offset induction in s2 and costs two words.
// Ruled out: index form with the pragma off (no induction, 60 words), index form with it on (59,
// s2 frame), defining dst before i, `dst++, i++` order, incrementing i inside the body, and a
// `while` for the second loop.
// near miss from lane fm6 (unreviewed)
