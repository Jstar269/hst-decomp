/* HSTMATCH module=EBOOT.BIN start=0x001cea30 end=0x001ceaf4 symbol=FUN_001cea30 lang=c++ */
/* Clone of src/eboot/copy_if_001ce96c.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* remove_copy_if over a range of object pointers with a negated predicate (i.e. copy_if): the 80-byte
   predicate functor arrives by value (pointer in t0, copied into the frame), its operator() is 0x1cef8c and
   returns int; the not1-style wrapper returns `!p(x)` as bool (retail's sltu/xori pair). Iterators are a
   one-pointer class with constructors (so the returned iterator is stored with sw, not lwc1/swc1) and
   operator!= written as !(a == b) (xor/sltiu/xori). Names provisional. */
struct Obj_001cea30;
typedef Obj_001cea30 *Elem_001cea30;
struct Iter_001cea30 {
    Elem_001cea30 *p;
    Iter_001cea30() {}
    Iter_001cea30(Elem_001cea30 *q) : p(q) {}
    Elem_001cea30 &operator*() const { return *p; }
    Iter_001cea30 &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter_001cea30 &a, const Iter_001cea30 &b) { return a.p == b.p; }
inline bool operator!=(const Iter_001cea30 &a, const Iter_001cea30 &b) { return !(a == b); }
struct Pred_001cea30;
extern "C" int FUN_001cee14(const Pred_001cea30 *self, Elem_001cea30 x);
struct Pred_001cea30 {
    int state[20];
    int operator()(Elem_001cea30 x) const { return FUN_001cee14(this, x); }
};
struct NotPred_001cea30 {
    Pred_001cea30 p;
    bool operator()(Elem_001cea30 x) const { return !p(x); }
};
extern "C" Iter_001cea30 FUN_001cea30(Iter_001cea30 first, Iter_001cea30 last, Iter_001cea30 result,
                                      NotPred_001cea30 pred)
{
    for (; first != last; ++first)
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
    return result;
}
