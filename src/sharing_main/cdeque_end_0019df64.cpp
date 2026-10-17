/* HSTMATCH module=hstp_trans_main.prx start=0x0019df64 end=0x0019dfc4 symbol=FUN_0019df64 lang=c++ */
/* Clone of src/eboot/cdeque_end_00118bfc.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_0019df64;
struct Cdeque_0019df64;
struct Iter_0019df64 {
    Elem_0019df64 *ptr;
    Elem_0019df64 *beg;
    Elem_0019df64 *first;
    Elem_0019df64 *end;
    Iter_0019df64(Elem_0019df64 *p, const Cdeque_0019df64 *d);
};
struct Cdeque_0019df64 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0019df64 *data_;
    Iter_0019df64 end() const { return Iter_0019df64(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_0019df64::Iter_0019df64(Elem_0019df64 *p, const Cdeque_0019df64 *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_0019df64 FUN_0019df64(const Cdeque_0019df64 *self)
{
    return self->end();
}
