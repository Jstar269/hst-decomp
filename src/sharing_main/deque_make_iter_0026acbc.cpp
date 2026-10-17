/* HSTMATCH module=hstp_trans_main.prx start=0x0026acbc end=0x0026ad70 symbol=FUN_0026acbc lang=c++ */
/* Clone of src/eboot/deque_make_iter_00191840.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block; block pointers in a circular cdeque map):
   iterator for position pos. The map iterator is begin() + block index through the cdeque iterator's
   operator+ (out-of-line instance 0x190e5c); the start offset must be added inside the argument,
   `begin() + (pos += start_) / 128` (a separate `pos += start_;` statement schedules differently). Names
   provisional. */
#pragma inline_depth(8)
struct Elem_0026acbc { int a; };
typedef Elem_0026acbc *Block_0026acbc;
struct MapIt_0026acbc {
    Block_0026acbc *ptr;
    Block_0026acbc *beg;
    Block_0026acbc *first;
    Block_0026acbc *end;
    MapIt_0026acbc(Block_0026acbc *p, Block_0026acbc *b, Block_0026acbc *e, Block_0026acbc *f)
        : ptr(p), beg(b), first(f), end(e) {}
    MapIt_0026acbc(const MapIt_0026acbc &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_0026acbc &operator+=(int n)
    {
        int cap = end - beg;
        n += ptr - beg;
        if (n < 0)
            n += cap;
        else if (n >= cap)
            n -= cap;
        ptr = beg + n;
        return *this;
    }
    MapIt_0026acbc operator+(int n) const { MapIt_0026acbc t(*this); return t += n; }
    Block_0026acbc &operator*() const { return *ptr; }
};
struct Map_0026acbc {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0026acbc *data_;
    unsigned size() const { return size_; }
    MapIt_0026acbc begin() { return MapIt_0026acbc(data_ + start_, data_, data_ + cap_, data_ + start_); }
};
struct Iter_0026acbc {
    MapIt_0026acbc i_;
    Elem_0026acbc *cur_;
    Elem_0026acbc *end_;
    Iter_0026acbc(const MapIt_0026acbc &i, Elem_0026acbc *b, unsigned off) : i_(i), cur_(b + off), end_(b + 128) {}
};
struct Deque_0026acbc {
    Map_0026acbc buf_;
    unsigned start_;
    unsigned size_;
};
extern "C" Iter_0026acbc FUN_0026acbc(Deque_0026acbc *self, unsigned pos)
{
    MapIt_0026acbc i = self->buf_.begin() + (pos += self->start_) / 128;
    Elem_0026acbc *b = self->buf_.size() == 0 ? 0 : *i;
    return Iter_0026acbc(i, b, pos % 128);
}
