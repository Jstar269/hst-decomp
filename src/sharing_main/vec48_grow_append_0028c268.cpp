/* HSTMATCH module=hstp_trans_main.prx start=0x0028c268 end=0x0028c55c symbol=FUN_0028c268 lang=c++ */
/* Clone of src/eboot/vec48_grow_append_0027af84.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vector8_grow_append_000e9074.cpp with a 48-byte element, max_size 0x5555555 and growth thresholds 0x1c71c71 / 0x38e38e2, grow helper 0x27b80c, buffer dtor 0x27b670); exact match verified; names and types await human review. */
typedef unsigned int u32;

struct E48 { float w[12]; };

struct Vec {
    E48 *beg;
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
    E48 *base;
    int saved;
} Work;

struct Tag { char v; Tag(char x) : v(x) {} };

#pragma opt_common_subs off

extern "C" void FUN_000043b4(void);
extern "C" void FUN_0028caf0(Vec *t, u32 cap, signed char c);
extern "C" void FUN_0028c954(Vec *t, int flag);

static inline void Reserve(Vec *t, u32 n, Tag g) { FUN_0028caf0(t, n, g.v); }

extern "C" void FUN_0028c268(Vec *p, int count, E48 *src)
{
    Work w;
    u32 *sel;
    u32 cap;
    u32 newcap;
    int cnt;
    E48 *dst;
    E48 *end;
    E48 *oldbeg;

    w.base = (E48 *)((char *)p + 8);
    cnt = count;
    w.t.beg = 0;
    w.t.count = 0;
    w.t.cap = 0;
    w.saved = 0;

    w.need = (u32)(p->count + cnt - p->cap);
    cap = p->cap;
    if (0x5555555u - cap < w.need) FUN_000043b4();

    if (cap < 0x1c71c71u) {
        w.cand = ((cap + 1) * 3) / 5;
        sel = (w.cand < w.need) ? &w.need : &w.cand;
        newcap = cap + *sel;
    } else if (cap < 0x38e38e2u) {
        w.cand2 = (cap + 1) >> 1;
        sel = (w.cand2 < w.need) ? &w.need : &w.cand2;
        newcap = cap + *sel;
    } else {
        newcap = 0x5555555u;
    }

    Reserve(&w.t, newcap, Tag(0));

    w.saved = p->count;
    dst = (E48 *)((char *)w.t.beg + w.saved * 48 + w.t.count * 48);

    while (cnt != 0) {
        if (dst != 0) {
            *dst = *src;
        }
        dst++;
        w.t.count++;
        cnt--;
    }

    oldbeg = p->beg;
    end = oldbeg + p->count;
    dst = (E48 *)((char *)w.t.beg + w.saved * 48);

    {
        E48 *q = dst;
        while (oldbeg < end) {
            --q;
            --end;
            if (q != 0) {
                *q = *end;
            }
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
        E48 *ob = p->beg;
        p->beg = w.t.beg;
        w.t.beg = ob;
    }
    {
        int osize = p->count;
        p->count = w.t.count;
        w.t.count = osize;
    }

    FUN_0028c954(&w.t, -1);
}
