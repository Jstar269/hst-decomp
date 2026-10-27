/* HSTMATCH module=EBOOT.BIN start=0x0005f6f0 end=0x0005f7d0 symbol=FUN_0005f6f0 lang=c++ rodata=0x002b9230 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct BitIt {
    unsigned *p;
    unsigned mask;
    BitIt(const BitIt &o) : p(o.p), mask(o.mask) {}
};

static inline unsigned CountLeadingZeros(unsigned x)
{
    static const unsigned char tab[16] = {4, 3, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    unsigned shift = 32;
    unsigned m = 0xf0000000;
    unsigned n = 0;
    do {
        shift -= 4;
        unsigned char t = tab[(x & m) >> shift];
        n += t;
        if (t != 4) break;
        m >>= 4;
    } while (shift != 0);
    return n;
}

template <class T> static inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }

extern "C" void FUN_0005f6f0(BitIt first, unsigned n, const bool &x)
{
    if (n == 0) return;
    unsigned v = -(unsigned)x;
    unsigned pos = CountLeadingZeros(first.mask);
    while (true) {
        unsigned k = Min(pos + 1, n);
        unsigned m = (~0u << (31 - pos)) & (~0u >> (pos + 1 - k));
        unsigned *p = first.p;
        *p &= ~m;
        *p |= v & m;
        n -= k;
        if (n == 0) break;
        ++first.p;
        pos = 31;
    }
}
