/* HSTMATCH module=EBOOT.BIN start=0x002534b4 end=0x002535e0 symbol=FUN_002534b4 lang=c99 */
extern int DAT_0034a7ec;
extern int FUN_0027edbc(int, int);
extern void FUN_000ffb3c(int, int);

void FUN_002534b4(int *param_1, int param_2)
{
    int h = param_1[param_2 + 0xf];
    int e = FUN_0027edbc(DAT_0034a7ec, h);
    int a = 0;
    int b = 0;
    int c = 0;
    int *g;
    int i;

    if (e != 0) {
        a = *(short *)(e + 10);
        b = *(short *)(e + 12);
        c = *(short *)(e + 14);
    }
    g = (int *)param_1[0];
    for (i = 0; i < g[5]; i++)
        FUN_000ffb3c(*(int *)(g[4] + i * 4), (i ^ (h - 1)) != 0);
    *(int *)(param_1[1] + 0x24) = param_1[2] + a;
    *(int *)(param_1[1] + 0x28) = param_1[2] + a;
    for (i = 0; i < 5; i++)
        FUN_000ffb3c(param_1[3 + i], !(i < b));
    for (i = 0; i < 5; i++)
        FUN_000ffb3c(param_1[8 + i], !(i < c));
}
// near miss: 80/75 words. Structure is right: slot lookup param_1[param_2+0xf] through
// FUN_0027edbc(DAT_0034a7ec, slot), three `lh` triples off the record (a at +10, b at +12,
// c at +14, each defaulting to 0), the count-driven callback loop over g[5]/g[4] with the
// argument `(i ^ (h-1)) != 0`, the two `param_1[1]+0x24/+0x28` stores of param_1[2]+a, and the
// two five-iteration loops calling with `!(i < b)` / `!(i < c)` off param_1[3+i] / param_1[8+i].
// Two deltas: (1) a, b, c must be `int` not `short` -- as `short` every use gains a `seh`, and
// the entry `move` becomes the s-register colouring instead (retail's three `move sX,zero`
// before the beqz are consistent with int locals); (2) MWCC strength-reduces `g[4] + i*4` into a
// byte pointer here (`addu v1,v1,s2` + `addiu s2,s2,4`, one extra saved register, `bnez` instead
// of retail's `bnezl`), where retail recomputes `sll a0,s2,2; addu v0,v1,a0` every iteration.
// Ruled out for (2): array-typed `((int *)g[4])[i]`, element into a local, `g[5] > i`,
// hoisting `h - 1` out of the loop, a `volatile` read of g[4] (83 words, worse), a local `arr`
// pointer plus a local `k` for the xor, and a local byte `off`. All keep the offset induction
// variable, so the difference is MWCC deciding to strength-reduce an address whose base is a
// memory load, not anything the source can express differently.
// near miss from lane fm6 (unreviewed)
