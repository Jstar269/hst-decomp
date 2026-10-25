/* HSTMATCH module=EBOOT.BIN start=0x002b34fc end=0x002b3738 symbol=FUN_002b34fc lang=c++ */
struct Elem {
    int w[25];
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
void FUN_002b3c6c(It a, It b, It c);
It FUN_002b3db4(It first, It last, Bound pred);
Elem &FUN_002b39d8(const It *i);
void FUN_002b3738(Elem &a, Elem &b);
It FUN_002b42c8(It first, It last, Bound pred);
void FUN_002b4580(It first, It last);
}

extern int DAT_003030e8;

static inline int Jitter()
{
    int r = DAT_003030e8 % 5;
    if (++DAT_003030e8 > 4)
        DAT_003030e8 = -4;
    return r;
}

inline void iter_swap(It a, It b) { FUN_002b3738(FUN_002b39d8(&a), FUN_002b39d8(&b)); }

extern "C" void FUN_002b34fc(It first, It last)
{
    for (;;) {
        int n = last - first;
        if (n < 2)
            return;
        if (n < 21) {
            FUN_002b4580(first, last);
            return;
        }
        It a = first + (n / 4 + DAT_003030e8 % 5);
        if (++DAT_003030e8 >= 5)
            DAT_003030e8 = -4;
        It b = first + (n * 3 / 4 + DAT_003030e8 % 5);
        if (++DAT_003030e8 >= 5)
            DAT_003030e8 = -4;
        It back = last - 1;
        FUN_002b3c6c(a, b, back);
        It m;
        m = FUN_002b3db4(first, back, Bound(Less(), back));
        if (m == first) {
            iter_swap(It(m.p), back);
            first = FUN_002b42c8(m + 1, last, Bound(Less(), first));
        } else if (m - first < last - m) {
            FUN_002b34fc(first, m);
            first = m;
        } else {
            FUN_002b34fc(m, last);
            last = m;
        }
    }
}
// NEAR MISS (ol1 lane): 141/143 words, 108 differ. Same template as wip/introsort_loop_00279f64.cpp
// (100-byte elements); identical residue: last/m register swap (s0/s2), jitter scheduling, Less copy form.
// near miss from lane ol1 (unreviewed)
