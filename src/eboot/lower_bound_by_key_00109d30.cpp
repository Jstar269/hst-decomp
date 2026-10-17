/* HSTMATCH module=EBOOT.BIN start=0x00109d30 end=0x00109db8 symbol=FUN_00109d30 lang=c++ */
/* Clone of src/sharing_main/lower_bound_by_key_0010faf0.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* lower_bound over a range of object pointers ordered by the float at +0x20 (largest first, comparator functor
   `Greater`); twin of 0x10fa68 (upper_bound) with the same stack-copy idiom: Distance() takes its first iterator as
   the plain-struct const-iterator type CIt (converted from It by a conversion operator), so retail spills `first`
   and copies it through the stack for `last - first`, and the empty comparator is passed by value (32-byte frame).
   Names provisional. */
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
inline It LowerBound(It first, It last, Obj *const *val, Greater comp)
{
    int len = Distance(first, last);
    while (len > 0) {
        int half = len / 2;
        Obj **mid = first.p + half;
        if (comp(*mid, *val)) {
            first.p = mid + 1;
            len = len - (half + 1);
        } else {
            len = half;
        }
    }
    return It(first.p);
}
extern "C" It FUN_00109d30(It first, It last, Obj *const *val, Greater comp)
{
    return LowerBound(first, last, val, comp);
}
