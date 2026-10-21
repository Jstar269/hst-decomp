/* HSTMATCH module=EBOOT.BIN start=0x001091d4 end=0x001095b8 symbol=FUN_001091d4 lang=c++ */
/* Hand-written reconstruction from the disassembly; NEAR MISS (249/249 words, 105 differ: frame 144 vs 176, stack offsets and saved registers; see trailing comments); names and types await human review. */
struct T {
    char pad[0x20];
    float v;
};
struct Cont {
    int pad0;
    int size;
    T **begin;
};
struct Ref {
    T **cur;
    Cont *c;
    int pad;
    Ref(T **a, Cont *b) : cur(a), c(b) {}
    Ref &operator=(T *const &v)
    {
        if (cur - c->begin < c->size) {
            *cur = v;
        } else {
            if (cur != 0) {
                *cur = v;
            }
            c->size = c->size + 1;
        }
        return *this;
    }
};
struct Ref16 {
    T **cur;
    Cont *c;
    int pad;
    Ref16(T **a, Cont *b) : cur(a), c(b) {}
    Ref16 &operator=(T *const &v)
    {
        if (cur - c->begin < c->size) {
            *cur = v;
        } else {
            if (cur != 0) {
                *cur = v;
            }
            c->size = c->size + 1;
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct Out {
    T **cur;
    Cont *c;
    Ref operator*() { return Ref(cur, c); }
    Ref16 Deref() { return Ref16(cur, c); }
    Out &operator++()
    {
        cur = cur + 1;
        return *this;
    }
};

static inline Out MakeOut(T **cur, Cont *c)
{
    Out r;
    r.cur = cur;
    r.c = c;
    return r;
}

extern "C" {
void FUN_001076c8(T **, T **, char);
void FUN_00107750(T **, T **, const Out &, const Out &, char);
Out FUN_00109a20(T **, T **, T **, T **, const Out &, char);
}

static inline bool Eq(T **a, T **b) { return a == b; }
static inline bool Ne(T **a, T **b) { return !Eq(a, b); }

static inline void Put(Out &o, T *v)
{
    *o = v;
}

static inline Out CopyFwd(T **first, T **last, Out out)
{
    for (; Ne(first, last); ++first) {
        out.Deref() = *first;
        ++out;
    }
    return out;
}

static inline Out CopyRev(T **first, T **last, Out out)
{
    while (Ne(first, last)) {
        --last;
        out.Deref() = *last;
        ++out;
    }
    return out;
}

extern "C" void FUN_001091d4(T **first, T **last, Out in, int flag)
{
    int n = last - first;
    if (n > 0) {
        if (n == 1) {
            *in = *first;
            return;
        }
        if (n == 2) {
            if (last[-1]->v > first[0]->v) {
                CopyRev(first, last, in);
            } else {
                CopyFwd(first, last, in);
            }
            return;
        }
        if (n < 21) {
            FUN_001076c8(first, last, flag);
            CopyFwd(first, last, in);
            return;
        }
        int half = n - n / 2;
        T **mid = first + half;
        FUN_00107750(first, mid, in, MakeOut(in.cur + half, in.c), flag);
        FUN_00107750(mid, last, MakeOut(in.cur + half, in.c), MakeOut(in.cur + n, in.c), flag);
        FUN_00109a20(first, mid, mid, first + n, in, flag);
    }
}

// sn1 NEAR (249/249 words = same length as retail; 109 words differ, all frame offsets / saved-register naming / a few delay-slot orders).
// What it took: (1) `*out = *first; ++out;` is an assignment PROXY: `Out::operator*()` returns a small class BY VALUE whose `operator=(T *const &v)` does the bounds-checked store
// (`if (cur - c->begin < c->size) *cur = v; else { if (cur) *cur = v; c->size = c->size + 1; }`); the proxy temporary is the memory-resident `sw cur,156(sp); sw c,160(sp)` object that
// retail reloads; taking the value by const reference loads `*first` lazily inside each branch. (2) The byte-for-byte loop shapes need the three copy loops inside INLINE functions that
// return `Out` by value (`CopyFwd`/`CopyRev`, `for (; Ne(first, last); ++first) { *out = *first; ++out; } return out;` with Ne = !Eq on raw pointers), and the n==1 / n==2 / n<21 / else
// branches written as `if (...) { ...; return; }` blocks (retail's `b EPILOGUE; nop` unfilled tails are those inline returns). (3) `in` is used directly as the callee-copied by-value parameter (a second
// `Out o = in;` doubles the copy); B, C, D are temporaries `MakeOut(in.cur + half, in.c)` passed as `const Out &` (retail's contiguous 8-byte objects 148/140/132 and the merge call's return slot 124).
// Open: retail's frame is 176 (ours 144): the n==1 proxy is a 12-byte 4-aligned object directly below the parameter copy (`int pad` third member, constructor `Ref(cur, c)`), the three loop proxies are
// 16-BYTE ALIGNED objects (96/80/64) and two more unused 16-aligned slots (48, 32) follow; ours reproduces the 16-aligned spacing with a separate `Ref16` class (aligned(16)) used via `out.Deref()` in the
// loops but not the two extra slots. Register naming: retail first=s5, last=s1, n=s2, flag=s0, mid=s3, half*4=s4.
// sn1 later pass: the n==2 test is `last[-1]->v > first[0]->v` (c.ngt.s f1,f0; bc1tl: variable on the left) and the parameter `flag` must be `int` (a `char` parameter passes
// to the `char` callees as a bare `move`; retail has `seb a2,s0` at every call, which needs the wider incoming type); `bool`/`unsigned char` parameters break the match (228 differ).
// Remaining after those (105 differ): frame 144 vs 176 / stack offsets, and the saved registers (retail first=s5, last=s1, n=s2, mid=s3, half*4=s4, flag=s0; ours first=s2, n=s3, mid=s5).
// near miss from lane sn1 (unreviewed)
