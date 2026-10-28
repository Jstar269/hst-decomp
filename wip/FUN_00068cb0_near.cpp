/* HSTMATCH module=EBOOT.BIN start=0x00068cb0 end=0x00068e54 symbol=FUN_00068cb0 lang=c++ */
typedef char *Ptr;

struct Node1 {
    char pad[16];
    void *f10;      /* +0x10 */
    void *f14;      /* +0x14 */
};

struct Node2 {
    char pad[16];
    void *f10;      /* +0x10 */
};

struct Mgr {
    char pad0[4];
    int sentinel1;          /* +4  (compared by address) */
    char pad8[4];
    Node1 *begin1;          /* +0x0c */
    char f10[4];            /* +0x10 */
    char pad14[8];
    char f1c[4];            /* +0x1c */
    int sentinel2;          /* +0x20 */
    char pad24[4];
    Node2 *begin2;          /* +0x28 */
};

extern "C" Mgr *DAT_00331c28;
extern "C" void FUN_0006abcc(void *p);
extern "C" void FUN_0006bc0c(void *p, int a);
extern "C" void FUN_0006bacc(void *p, int a);
extern "C" void FUN_000000a0(void *p);
extern "C" void FUN_00055e48(void *p, int a);
extern "C" void FUN_00053718(void *p, int a);
extern "C" void FUN_000643e8(void **it);

extern "C" void FUN_00068cb0(void)
{
    Mgr *m = DAT_00331c28;
    if (!m)
        return;

    FUN_0006abcc(m->f10);

    Node1 *it = DAT_00331c28->begin1;
    if (it != (Node1 *)&DAT_00331c28->sentinel1) {
        do {
            void **f = (void **)((char *)it + 16);
            if (f[1]) {
                FUN_00055e48(f[1], 1);
                f[1] = 0;
            }
            if (f[0]) {
                FUN_00053718(f[0], 1);
                f[0] = 0;
            }
            FUN_000643e8((void **)&it);
        } while (it != (Node1 *)&DAT_00331c28->sentinel1);
    }

    Node2 *it2 = DAT_00331c28->begin2;
    if (it2 != (Node2 *)&DAT_00331c28->sentinel2) {
        do {
            void *p = *(void **)((char *)it2 + 16);
            if (p) {
                if (p)
                    ((void (*)(void *, int))(*(void ***)p)[2])(p, 1);
                *(void **)((char *)it2 + 16) = 0;
            }
            FUN_000643e8((void **)&it2);
        } while (it2 != (Node2 *)&DAT_00331c28->sentinel2);
    }

    if (!DAT_00331c28)
        return;

    Mgr *g = DAT_00331c28;
    if (g) {
        char *a = (char *)g + 28;
        if (a) {
            char *b = (char *)g + 16;
            if (b) {
                if (b) {
                    if (b)
                        FUN_0006bc0c(b, 0);
                }
            }
        }
        char *c = (char *)g + 16;
        if (c)
            FUN_0006abcc(c);
        if (g) {
            if (g) {
                if (g)
                    FUN_0006bacc(g, 0);
            }
        }
        FUN_000000a0(g);
    }
    DAT_00331c28 = 0;
}
// Phase-3 pass 9 (2026-10-28): tail map worked to 104/105 words (45 differing). Two structural wins:
// (a) the second list's body is a NESTED check - `if (p) { if (p) vtable_call(p,1); *(it+16) = 0; }` - which is
//     exactly retail's two `beqzl a0` with different targets (inner skips only the call, outer skips the store);
// (b) the tail's triple identical `beqz` are explicit nested `if` on the same address expression
//     (a = G+28; if (a) { b = G+16; if (b) if (b) if (b) 0x6bc0c(b,0); } ... if (g) if (g) if (g) 0x6bacc(g,0))
//     - writing them as a plain call sequence loses 22 words.
// LEFT (1 word + 45 diffs): the FIRST guard. Retail has `lw a1,7208(v1); beqz a1,0x68dac` + nop (plain branch,
// value into a1, jumping FORWARD INTO the second guard's test so both exits share code), ours emits
// `lw v1; beqzl v1,<epilogue>` with `lw ra` in the delay slot. Tried: `!m`, `m == 0`, cached local vs direct
// global, both guards present - the merge into the second test never happens.
// Phase-3 pass 10 (2026-10-28): the first guard is a CFG/scheduler tie in this build. Evidence: with both guards
// present MWCC still emits `lw v1,7208(v1); beqzl v1,<epilogue>` for the first, and it DROPS the second guard
// entirely (our stream has no `beqzl a1` before the `s0 = DAT` load, retail has one at 0x68dac). Removing the
// tail's `if (g)` wrapper to force the guard out costs 2 words (102/105) and still does not produce the plain
// `beqz a1` into the shared test. Also ruled out: direct-global vs cached-local, `!m` vs `m == 0`, `if/else` form.
// near miss from lane dsn2 (unreviewed)
