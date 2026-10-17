/* HSTMATCH module=hstp_trans_main.prx start=0x001dd10c end=0x001dd1d0 symbol=FUN_001dd10c lang=c++ */
/* Clone of src/eboot/copy_if_001ce96c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* remove_copy_if over a range of object pointers with a negated predicate (i.e. copy_if): the 80-byte
   predicate functor arrives by value (pointer in t0, copied into the frame), its operator() is 0x1cef8c and
   returns int; the not1-style wrapper returns `!p(x)` as bool (retail's sltu/xori pair). Iterators are a
   one-pointer class with constructors (so the returned iterator is stored with sw, not lwc1/swc1) and
   operator!= written as !(a == b) (xor/sltiu/xori). Names provisional. */
struct Obj_001dd10c;
typedef Obj_001dd10c *Elem_001dd10c;
struct Iter_001dd10c {
    Elem_001dd10c *p;
    Iter_001dd10c() {}
    Iter_001dd10c(Elem_001dd10c *q) : p(q) {}
    Elem_001dd10c &operator*() const { return *p; }
    Iter_001dd10c &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter_001dd10c &a, const Iter_001dd10c &b) { return a.p == b.p; }
inline bool operator!=(const Iter_001dd10c &a, const Iter_001dd10c &b) { return !(a == b); }
struct Pred_001dd10c;
extern "C" int FUN_001dd4f0(const Pred_001dd10c *self, Elem_001dd10c x);
struct Pred_001dd10c {
    int state[20];
    int operator()(Elem_001dd10c x) const { return FUN_001dd4f0(this, x); }
};
struct NotPred_001dd10c {
    Pred_001dd10c p;
    bool operator()(Elem_001dd10c x) const { return !p(x); }
};
extern "C" Iter_001dd10c FUN_001dd10c(Iter_001dd10c first, Iter_001dd10c last, Iter_001dd10c result,
                                      NotPred_001dd10c pred)
{
    for (; first != last; ++first)
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
    return result;
}
