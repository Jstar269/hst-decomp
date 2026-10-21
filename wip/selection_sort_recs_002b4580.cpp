/* HSTMATCH module=EBOOT.BIN start=0x002b4580 end=0x002b46a0 symbol=FUN_002b4580 lang=c++ */
struct Rec {
    char pad[0x50];
    int key;
    char pad54[0x10];
};
struct Iter {
    Rec *p;
};
extern "C" Rec *FUN_002b39d8(Iter *);
extern "C" void FUN_002b3738(Rec *, Rec *);
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }
inline bool operator<(const Iter &a, const Iter &b) { return a.p < b.p; }

inline Iter MinElement(Iter first, Iter last)
{
    Iter result = first;
    if (first != last) {
        Iter j = first;
        ++j.p;
        for (; j != last; ++j.p) {
            if (j.p->key < result.p->key) {
                result = j;
            }
        }
    }
    return result;
}

inline void IterSwap(Iter a, Iter b)
{
    FUN_002b3738(FUN_002b39d8(&a), FUN_002b39d8(&b));
}

extern "C" void FUN_002b4580(Iter first, Iter last)
{
    if (first != last) {
        Iter lm;
        lm.p = last.p - 1;
        for (; first < lm; ++first.p) {
            Iter m = MinElement(first, last);
            if (m != first) {
                IterSwap(m, first);
            }
        }
    }
}
// NEAR MISS (75/72 words, 35 differ; sn3, ~18 compiles): selection sort over 100-byte records (key int at +0x50) with a one-pointer iterator
// struct; prologue, both loop guards, the min-search loop (j in a2, min in v1, bool-materialised `!=` via a free operator!= = !(a == b)) and the
// two out-of-line calls (0x2b39d8 = `Rec *get(Iter *)`, 0x2b3738 = swap(Rec *, Rec *)) are retail-exact. Remaining difference: retail stores the
// min iterator once with `sw v1,72(sp)` (m lives in memory at 72, written at the join, compare uses v1), then copies it with lwc1/swc1 to the
// by-value param slot 52; ours (plain struct) first writes an sret temp at 68, copies it to m (lwc1/swc1) and reloads it (lw v1,72) before the compare.
// With any user-declared ctor (Iter(){}, Iter(Rec *), both) RVO works but m is scalarised: `sw v1,52(sp)` straight into the param slot (32 words).
// Ruled out: `Iter m(Min..)`, `const Iter &m = Min..` (extra saved reg), out-param `MinElement(Iter &out,..)`, early-return, raw-pointer result + `return Iter(res)`, dtor (does not compile).
// near miss from lane sn3 (unreviewed)
