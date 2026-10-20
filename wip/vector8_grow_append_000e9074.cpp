/* HSTMATCH module=EBOOT.BIN start=0x000e9074 end=0x000e92c8 symbol=FUN_000e9074 lang=c++ */
// NEAR MISS 0x000e9074: 149/149 words, 22 differ, first at +0x18c
// PRAGMAS: `opt_common_subs off` (+ `opt_propagation off` for 0x14f70c) are required by the bytes --
// with the defaults MWCC copies the 2nd argument at its first use and the whole prefix is 100+ words off.
// Recipe: work area (cand2, cand, need, pad[4], t, base, saved); the grow helper's third argument is a
// BY-VALUE one-char Tag (`struct Tag{char v; Tag(char x):v(x){}}` inside `inline Reserve(t,n,Tag g)`); its
// 16-byte temp takes the LOWEST frame slot, so the work struct must not pad its own bottom. Frame 96 with
// need/cand/cand2 at 56/52/48, t at 76, base 88, saved 92 -- retail's slots exactly.
// Remaining gap: 22 words, same tail set-up as 0xd61fc. This twin copies the 16-byte element with
// `*q = *end`, which MWCC emits as lwc1/swc1 exactly like retail, and the fixed `E16 *q = dst - 1;`
// destination is what makes the loop body byte-exact.
typedef unsigned int u32;

struct E16 { float w[4]; };

struct Vec {
    E16 *beg;
    int count;
    int cap;
};

/* local work area: need 56, cand 52, cand2 48, t 76..87, base 88, saved 92 */
typedef struct {
    u32 cand2;
    u32 cand;
    u32 need;
    int pad[4];
    Vec t;
    E16 *base;
    int saved;
} Work;

struct Tag { char v; Tag(char x) : v(x) {} };

#pragma opt_common_subs off

extern "C" void FUN_000043b4(void);
extern "C" void FUN_000e95dc(Vec *t, u32 cap, signed char c);
extern "C" void FUN_000e93ac(Vec *t, int flag);

static inline void Reserve(Vec *t, u32 n, Tag g) { FUN_000e95dc(t, n, g.v); }

extern "C" void FUN_000e9074(Vec *p, int count, E16 *src)
{
    Work w;
    u32 *sel;
    u32 cap;
    u32 newcap;
    int cnt;
    E16 *dst;
    E16 *end;
    E16 *oldbeg;

    w.base = (E16 *)((char *)p + 8);
    cnt = count;
    w.t.beg = 0;
    w.t.count = 0;
    w.t.cap = 0;
    w.saved = 0;

    w.need = (u32)(p->count + cnt - p->cap);
    cap = p->cap;
    if (0xfffffffu - cap < w.need) FUN_000043b4();

    if (cap < 0x5555555u) {
        w.cand = ((cap + 1) * 3) / 5;
        sel = (w.cand < w.need) ? &w.need : &w.cand;
        newcap = cap + *sel;
    } else if (cap < 0xaaaaaaau) {
        w.cand2 = (cap + 1) >> 1;
        sel = (w.cand2 < w.need) ? &w.need : &w.cand2;
        newcap = cap + *sel;
    } else {
        newcap = 0xfffffffu;
    }

    Reserve(&w.t, newcap, Tag(0));

    w.saved = p->count;
    dst = (E16 *)((char *)w.t.beg + w.saved * 16 + w.t.count * 16);

    while (cnt != 0) {
        if (dst != 0) {
            dst->w[0] = src->w[0];
            dst->w[1] = src->w[1];
            dst->w[2] = src->w[2];
            dst->w[3] = src->w[3];
        }
        dst++;
        w.t.count++;
        cnt--;
    }

    oldbeg = p->beg;
    end = p->beg + p->count;
    dst = (E16 *)((char *)w.t.beg + w.saved * 16);

    {
        E16 *q = dst - 1;
        while (oldbeg < end) {
            --end;
            *q = *end;
            w.saved--;
            w.t.count++;
        }
    }

    {
        int oldcap = p->cap;
        p->cap = w.t.cap;
        w.t.cap = oldcap;
    }
    {
        E16 *ob = p->beg;
        p->beg = w.t.beg;
        w.t.beg = ob;
    }
    {
        int osize = p->count;
        p->count = w.t.count;
        w.t.count = osize;
    }

    FUN_000e93ac(&w.t, -1);
}
// near miss from lane ds1 (unreviewed)
