/* HSTMATCH module=EBOOT.BIN start=0x0014f70c end=0x0014f948 symbol=FUN_0014f70c lang=c++ */
// NEAR MISS 0x0014f70c: 143/143 words, 45 differ, first at +0x18
// PRAGMAS: `opt_common_subs off` (+ `opt_propagation off` for 0x14f70c) are required by the bytes --
// with the defaults MWCC copies the 2nd argument at its first use and the whole prefix is 100+ words off.
// Recipe: work area (cand2, cand, need, pad[4], t, base, saved); the grow helper's third argument is a
// BY-VALUE one-char Tag (`struct Tag{char v; Tag(char x):v(x){}}` inside `inline Reserve(t,n,Tag g)`); its
// 16-byte temp takes the LOWEST frame slot, so the work struct must not pad its own bottom. Frame 96 with
// need/cand/cand2 at 56/52/48, t at 76, base 88, saved 92 -- retail's slots exactly.
// Remaining gap: saved-register colouring only. Retail p=s0, cap=s1, src=s2, count=s3; ours p=s3, cap=s0,
// src=s2, count=s1 -- same 143 words, same slots. Measured and ruled out 2026-10-18: all 24 declaration-order
// permutations of cap/cnt/sel/dst, `int cnt = count;` initialised in its declaration, and a named `Vec *v = p;`
// local -- every one is byte-identical to this file, so the colouring is not driven by declaration or
// initialisation order.
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
} E8;

typedef struct {
    E8 *beg;
    int count;
    int cap;
} Vec;

/* The local work area.  Its members are laid out so that the referenced ones land on the slots
   retail uses (need 56, cand 52, cand2 48, t 76..87, base 88, saved 92); z[] and pad[] are the two
   16-byte regions retail reserves below/above them but never references. */
typedef struct {
    u32 cand2;
    u32 cand;
    u32 need;
    int pad[4];
    Vec t;
    int *base;
    int saved;
} Work;

#pragma opt_common_subs off
#pragma opt_propagation off

extern "C" void FUN_000043b4(void);
extern "C" void FUN_0014fabc(Vec *t, u32 cap, signed char c);

struct Tag { char v; Tag(char x) : v(x) {} };

static inline void Reserve(Vec *t, u32 n, Tag g) { FUN_0014fabc(t, n, g.v); }
extern "C" void FUN_00011090(char *dst, char *src, int n);
extern "C" void FUN_000114c0(char *pt, int a, int n);
extern "C" void FUN_0014fa2c(Vec *t, int flag);

extern "C" void FUN_0014f70c(Vec *p, int count, int *src)
{
    Work w;
    u32 *sel;
    u32 cap;
    u32 newcap;
    int *dst;
    int n;
    int cnt;
    E8 *oldbeg;
    Vec *oldv;

    w.base = (int *)((char *)p + 8);
    cnt = count;
    w.t.beg = 0;
    w.t.count = 0;
    w.t.cap = 0;
    w.saved = 0;

    w.need = (u32)(p->count + cnt - p->cap);
    cap = p->cap;
    if (0x1fffffffu - cap < w.need) FUN_000043b4();

    if (cap < 0xaaaaaaau) {
        w.cand = ((cap + 1) * 3) / 5;
        sel = (w.cand < w.need) ? &w.need : &w.cand;
        newcap = cap + *sel;
    } else if (cap < 0x15555554u) {
        w.cand2 = (cap + 1) >> 1;
        sel = (w.cand2 < w.need) ? &w.need : &w.cand2;
        newcap = cap + *sel;
    } else {
        newcap = 0x1fffffffu;
    }

    Reserve(&w.t, newcap, Tag(0));

    w.saved = p->count;
    dst = (int *)((char *)w.t.beg + w.saved * 8 + w.t.count * 8);

    while (cnt != 0) {
        if (dst != 0) {
            dst[0] = src[0];
            dst[1] = src[1];
        }
        dst += 2;
        w.t.count++;
        cnt--;
    }

    oldbeg = p->beg;
    n = (int)((char *)(p->beg + p->count) - (char *)p->beg);
    if (n < 0) n += 7;
    n >>= 3;

    w.saved = w.saved - n;
    FUN_00011090((char *)w.t.beg + w.saved * 8, (char *)oldbeg, n * 8);
    FUN_000114c0((char *)oldbeg, 0, n * 8);

    w.t.count = w.t.count + n;
    oldv = p;
    p->count = 0;

    {
        int oldcap = p->cap;
        p->cap = w.t.cap;
        w.t.cap = oldcap;
    }
    {
        E8 *ob = p->beg;
        p->beg = w.t.beg;
        w.t.beg = ob;
    }
    {
        int osize = p->count;
        p->count = w.t.count;
        w.t.count = osize;
    }

    FUN_0014fa2c(&w.t, -1);
}
// near miss from lane ds1 (unreviewed)
