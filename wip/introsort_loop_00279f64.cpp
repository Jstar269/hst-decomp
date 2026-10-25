/* HSTMATCH module=EBOOT.BIN start=0x00279f64 end=0x0027a190 symbol=FUN_00279f64 lang=c++ */
struct Elem {
    int w[12];
};
struct It {
    Elem *p;
    It() {}
    It(Elem *q) : p(q) {}
    It operator+(int n) const { return It(p + n); }
    It operator-(int n) const { return It(p - n); }
};
inline int operator-(const It &a, const It &b) { return a.p - b.p; }
inline bool operator==(const It &a, const It &b) { return a.p == b.p; }

struct Less {
    unsigned char unused;
    Less() {}
};
struct Bound {
    Less comp;
    It value;
    Bound(const Less &c, const It &v) : comp(c), value(v) {}
    Bound(const Bound &o) : comp(o.comp), value(o.value) {}
};

extern "C" {
void FUN_0027a658(It a, It b, It c);
It FUN_0027a7a0(It first, It last, Bound pred);
Elem &FUN_0027a2ec(const It *i);
void FUN_0027a190(Elem &a, Elem &b);
It FUN_0027abac(It first, It last, Bound pred);
void FUN_0027ae64(It first, It last);
}

extern int DAT_002fe6a8;

static inline int Jitter()
{
    int r = DAT_002fe6a8 % 5;
    if (++DAT_002fe6a8 > 4)
        DAT_002fe6a8 = -4;
    return r;
}

inline void iter_swap(It a, It b) { FUN_0027a190(FUN_0027a2ec(&a), FUN_0027a2ec(&b)); }

extern "C" void FUN_00279f64(It first, It last)
{
    for (;;) {
        int n = last - first;
        if (n < 2)
            return;
        if (n < 21) {
            FUN_0027ae64(first, last);
            return;
        }
        It a = first + (n / 4 + DAT_002fe6a8 % 5);
        if (++DAT_002fe6a8 >= 5)
            DAT_002fe6a8 = -4;
        It b = first + (n * 3 / 4 + DAT_002fe6a8 % 5);
        if (++DAT_002fe6a8 >= 5)
            DAT_002fe6a8 = -4;
        It back = last - 1;
        FUN_0027a658(a, b, back);
        It m;
        m = FUN_0027a7a0(first, back, Bound(Less(), back));
        if (m == first) {
            iter_swap(It(m.p), back);
            first = FUN_0027abac(m + 1, last, Bound(Less(), first));
        } else if (m - first < last - m) {
            FUN_00279f64(first, m);
            first = m;
        } else {
            FUN_00279f64(m, last);
            last = m;
        }
    }
}
// NEAR MISS (ol1 lane): 137/139 words, 104 differ (mostly register/scheduling shift).
// Structure is right (frame 112, 4 saved regs, Bound{Less,It} with user copy ctor passed by invisible ref,
// iter_swap(It(m.p), back) gives retail's prvalue copy for m and direct store for back).
// Differs: (1) retail keeps last in s0 and m in s2 (ours last s2, m s0); declaration order of m/back
//   (top of function, in loop, assigned vs initialised, const& m) did not change it.
// (2) jitter: retail finishes first+(n/4+G%5) before the wrap test and computes n*3/4 before the 2nd G%5;
//   inline Jitter() is evaluated before n/4; open-coded `++G >= 5` statements are closest.
// (3) retail copies Less via `addiu v0,sp,84; lbu 0(v0)`; ours folds to lbu 80(sp); Bound slots 4 lower.
// near miss from lane ol1 (unreviewed)
