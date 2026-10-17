/* HSTMATCH module=EBOOT.BIN start=0x00191754 end=0x001917b4 symbol=FUN_00191754 lang=c++ */
/* Clone of src/eboot/cdeque_end_00118bfc.cpp (hstclone.py tag c36): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_00191754;
struct Cdeque_00191754;
struct Iter_00191754 {
    Elem_00191754 *ptr;
    Elem_00191754 *beg;
    Elem_00191754 *first;
    Elem_00191754 *end;
    Iter_00191754(Elem_00191754 *p, const Cdeque_00191754 *d);
};
struct Cdeque_00191754 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00191754 *data_;
    Iter_00191754 end() const { return Iter_00191754(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_00191754::Iter_00191754(Elem_00191754 *p, const Cdeque_00191754 *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_00191754 FUN_00191754(const Cdeque_00191754 *self)
{
    return self->end();
}
