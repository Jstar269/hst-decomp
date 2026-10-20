/* HSTMATCH module=EBOOT.BIN start=0x001fa0e4 end=0x001fa23c symbol=FUN_001fa0e4 lang=c99 */
extern unsigned char DAT_003417cc;
extern int DAT_0034a7ec;
extern int FUN_0027edbc(int, unsigned char);
extern void FUN_001bda24(char *a0, unsigned char a1, unsigned char a2, int a3,
                         int a4, int a5, int a6, int a7,
                         int b0, int b1, int b2, int b3, int b4,
                         int b5, int b6, int b7, int b8, int b9,
                         int b10, int b11, int b12, int b13,
                         int b14, int b15, int b16, int b17,
                         int b18, int b19, int b20, int b21,
                         int *b22);
void FUN_001fa0e4(char *p, char *a2)
{
    char *q = p + 0x54;
    char *n = q + 92 * *(int *)(p + 0x3cc) + 24;
    int v = FUN_0027edbc(DAT_0034a7ec, DAT_003417cc);

    FUN_001bda24(a2 + 0x1378,
                 *(unsigned char *)(p + 0x5bd), *(unsigned char *)(p + 0x5a8),
                 v ? *(short *)(v + 10) : 0,
                 *(int *)(q + 400), *(int *)(n + 8), *(int *)(n + 12), *(int *)(q + 404),
                 *(int *)(q + 408), *(int *)(q + 412), *(int *)(q + 416), *(int *)(q + 420),
                 *(int *)(q + 424),
                 *(int *)(n + 44), *(int *)(n + 40), *(int *)(n + 56), *(int *)(n + 60),
                 *(int *)(n + 64), *(int *)(n + 24), *(int *)(n + 28), *(int *)(n + 32),
                 *(int *)(n + 36), *(int *)(q + 428), *(int *)(q + 432), *(int *)(n + 20),
                 *(int *)(q + 436), *(int *)(n + 84), *(int *)(n + 88), *(int *)(n + 80),
                 *(int *)(q + 440), (int *)(q + 444));
}
// NEAR MISS: 87/86 words, 75 differ (first at +0x20). Content is confirmed correct: the callee's 31
// arguments and their load/store order match retail 1:1 (sp+0..sp+88, int store loop 408..424,
// then the record fields, then the trailing (int *)(q+444)), and the prologue computes q = p+0x54 and
// n = q + 92*(p+0x3cc) + 24 in retail's order with s0 = n. The whole function then differs only in
// register allocation: our index temporary lands in a2 (retail v1), which frees v1 for the global's
// `lui 0x35` and cascades (retail: global address materialised just before the call, load in the jal
// delay slot and the load temps reuse v1; ours: address hoisted early, `addiu s0` moved into the
// delay slot, temps in a0). 12 spellings of the base expression / call placement (named idx, unsigned
// idx, call first, n += 24, typed-pointer forms) were byte-identical to each other, so the choice does
// not follow from the source shape we can see. One extra word comes from `addiu s0,v0,24` not being
// folded; `n += 24` after the call folds it but loses the +24 offsets.
// near miss from lane ds2 (unreviewed)
