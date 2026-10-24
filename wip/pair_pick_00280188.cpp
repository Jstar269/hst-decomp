/* HSTMATCH module=EBOOT.BIN start=0x00280188 end=0x002803d8 symbol=FUN_00280188 lang=c++ */
// NEAR 1/148: everything matches except the two push sites' third argument.
// Retail: "move v0,zero; seb a2,v0; addiu a0,..; jal FUN_000545bc; addiu a1,.."
// Ours:   "addiu a0,..; addiu a1,..; jal FUN_000545bc; move a2,zero"  (1 word shorter per site)
// Ruled out: int/char/signed char/unsigned char prototypes, (char)0, char and int
// locals holding 0 (all fold to "move a2,zero"), and a char parameter local assigned 0.
// The "seb" needs an int-typed expression narrowed to char that is only folded to 0 late,
// which no plain constant spelling reproduces.
// Levers that did work: "i = 0; n = FUN_000650e0(*obj); for (; i < n; i++)" puts the
// zeroing in the jal delay slot and keeps i in s0 (a plain for(i=0;..) instead specialised
// the first iteration with a literal 0 and dropped s5); hoisting the survivor count into a
// local ("cnt = a.size") keeps it in s0 across FUN_0001342c instead of reloading it; and a
// fresh local for the returned element keeps it in s0 across both FUN_00054600 calls
// (reusing the loop's v spilled it to the stack).*/

struct False_280188 {};

struct Vec_280188 {
    int *p;            /* 0x00 */
    unsigned size;     /* 0x04 */
    unsigned cap;      /* 0x08 */
};

extern "C" {
extern char DAT_002fe8cc[];
extern void FUN_00286490(struct Vec_280188 *v, int n);
extern int FUN_000650e0(int obj);
extern int FUN_00065104(int obj, int idx, int sub);
extern int FUN_0006517c(int obj, int idx, int sub);
extern void FUN_002803d8(char *fmt, ...);
extern void FUN_000545bc(struct Vec_280188 *v, int *val, int flag);
extern void FUN_00054600(struct Vec_280188 *v, int flag);
extern unsigned FUN_0001342c(void);
extern unsigned char FUN_0000d62c(int v);
}

extern "C" int FUN_00280188(int *obj, unsigned char *out, int want, int sub, False_280188)
{
    struct Vec_280188 a;
    struct Vec_280188 b;
    int i, n;
    int v, w, res;
    unsigned cnt, r;

    a.p = 0;
    a.size = 0;
    a.cap = 0;
    b.p = 0;
    b.size = 0;
    b.cap = 0;
    if (a.cap < 0x20)
        FUN_00286490(&a, 0x20);
    if (b.cap < 0x20)
        FUN_00286490(&b, 0x20);

    i = 0;
    n = FUN_000650e0(*obj);
    for (; i < n; i++) {
        FUN_002803d8(DAT_002fe8cc, FUN_00065104(*obj, i, 0),
                     FUN_0006517c(*obj, i, sub + 2));
        if (want == FUN_00065104(*obj, i, 0)) {
            v = FUN_0006517c(*obj, i, sub + 2);
            if (a.size < a.cap) {
                a.size = a.size + 1;
                *(int *)((char *)a.p + a.size * 4 - 4) = v;
            } else {
                FUN_000545bc(&a, &v, 0);
            }
            w = FUN_0006517c(*obj, i, 1);
            if (b.size < b.cap) {
                b.size = b.size + 1;
                *(int *)((char *)b.p + b.size * 4 - 4) = w;
            } else {
                FUN_000545bc(&b, &w, 0);
            }
        }
        n = FUN_000650e0(*obj);
    }

    cnt = a.size;
    if (cnt == 0 || b.size == 0) {
        FUN_00054600(&b, 0);
        FUN_00054600(&a, 0);
        return 0;
    }
    {
        r = FUN_0001342c() % cnt;
        *out = FUN_0000d62c(b.p[r] + 5);
        res = a.p[r];
        FUN_00054600(&b, 0);
        FUN_00054600(&a, 0);
        return res;
    }
}
// near miss from lane fm7 (unreviewed)
