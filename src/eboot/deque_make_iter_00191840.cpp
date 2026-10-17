/* HSTMATCH module=EBOOT.BIN start=0x00191840 end=0x001918f4 symbol=FUN_00191840 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block; block pointers in a circular cdeque map):
   iterator for position pos. The map iterator is begin() + block index through the cdeque iterator's
   operator+ (out-of-line instance 0x190e5c); the start offset must be added inside the argument,
   `begin() + (pos += start_) / 128` (a separate `pos += start_;` statement schedules differently). Names
   provisional. */
#pragma inline_depth(8)
struct Elem_00191840 { int a; };
typedef Elem_00191840 *Block_00191840;
struct MapIt_00191840 {
    Block_00191840 *ptr;
    Block_00191840 *beg;
    Block_00191840 *first;
    Block_00191840 *end;
    MapIt_00191840(Block_00191840 *p, Block_00191840 *b, Block_00191840 *e, Block_00191840 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    MapIt_00191840(const MapIt_00191840 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_00191840 &operator+=(int n)
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
    MapIt_00191840 operator+(int n) const { MapIt_00191840 t(*this); return t += n; }
    Block_00191840 &operator*() const { return *ptr; }
};
struct Map_00191840 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_00191840 *data_;
    unsigned size() const { return size_; }
    MapIt_00191840 begin() { return MapIt_00191840(data_ + start_, data_, data_ + cap_, data_ + start_); }
};
struct Iter_00191840 {
    MapIt_00191840 i_;
    Elem_00191840 *cur_;
    Elem_00191840 *end_;
    Iter_00191840(const MapIt_00191840 &i, Elem_00191840 *b, unsigned off) : i_(i), cur_(b + off), end_(b + 128) {}
};
struct Deque_00191840 {
    Map_00191840 buf_;
    unsigned start_;
    unsigned size_;
};
extern "C" Iter_00191840 FUN_00191840(Deque_00191840 *self, unsigned pos)
{
    MapIt_00191840 i = self->buf_.begin() + (pos += self->start_) / 128;
    Elem_00191840 *b = self->buf_.size() == 0 ? 0 : *i;
    return Iter_00191840(i, b, pos % 128);
}
