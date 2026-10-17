/* HSTMATCH module=EBOOT.BIN start=0x00118bfc end=0x00118c5c symbol=FUN_00118bfc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_00118bfc;
struct Cdeque_00118bfc;
struct Iter_00118bfc {
    Elem_00118bfc *ptr;
    Elem_00118bfc *beg;
    Elem_00118bfc *first;
    Elem_00118bfc *end;
    Iter_00118bfc(Elem_00118bfc *p, const Cdeque_00118bfc *d);
};
struct Cdeque_00118bfc {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00118bfc *data_;
    Iter_00118bfc end() const { return Iter_00118bfc(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_00118bfc::Iter_00118bfc(Elem_00118bfc *p, const Cdeque_00118bfc *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_00118bfc FUN_00118bfc(const Cdeque_00118bfc *self)
{
    return self->end();
}
