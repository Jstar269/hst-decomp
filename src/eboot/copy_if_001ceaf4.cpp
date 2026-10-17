/* HSTMATCH module=EBOOT.BIN start=0x001ceaf4 end=0x001cebb8 symbol=FUN_001ceaf4 lang=c++ */
/* Clone of src/eboot/copy_if_001ce96c.cpp (hstclone.py tag c31): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* remove_copy_if over a range of object pointers with a negated predicate (i.e. copy_if): the 80-byte
   predicate functor arrives by value (pointer in t0, copied into the frame), its operator() is 0x1cef8c and
   returns int; the not1-style wrapper returns `!p(x)` as bool (retail's sltu/xori pair). Iterators are a
   one-pointer class with constructors (so the returned iterator is stored with sw, not lwc1/swc1) and
   operator!= written as !(a == b) (xor/sltiu/xori). Names provisional. */
struct Obj_001ceaf4;
typedef Obj_001ceaf4 *Elem_001ceaf4;
struct Iter_001ceaf4 {
    Elem_001ceaf4 *p;
    Iter_001ceaf4() {}
    Iter_001ceaf4(Elem_001ceaf4 *q) : p(q) {}
    Elem_001ceaf4 &operator*() const { return *p; }
    Iter_001ceaf4 &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter_001ceaf4 &a, const Iter_001ceaf4 &b) { return a.p == b.p; }
inline bool operator!=(const Iter_001ceaf4 &a, const Iter_001ceaf4 &b) { return !(a == b); }
struct Pred_001ceaf4;
extern "C" int FUN_001cebb8(const Pred_001ceaf4 *self, Elem_001ceaf4 x);
struct Pred_001ceaf4 {
    int state[20];
    int operator()(Elem_001ceaf4 x) const { return FUN_001cebb8(this, x); }
};
struct NotPred_001ceaf4 {
    Pred_001ceaf4 p;
    bool operator()(Elem_001ceaf4 x) const { return !p(x); }
};
extern "C" Iter_001ceaf4 FUN_001ceaf4(Iter_001ceaf4 first, Iter_001ceaf4 last, Iter_001ceaf4 result,
                                      NotPred_001ceaf4 pred)
{
    for (; first != last; ++first)
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
    return result;
}
