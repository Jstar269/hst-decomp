/* HSTMATCH module=EBOOT.BIN start=0x00118e90 end=0x00118ef0 symbol=FUN_00118e90 lang=c++ */
/* Clone of src/eboot/cdeque_end_00118bfc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_00118e90;
struct Cdeque_00118e90;
struct Iter_00118e90 {
    Elem_00118e90 *ptr;
    Elem_00118e90 *beg;
    Elem_00118e90 *first;
    Elem_00118e90 *end;
    Iter_00118e90(Elem_00118e90 *p, const Cdeque_00118e90 *d);
};
struct Cdeque_00118e90 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00118e90 *data_;
    Iter_00118e90 end() const { return Iter_00118e90(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_00118e90::Iter_00118e90(Elem_00118e90 *p, const Cdeque_00118e90 *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_00118e90 FUN_00118e90(const Cdeque_00118e90 *self)
{
    return self->end();
}
