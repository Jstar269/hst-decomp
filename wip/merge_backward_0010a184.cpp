/* HSTMATCH module=EBOOT.BIN start=0x0010a184 end=0x0010a340 symbol=FUN_0010a184 lang=c++ */
#pragma opt_strength_reduction off

extern "C" void *FUN_000111c0(void *dst, const void *src, unsigned n);

struct Obj {
    char pad[0x20];
    float key;
};

struct It {
    Obj **p;
    It() {}
    It(Obj **q) : p(q) {}
};

struct TempBuf;

struct TempBufIter {
    Obj **p;
    TempBuf *buf;
};

inline It copy_backward(TempBufIter first, TempBufIter last, It result) {
    Obj **cur = last.p;
    Obj **end = first.p;
    if (cur == end)
        return result;
    do {
        --cur;
        --result.p;
        *result.p = *cur;
    } while (cur != end);
    return result;
}

inline It copy_backward(Obj **first, Obj **last, It result) {
    int n = last - first;
    result.p -= n;
    FUN_000111c0(result.p, first, n * sizeof(Obj *));
    return result;
}

extern "C" It FUN_0010a184(Obj **first1, Obj **last1, const TempBufIter &first2_in, const TempBufIter &last2_in, It result) {
    TempBufIter first2 = first2_in;
    TempBufIter last2 = last2_in;

    if (first1 == last1)
        return copy_backward(first2, last2, result);
    if (first2.p == last2.p)
        return copy_backward(first1, last1, result);
    --last1;
    --last2.p;
    while (true) {
        bool b = (*last2.p)->key > (*last1)->key;
        if (b) {
            --result.p;
            *result.p = *last1;
            if (first1 == last1) {
                ++last2.p;
                return copy_backward(first2, last2, result);
            }
            --last1;
        } else {
            --result.p;
            *result.p = *last2.p;
            if (first2.p == last2.p) {
                ++last1;
                return copy_backward(first1, last1, result);
            }
            --last2.p;
        }
    }
}
// Differing words: 90 / 111
// Identified as STL MSL __merge_backward over Obj** range and TempBufIter range with Greater float comparator (field 0x20).
// Frame 64 matched, prologue matched (all 11 instructions), memmove and inner copy loop matched.
// Differs in register allocation (a2 vs v1 for comp bool), spilling last1 at 24(sp) in the prologue, and copy_backward branch scheduling.
// near miss from lane ag4 (unreviewed)
