/* HSTMATCH module=hstp_trans_main.prx start=0x0010fa68 end=0x0010faf0 symbol=FUN_0010fa68 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* upper_bound over a range of object pointers ordered by the float at +0x20 (largest first, comparator functor
   `Greater`); the result iterator is returned through the hidden pointer in a0 and the empty comparator is passed by
   value (retail's 32-byte frame). Matching idiom: Distance() takes its first iterator as the plain-struct
   const-iterator type CIt (converted from It by a conversion operator), which is what makes retail spill `first` and
   copy it through the stack (sw/lwc1/swc1/lw) for `last - first`; two plain It parameters are optimised into
   registers. Twin of 0x10faf0 (lower_bound). Names provisional. */
struct Obj {
    char pad[0x20];
    float key;
};
struct CIt {
    Obj **p;
};
struct It {
    Obj **p;
    It() {}
    It(Obj **q) : p(q) {}
    operator CIt() const
    {
        CIt c;
        c.p = p;
        return c;
    }
};
struct Greater {
    bool operator()(Obj *a, Obj *b) const { return a->key > b->key; }
};
inline int Distance(CIt first, It last) { return last.p - first.p; }
inline It UpperBound(It first, It last, Obj *const *val, Greater comp)
{
    int len = Distance(first, last);
    while (len > 0) {
        int half = len / 2;
        Obj **mid = first.p + half;
        if (!comp(*val, *mid)) {
            first.p = mid + 1;
            len = len - (half + 1);
        } else {
            len = half;
        }
    }
    return It(first.p);
}
extern "C" It FUN_0010fa68(It first, It last, Obj *const *val, Greater comp)
{
    return UpperBound(first, last, val, comp);
}
