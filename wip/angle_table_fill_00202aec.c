/* HSTMATCH module=EBOOT.BIN start=0x00202aec end=0x00202cb8 symbol=FUN_00202aec lang=c99 */
extern int FUN_0001342c(void);
extern double FUN_00022178(int);
extern double FUN_00021748(double, double);
extern double FUN_00021ac0(double, int, float);
extern double FUN_000223a0(double);
extern float FUN_0000bc34(float);
extern float FUN_0000bf34(float);

void FUN_00202aec(int param_1, int param_2)
{
    int half;
    int ang;
    int i;
    int fp;
    int tp;
    int t;
    float f;
    double d;

    if (param_2 == *(int *)(param_1 + 0xf8))
        return;
    *(int *)(param_1 + 0xf8) = param_2;
    if (param_2 <= 0)
        return;
    i = 0;
    fp = param_1;
    tp = param_1;
    do {
        *(float *)(fp + 0xfc) = (float)(FUN_0001342c() % 100) / 100.0f;
        ang = ((i + 1) * 0x1000) / *(int *)(param_1 + 0xf8);
        t = 0x1000 / *(int *)(param_1 + 0xf8);
        half = t / 2;
        ang += FUN_0001342c() % half - half / 2;
        d = FUN_00022178(ang);
        d = FUN_00021748(3.14159265358979323846, d);
        d = FUN_00021ac0(d, 0, 5.0f);
        f = (float)FUN_000223a0(d);
        *(float *)(tp + 0x28c) = FUN_0000bc34(f + 1.5707964f);
        *(float *)(tp + 0x19c) = FUN_0000bf34(f + 1.5707964f);
        *(float *)(tp + 0x290) = FUN_0000bc34(f);
        *(float *)(tp + 0x1a0) = FUN_0000bf34(f);
        *(float *)(tp + 0x294) = FUN_0000bc34(f - 1.5707964f);
        *(float *)(tp + 0x1a4) = FUN_0000bf34(f - 1.5707964f);
        i++;
        fp += 4;
        tp += 0xc;
    } while (i < *(int *)(param_1 + 0xf8));
}
// 118/115 words; first difference at +0x2c, and it is a pure s-register permutation:
// retail s3/s2/s1/s0 = base/i/fp/tp with the two loop-body values ang (s4) and half (s5),
// this build s5/s4/s3/s2/s1/s0 = base/i/fp/tp/half/ang.  The prologue (s5..s0 + f21,f20)
// and every instruction of the body, both double call chains and all six swc1 stores match.
// Ruled out: declaration order (no effect), lowering the generated draft's single reused
// temporaries (7 s-registers), splitting `ang` into its own statement (this version, which is
// what produced matching 6-register saves).  The split `ang = left; ang += ...` is required:
// without it the left term is not kept across the rng() call.
// near miss from lane fm8 (unreviewed)
