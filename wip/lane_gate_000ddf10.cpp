/* HSTMATCH module=EBOOT.BIN start=0x000ddf10 end=0x000de100 symbol=FUN_000ddf10 lang=c++ */
// NEAR: 124/124 words, 22 differ, ALL of them float-register allocation/operand order:
// retail keeps base=$f4, first limit=$f3, second limit=$f2, mul.s $f4,$f0,$f1 (const loaded first);
// ours base=$f3, limit=$f2. Everything else (frame, table index addu order, branch ladder,
// constants, c.ngt/bc1t compares) is exact.
// Levers found 2026-10-24 (sn7): the compares must be written with the variable on the left
// (fabsf(t.x) > lim - (base + ramp), t.z > lim - (...)) for retail's c.ngt.s/bc1t; the
// limit is a ternary expression (lim = (c != 0 || flag != 0) ? 4.1148f : 5.4864f; lim = flag != 0 ? 6.4008f : 11.8872f)
// not an if/else (retail's bnezl/beqzl layout and the 124-word length); the table index is
// 'int off = idx * 4; ... (off + (int)tbl + 0x70)' for retail's addu v0,v1,v0.
// Ruled out for the $f allocation: declaration order of base/lim/lim2, a second limit local,
// block-scoped limits, base split in two statements or via extra locals, DAT*field vs field*DAT
// (changes load order but not the registers), inlining the base product at every use (137-140 words).


struct V4_0ddf10 {
    float x;
    float y;
    float z;
    float w;
};

extern "C" {
extern char *DAT_003386b0;
extern char *DAT_003402a0;
extern float DAT_002d279c;
extern float fabsf(float);
extern void FUN_00022450(struct V4_0ddf10 *out, struct V4_0ddf10 *a,
                         struct V4_0ddf10 *b);
extern unsigned char FUN_000ddd64(char *self, struct V4_0ddf10 *v, int flag);
}

extern "C" int FUN_000ddf10(char *self, int flag)
{
    char *node = *(char **)(self + 0x40);
    char *tbl = DAT_003386b0;
    int idx = *(int *)(node + 0x234);
    int off = idx * 4;
    char *p = *(char **)(off + (int)tbl + 0x70);
    struct V4_0ddf10 t;
    struct V4_0ddf10 b;
    struct V4_0ddf10 a;
    struct V4_0ddf10 r;
    float base;
    float lim;
    unsigned char hit;

    a.x = *(float *)(p + 0x5a0);
    a.y = *(float *)(p + 0x5a4);
    a.z = *(float *)(p + 0x5a8);
    a.w = *(float *)(p + 0x5ac);
    b.x = *(float *)(node + 0x10);
    b.y = *(float *)(node + 0x14);
    b.z = *(float *)(node + 0x18);
    b.w = *(float *)(node + 0x1c);
    FUN_00022450(&r, &b, &a);
    t.x = r.x;
    t.y = r.y;
    t.z = r.z;
    t.w = r.w;
    hit = FUN_000ddd64(self, &t, flag);
    if (hit == 0)
        return 0;

    base = *(float *)(*(char **)(DAT_003386b0 + 0x88) + 0x110) * DAT_002d279c;
    if (flag != 0) {
        if (fabsf(t.x) < base + 0.5f * *(float *)(DAT_003402a0 + 0x1420))
            *(unsigned char *)(self + 0x63) = 1;
    }
    lim = (*(unsigned char *)(self + 0x45) != 0 || flag != 0) ? 4.1148f : 5.4863997f;
    float d = lim - (base + *(float *)(DAT_003402a0 + 0x1420));
    if (fabsf(t.x) > d)
        *(unsigned char *)(self + 0x63) = 1;

    lim = flag != 0 ? 6.4007998f : 11.887199f;
    float d2 = lim - (base + *(float *)(DAT_003402a0 + 0x1424));
    if (t.z > d2)
        *(unsigned char *)(self + 0x63) = 1;
    return 1;
}
// improved by lane sn7 (unreviewed): 59 -> 24 differing words
// Lane wf20261026-e01-05: 24 -> 22 with `base + 0.5f * X` in the flag block and each compare's right side in a local first (float d = lim - (base + X); if (fabsf(t.x) > d)). base stays $f3 (retail $f4); see try/lane-work/0xddf10.md for the ruled-out list.
// improved by lane wf20261026-e01-05 (unreviewed): 24 -> 22 differing words
