/* HSTMATCH module=EBOOT.BIN start=0x0023fe08 end=0x0023ff88 symbol=FUN_0023fe08 lang=c99 */
extern int DAT_003402a0;
extern char DAT_002bc410[];
extern char DAT_002f83ec[];
extern char DAT_002f8400[];
extern char FUN_001463f8(int, int, int);
extern void FUN_0023ff88(char *, ...);
extern void FUN_0004d2cc(float, int, char *);

void FUN_0023fe08(int self, int a1, int a2, int a3, float f1, float f2, int a6, int a7)
{
    unsigned char ok;
    int n;
    unsigned int r;
    float *v;

    *(int *)(self + 0x2ac) = a1;
    *(int *)(self + 0x2b0) = a2;
    *(int *)(self + 0x2b4) = a3;
    *(float *)(self + 0x2b8) = f1;
    *(float *)(self + 0x2bc) = f2;
    *(int *)(self + 0x2c0) = a6;
    *(int *)(self + 0x2c4) = a7;
    ok = FUN_001463f8(DAT_003402a0 + 0x40, *(int *)(self + 0x2b0), self + 0x2a0);
    if (ok == 0)
        FUN_0023ff88(DAT_002f83ec, *(int *)(self + 0x2b0));
    if (*(int *)(self + 0x2ac) == 3 || *(int *)(self + 0x2ac) == 6)
        FUN_0023ff88(DAT_002f8400, *(int *)(self + 0x2ac), *(int *)(self + 0x2a4));
    n = *(int *)(self + 0x2c4);
    if (n != 0) {
        r = *(int *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
        *(int *)(DAT_003402a0 + 0x1360) = r;
        n = ((r >> 16) & 0x7fff) % n;
    } else {
        n = 0;
    }
    FUN_0004d2cc((float)(*(int *)(self + 0x2c0) + n) * 0.017453292f, self + 0x220,
                 DAT_002bc410);
    v = *(float **)*(int *)(self + 0x2a0);
    *(float *)(self + 0x280) = v[0];
    *(float *)(self + 0x284) = v[1];
    *(float *)(self + 0x288) = v[2];
    *(float *)(self + 0x28c) = v[3];
    *(float *)(self + 0x290) = *(float *)(self + 0x280);
    *(float *)(self + 0x294) = *(float *)(self + 0x284);
    *(float *)(self + 0x298) = *(float *)(self + 0x288);
    *(float *)(self + 0x29c) = *(float *)(self + 0x28c);
    *(float *)(self + 0x250) = *(float *)(self + 0x280);
    *(float *)(self + 0x254) = *(float *)(self + 0x284);
    *(float *)(self + 0x258) = *(float *)(self + 0x288);
    *(float *)(self + 0x25c) = *(float *)(self + 0x28c);
}
// near miss: 94-97/96 words. Everything is pinned except the random-offset block: retail keeps the
// count in v0 and emits `bnezl v0, rng` with the trivial `n = 0` arm out of line; ours loads it
// into a2 and branches the other way (`beqzl a2, end` with `move a0,zero` in the delay). Facts:
// the seven stored fields are +0x2ac/+0x2b0/+0x2b4 (ints from a1..a3), +0x2b8/+0x2bc (FLOATS from
// f12/f13), +0x2c0/+0x2c4 (t0/t1); FUN_001463f8's result is UNSIGNED (andi 0xff, not seb); the
// angle is (float)(+0x2c0 + n) * 0.017453292 and goes to FUN_0004d2cc(angle, self+0x220,
// DAT_002bc410); the three vec4 copies (+0x280 from **(self+0x2a0), then +0x290 and +0x250 from
// +0x280) are float word-by-word copies.
// near miss from lane fm6 (unreviewed)
