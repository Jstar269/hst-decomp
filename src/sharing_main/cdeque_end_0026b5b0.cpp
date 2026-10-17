/* HSTMATCH module=hstp_trans_main.prx start=0x0026b5b0 end=0x0026b610 symbol=FUN_0026b5b0 lang=c++ */
/* Clone of src/eboot/cdeque_end_00118bfc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_0026b5b0;
struct Cdeque_0026b5b0;
struct Iter_0026b5b0 {
    Elem_0026b5b0 *ptr;
    Elem_0026b5b0 *beg;
    Elem_0026b5b0 *first;
    Elem_0026b5b0 *end;
    Iter_0026b5b0(Elem_0026b5b0 *p, const Cdeque_0026b5b0 *d);
};
struct Cdeque_0026b5b0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0026b5b0 *data_;
    Iter_0026b5b0 end() const { return Iter_0026b5b0(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_0026b5b0::Iter_0026b5b0(Elem_0026b5b0 *p, const Cdeque_0026b5b0 *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_0026b5b0 FUN_0026b5b0(const Cdeque_0026b5b0 *self)
{
    return self->end();
}
