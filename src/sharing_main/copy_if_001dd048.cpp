/* HSTMATCH module=hstp_trans_main.prx start=0x001dd048 end=0x001dd10c symbol=FUN_001dd048 lang=c++ */
/* Clone of src/eboot/copy_if_001ce96c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* remove_copy_if over a range of object pointers with a negated predicate (i.e. copy_if): the 80-byte
   predicate functor arrives by value (pointer in t0, copied into the frame), its operator() is 0x1cef8c and
   returns int; the not1-style wrapper returns `!p(x)` as bool (retail's sltu/xori pair). Iterators are a
   one-pointer class with constructors (so the returned iterator is stored with sw, not lwc1/swc1) and
   operator!= written as !(a == b) (xor/sltiu/xori). Names provisional. */
struct Obj_001dd048;
typedef Obj_001dd048 *Elem_001dd048;
struct Iter_001dd048 {
    Elem_001dd048 *p;
    Iter_001dd048() {}
    Iter_001dd048(Elem_001dd048 *q) : p(q) {}
    Elem_001dd048 &operator*() const { return *p; }
    Iter_001dd048 &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter_001dd048 &a, const Iter_001dd048 &b) { return a.p == b.p; }
inline bool operator!=(const Iter_001dd048 &a, const Iter_001dd048 &b) { return !(a == b); }
struct Pred_001dd048;
extern "C" int FUN_001dd668(const Pred_001dd048 *self, Elem_001dd048 x);
struct Pred_001dd048 {
    int state[20];
    int operator()(Elem_001dd048 x) const { return FUN_001dd668(this, x); }
};
struct NotPred_001dd048 {
    Pred_001dd048 p;
    bool operator()(Elem_001dd048 x) const { return !p(x); }
};
extern "C" Iter_001dd048 FUN_001dd048(Iter_001dd048 first, Iter_001dd048 last, Iter_001dd048 result,
                                      NotPred_001dd048 pred)
{
    for (; first != last; ++first)
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
    return result;
}
