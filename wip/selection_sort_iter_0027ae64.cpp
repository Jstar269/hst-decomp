/* HSTMATCH module=EBOOT.BIN start=0x0027ae64 end=0x0027af84 symbol=FUN_0027ae64 lang=c++ */
struct Elem {
    char pad0[16];
    int key;
    char pad1[28];
};

struct It {
    Elem *p;
    It() {}
    It(Elem *q) : p(q) {}
    Elem &operator*();
    It &operator++() { ++p; return *this; }
};

extern "C" void FUN_0027a190(Elem *a, Elem *b);
extern "C" Elem *FUN_0027a2ec(It *it);

inline bool operator==(const It &a, const It &b) { return a.p == b.p; }
inline bool operator!=(const It &a, const It &b) { return !(a == b); }
inline bool operator<(const It &a, const It &b) { return a.p < b.p; }

inline It MinElement(It first, It last)
{
    It result = first;
    if (first != last) {
        ++first;
        while (first != last) {
            if (first.p->key < result.p->key) result = first;
            ++first;
        }
    }
    return result;
}

inline void IterSwap(It a, It b)
{
    FUN_0027a190(FUN_0027a2ec(&a), FUN_0027a2ec(&b));
}

extern "C" void FUN_0027ae64(It first, It last)
{
    if (first != last) {
        It lim(last.p - 1);
        for (It i = first; i < lim; ++i) {
            It m = MinElement(i, last);
            if (m != i) IterSwap(m, i);
        }
    }
}
// PARKED (lane sn2, ~40 compiles): selection sort over 48-byte records (int key at +0x10) with a one-pointer iterator class It
// (ctors It(){}, It(Elem*), inline ++, free == and != = !(a==b) => xor/sltiu/xori); out-of-line operator* = FUN_0027a2ec(It*) (8 bytes, lw v0,0(a0)),
// swap = FUN_0027a190(Elem*,Elem*). Structure verified word-for-word for the whole min-search loop and the outer loop; a/b slots (52/48) match
// with `first` modified in place (++first). 61 of 72 words still differ because of: (1) retail keeps the min iterator m MEMORY-resident
// (`sw v1,72(sp)` at the join, `xor v1,v1,s3` on the register, copy `lwc1 f0,72(sp); swc1 f0,52(sp)` into the by-value param) whereas
// the ctor-world It is scalarised (`sw v1,52(sp)` direct); (2) prologue: retail `move s3,a0` before the first beqz, first test is a likely
// branch with `lw ra` in its slot, extra copy s2=last. Findings: without ctors (POD It) m is memory-resident but via temp(68)+copy(72) and a
// reload (74 words); `const It &m = MinElement(i,last)` gives retail's direct `sw v1,72(sp)` with no temp but needs an address register
// (`addiu s0,sp,72`, lwc1 f0,0(s0); with #pragma opt_loop_invariants off: addiu a0,sp,72; lwc1 f0,0(a0)); an out-parameter version, a CIt
// conversion operator (lower_bound idiom) and a destructor are all worse. Open question: what makes a returned inline class value memory-resident
// WITHOUT the temp copy and without a reference.
// near miss from lane sn2 (unreviewed)
