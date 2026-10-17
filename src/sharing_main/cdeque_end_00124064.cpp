/* HSTMATCH module=hstp_trans_main.prx start=0x00124064 end=0x001240c4 symbol=FUN_00124064 lang=c++ */
/* Clone of src/eboot/cdeque_end_00118bfc.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_00124064;
struct Cdeque_00124064;
struct Iter_00124064 {
    Elem_00124064 *ptr;
    Elem_00124064 *beg;
    Elem_00124064 *first;
    Elem_00124064 *end;
    Iter_00124064(Elem_00124064 *p, const Cdeque_00124064 *d);
};
struct Cdeque_00124064 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00124064 *data_;
    Iter_00124064 end() const { return Iter_00124064(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_00124064::Iter_00124064(Elem_00124064 *p, const Cdeque_00124064 *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_00124064 FUN_00124064(const Cdeque_00124064 *self)
{
    return self->end();
}
