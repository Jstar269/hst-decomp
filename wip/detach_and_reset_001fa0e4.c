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
    int s = 0;
    if (v) s = *(short *)(v + 10);

    FUN_001bda24(a2 + 0x1378,
                 *(unsigned char *)(p + 0x5bd), *(unsigned char *)(p + 0x5a8),
                 s,
                 *(int *)(q + 400), *(int *)(n + 8), *(int *)(n + 12), *(int *)(q + 404),
                 *(int *)(q + 408), *(int *)(q + 412), *(int *)(q + 416), *(int *)(q + 420),
                 *(int *)(q + 424),
                 *(int *)(n + 44), *(int *)(n + 40), *(int *)(n + 56), *(int *)(n + 60),
                 *(int *)(n + 64), *(int *)(n + 24), *(int *)(n + 28), *(int *)(n + 32),
                 *(int *)(n + 36), *(int *)(q + 428), *(int *)(q + 432), *(int *)(n + 20),
                 *(int *)(q + 436), *(int *)(n + 84), *(int *)(n + 88), *(int *)(n + 80),
                 *(int *)(q + 440), (int *)(q + 444));
}
// NEAR MISS (lane wf20261026-e01-02, 2026-10-26): 86/86 words, 10 differ (was 75). Fix: the ternary
// `v ? *(short*)(v+10) : 0` in the argument list becomes `int s = 0; if (v) s = ...;` before the call,
// giving retail's `beqz v0; move a3,zero; lh a3,10(v0)` right after the call (the ternary/if-else forms put
// the select after the stack stores). Remaining 10 words: idx loads into a2 (retail v1), so lui 0x35 gets
// v1 and is hoisted; retail has lui v0,0x35 after `addiu s0,v0,24` and lw a0 in the jal slot.
// 17 spellings (call first/middle, idx/key/global as locals in any order, n += 24, off temp, typed C++
// structs Sub/Rec with &q->recs[p->idx], inline GetS() wrapper, ptr-to-global) are byte-identical to this.
// improved by lane wf20261026-e01-02 (unreviewed): 75 -> 10 differing words
