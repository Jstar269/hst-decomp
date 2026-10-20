/* HSTMATCH module=EBOOT.BIN start=0x001cd970 end=0x001cd9c0 symbol=FUN_001cd970 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* std::remove_copy over a range of object pointers owned by one Parent (0x1cd5a0 passes its found slot):
   the iterator is a one-pointer class whose user constructors make the returned copy a plain `sw` to the
   hidden return slot, and operator!= is the MSL `!(a == b)` form (xor/sltiu/xori). */
struct Obj;
struct Iter {
    Obj **p;
    Iter() {}
    Iter(Obj **q) : p(q) {}
    Iter &operator++() { ++p; return *this; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }
inline Obj *&operator*(const Iter &it) { return *it.p; }

extern "C" Iter FUN_001cd970(Iter first, Iter last, Iter out, Obj *const &value)
{
    for (; first != last; ++first)
        if (*first != value) {
            *out = *first;
            ++out;
        }
    return out;
}
