/* HSTMATCH module=hstp_trans_main.prx start=0x0019e050 end=0x0019e104 symbol=FUN_0019e050 lang=c++ */
/* Clone of src/eboot/deque_make_iter_00191840.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block; block pointers in a circular cdeque map):
   iterator for position pos. The map iterator is begin() + block index through the cdeque iterator's
   operator+ (out-of-line instance 0x190e5c); the start offset must be added inside the argument,
   `begin() + (pos += start_) / 128` (a separate `pos += start_;` statement schedules differently). Names
   provisional. */
#pragma inline_depth(8)
struct Elem_0019e050 { int a; };
typedef Elem_0019e050 *Block_0019e050;
struct MapIt_0019e050 {
    Block_0019e050 *ptr;
    Block_0019e050 *beg;
    Block_0019e050 *first;
    Block_0019e050 *end;
    MapIt_0019e050(Block_0019e050 *p, Block_0019e050 *b, Block_0019e050 *e, Block_0019e050 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    MapIt_0019e050(const MapIt_0019e050 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_0019e050 &operator+=(int n)
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
    MapIt_0019e050 operator+(int n) const { MapIt_0019e050 t(*this); return t += n; }
    Block_0019e050 &operator*() const { return *ptr; }
};
struct Map_0019e050 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0019e050 *data_;
    unsigned size() const { return size_; }
    MapIt_0019e050 begin() { return MapIt_0019e050(data_ + start_, data_, data_ + cap_, data_ + start_); }
};
struct Iter_0019e050 {
    MapIt_0019e050 i_;
    Elem_0019e050 *cur_;
    Elem_0019e050 *end_;
    Iter_0019e050(const MapIt_0019e050 &i, Elem_0019e050 *b, unsigned off) : i_(i), cur_(b + off), end_(b + 128) {}
};
struct Deque_0019e050 {
    Map_0019e050 buf_;
    unsigned start_;
    unsigned size_;
};
extern "C" Iter_0019e050 FUN_0019e050(Deque_0019e050 *self, unsigned pos)
{
    MapIt_0019e050 i = self->buf_.begin() + (pos += self->start_) / 128;
    Elem_0019e050 *b = self->buf_.size() == 0 ? 0 : *i;
    return Iter_0019e050(i, b, pos % 128);
}
