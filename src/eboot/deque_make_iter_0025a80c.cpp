/* HSTMATCH module=EBOOT.BIN start=0x0025a80c end=0x0025a8c0 symbol=FUN_0025a80c lang=c++ */
/* Clone of src/eboot/deque_make_iter_00191840.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per 512-byte block; block pointers in a circular cdeque map):
   iterator for position pos. The map iterator is begin() + block index through the cdeque iterator's
   operator+ (out-of-line instance 0x190e5c); the start offset must be added inside the argument,
   `begin() + (pos += start_) / 128` (a separate `pos += start_;` statement schedules differently). Names
   provisional. */
#pragma inline_depth(8)
struct Elem_0025a80c { int a; };
typedef Elem_0025a80c *Block_0025a80c;
struct MapIt_0025a80c {
    Block_0025a80c *ptr;
    Block_0025a80c *beg;
    Block_0025a80c *first;
    Block_0025a80c *end;
    MapIt_0025a80c(Block_0025a80c *p, Block_0025a80c *b, Block_0025a80c *e, Block_0025a80c *f)
        : ptr(p), beg(b), first(f), end(e) {}
    MapIt_0025a80c(const MapIt_0025a80c &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_0025a80c &operator+=(int n)
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
    MapIt_0025a80c operator+(int n) const { MapIt_0025a80c t(*this); return t += n; }
    Block_0025a80c &operator*() const { return *ptr; }
};
struct Map_0025a80c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Block_0025a80c *data_;
    unsigned size() const { return size_; }
    MapIt_0025a80c begin() { return MapIt_0025a80c(data_ + start_, data_, data_ + cap_, data_ + start_); }
};
struct Iter_0025a80c {
    MapIt_0025a80c i_;
    Elem_0025a80c *cur_;
    Elem_0025a80c *end_;
    Iter_0025a80c(const MapIt_0025a80c &i, Elem_0025a80c *b, unsigned off) : i_(i), cur_(b + off), end_(b + 128) {}
};
struct Deque_0025a80c {
    Map_0025a80c buf_;
    unsigned start_;
    unsigned size_;
};
extern "C" Iter_0025a80c FUN_0025a80c(Deque_0025a80c *self, unsigned pos)
{
    MapIt_0025a80c i = self->buf_.begin() + (pos += self->start_) / 128;
    Elem_0025a80c *b = self->buf_.size() == 0 ? 0 : *i;
    return Iter_0025a80c(i, b, pos % 128);
}
