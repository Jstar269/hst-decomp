/* HSTMATCH module=EBOOT.BIN start=0x001ce96c end=0x001cea30 symbol=FUN_001ce96c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* remove_copy_if over a range of object pointers with a negated predicate (i.e. copy_if): the 80-byte
   predicate functor arrives by value (pointer in t0, copied into the frame), its operator() is 0x1cef8c and
   returns int; the not1-style wrapper returns `!p(x)` as bool (retail's sltu/xori pair). Iterators are a
   one-pointer class with constructors (so the returned iterator is stored with sw, not lwc1/swc1) and
   operator!= written as !(a == b) (xor/sltiu/xori). Names provisional. */
struct Obj_001ce96c;
typedef Obj_001ce96c *Elem_001ce96c;
struct Iter_001ce96c {
    Elem_001ce96c *p;
    Iter_001ce96c() {}
    Iter_001ce96c(Elem_001ce96c *q) : p(q) {}
    Elem_001ce96c &operator*() const { return *p; }
    Iter_001ce96c &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter_001ce96c &a, const Iter_001ce96c &b) { return a.p == b.p; }
inline bool operator!=(const Iter_001ce96c &a, const Iter_001ce96c &b) { return !(a == b); }
struct Pred_001ce96c;
extern "C" int FUN_001cef8c(const Pred_001ce96c *self, Elem_001ce96c x);
struct Pred_001ce96c {
    int state[20];
    int operator()(Elem_001ce96c x) const { return FUN_001cef8c(this, x); }
};
struct NotPred_001ce96c {
    Pred_001ce96c p;
    bool operator()(Elem_001ce96c x) const { return !p(x); }
};
extern "C" Iter_001ce96c FUN_001ce96c(Iter_001ce96c first, Iter_001ce96c last, Iter_001ce96c result,
                                      NotPred_001ce96c pred)
{
    for (; first != last; ++first)
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
    return result;
}
