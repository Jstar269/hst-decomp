/* HSTMATCH module=EBOOT.BIN start=0x000b4024 end=0x000b41b8 symbol=FUN_000b4024 lang=c++ */
struct Rec {
    float f[14];
    float key;
    float g[5];
} __attribute__((aligned(16)));

struct It {
    Rec *p;
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

extern "C" void FUN_000b4024(It first, Rec *last, int flag)
{
    int n = last - first.p;
    if (n > 1) {
        if (n == 2) {
            Rec *back = last - 1;
            if (Less(*back, *first.p)) {
                It a = first;
                It b;
                b.p = back;
                Rec *x = FUN_000b42ac(&a);
                Rec *y = FUN_000b42ac(&b);
                FUN_000b41b8(x, y);
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
// lane sn6: 66 of 101 words differ, but the structure is retail's (std-style sort of 80-byte records keyed by the float at +0x38): n = (last-first)/0x50; n<2 nothing; n==2 `Less(*(last-1), *first)`
// with BY-VALUE Rec params (two 80-byte block copies, 10 x lw/lw/sw/sw) then iter_swap through two stack iterators (FUN_000b42ac = operator*, FUN_000b41b8 = swap); n<=20 insertion sort
// FUN_000b4578(first,last,flag); else Temporary_buffer (FUN_000b44e4 pair -> Buf{len,0,ptr}, begin/end 8-byte iterators {p, &Buf} with a user copy ctor so they go by reference)
// + FUN_000b4710(first,last,&begin,&end,flag) + delete[] FUN_000009e4(ptr). flag reaches the callees through `seb` (int param, char callee).
// Found so far: `It` needs a user operator= (that is what makes retail store the by-value param home `sw a0,20(sp)` and copy it with lwc1/swc1); `Rec *back = last - 1` computed once
// (retail reuses s1 for it); Buf must have a user dtor calling FUN_000009e4(ptr) with NO null test.
// Open: (1) saved registers: retail first=s0,last=s1,flag=s2 with `move s2,a2` in the first bnez slot and n computed in a3 (flag copy late; B calls seb a2,a2 directly); ours copies flag first
// (s1) and last (s2), so n lands in a2 and the whole prologue/schedule shifts; (2) frame: retail iterators a/b at 200/196, pair 204, end 212, begin 220, Buf 228 (declared Buf,begin,end,pair
// from the top), param home at 20; ours puts them elsewhere. Tried: int/char/signed char flag, both params as It, operator- on const refs, if-chain order inverted (C first).
// near miss from lane sn6 (unreviewed)
