/* HSTMATCH module=hstp_trans_main.prx start=0x00123dd0 end=0x00123e30 symbol=FUN_00123dd0 lang=c++ */
/* Clone of src/eboot/cdeque_end_00118bfc.cpp (hstclone.py tag c37): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: end() const, returned by value through the hidden
   pointer. The iterator constructor initialises first_ from the beg_ register and end_ by re-reading the
   stored beg_ member (`end_(beg_ + d->cap_)`), which gives retail's reload from the result. Names provisional. */
typedef int Elem_00123dd0;
struct Cdeque_00123dd0;
struct Iter_00123dd0 {
    Elem_00123dd0 *ptr;
    Elem_00123dd0 *beg;
    Elem_00123dd0 *first;
    Elem_00123dd0 *end;
    Iter_00123dd0(Elem_00123dd0 *p, const Cdeque_00123dd0 *d);
};
struct Cdeque_00123dd0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00123dd0 *data_;
    Iter_00123dd0 end() const { return Iter_00123dd0(data_ + (cap_ ? (start_ + size_) % cap_ : 0), this); }
};
inline Iter_00123dd0::Iter_00123dd0(Elem_00123dd0 *p, const Cdeque_00123dd0 *d)
    : ptr(p), beg(d->data_), first(beg + d->start_), end(beg + d->cap_) {}

extern "C" Iter_00123dd0 FUN_00123dd0(const Cdeque_00123dd0 *self)
{
    return self->end();
}
