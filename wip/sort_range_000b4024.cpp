/* HSTMATCH module=EBOOT.BIN start=0x000b4024 end=0x000b41b8 symbol=FUN_000b4024 lang=c++ */
struct Rec {
    float f[14];
    float key;
    float g[5];
} __attribute__((aligned(16)));

struct It {
    Rec *p;
    It(Rec *q) : p(q) {}
    It &operator=(const It &o) { p = o.p; return *this; }
};
struct Buf;
struct BufIt {
    Rec *p;
    Buf *owner;
    BufIt(Rec *q, Buf *b) : p(q), owner(b) {}
    BufIt(const BufIt &o) : p(o.p), owner(o.owner) {}
};
struct Pair {
    Rec *ptr;
    int count;
};
extern "C" {
Rec *FUN_000b42ac(It *);
void FUN_000b41b8(Rec *, Rec *);
void FUN_000b4578(Rec *, Rec *, char);
void FUN_000b4710(Rec *, Rec *, BufIt *, BufIt *, char);
void FUN_000b44e4(Pair *, int);
void FUN_000009e4(void *);
}
struct Buf {
    int len;
    int used;
    Rec *ptr;
    Buf(int n)
    {
        Pair pr;
        FUN_000b44e4(&pr, n);
        len = pr.count;
        used = 0;
        ptr = pr.ptr;
    }
    ~Buf() { FUN_000009e4(ptr); }
    BufIt begin() { return BufIt(ptr, this); }
    BufIt end() { return BufIt(ptr + len, this); }
};
inline bool Less(Rec a, Rec b) { return a.key < b.key; }
inline void Swap(It a, It b)
{
    Rec *x = FUN_000b42ac(&a);
    Rec *y = FUN_000b42ac(&b);
    FUN_000b41b8(x, y);
}

extern "C" void FUN_000b4024(It first, Rec *last, int flag)
{
    int n = last - first.p;
    if (n > 1) {
        if (n == 2) {
            Rec *back = last - 1;
            if (Less(*back, *first.p)) {
                Swap(first, It(back));
            }
        } else if (n < 21) {
            FUN_000b4578(first.p, last, flag);
        } else {
            Buf buf(n);
            BufIt bb = buf.begin();
            BufIt be = buf.end();
            FUN_000b4710(first.p, last, &bb, &be, flag);
        }
    }
}
// lane wf20261026-e01-03: 67 -> 55 words. iter_swap is an inline Swap(It a, It b) with It(Rec*) ctor
// (copies first from its home like retail); variant try/lane-work/b/b4024_6.cpp (Swap(It a, Rec *q){It b(q);..})
// reproduces retail's n==2 block shape exactly but offsets/regs shift (66 words).
// Open: params retail first=s0,last=s1,flag=s2 with n computed from a0/a1 before the copies; MWCC
// always gives scalar params first->highest s-reg (toy probes try/lane-work/sreg/t1-t5: use count,
// use order, K&R decl order, register, local copies, inline wrapper all invariant).
// improved by lane wf20261026-e01-03 (unreviewed): 67 -> 55 differing words
