/* HSTMATCH module=EBOOT.BIN start=0x0011e3e8 end=0x0011e5bc symbol=FUN_0011e3e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deque segmented range walk (destroy [first, last) for a trivially destructible 12-byte element, 42 per
   block): iterators by value, map iterator is a circular-buffer iterator {p, first, beg, last} with a
   member-wise copy constructor; per-block destroy is empty. Names provisional. */
#pragma inline_depth(8)
extern "C" const unsigned DAT_002da164;

template <class T> inline const T &Min_0011e3e8(const T &a, const T &b) { return b < a ? b : a; }

struct Elem_0011e3e8 { int a, b, c; };
typedef Elem_0011e3e8 *Block_0011e3e8;

struct MapIt_0011e3e8 {
    Block_0011e3e8 *p_;
    Block_0011e3e8 *first_;
    Block_0011e3e8 *beg_;
    Block_0011e3e8 *last_;
    MapIt_0011e3e8(const MapIt_0011e3e8 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
    Block_0011e3e8 &operator*() const { return *p_; }
    MapIt_0011e3e8 &operator++() { if (++p_ == last_) p_ = first_; return *this; }
    friend int operator-(const MapIt_0011e3e8 &x, const MapIt_0011e3e8 &y)
    {
        Block_0011e3e8 *b = x.beg_;
        int n = x.p_ - y.p_;
        if (x.p_ >= b) {
            if (y.p_ < b)
                n -= x.last_ - x.first_;
        } else if (y.p_ >= b)
            n += x.last_ - x.first_;
        return n;
    }
};

struct DequeIt_0011e3e8 {
    MapIt_0011e3e8 i_;
    Elem_0011e3e8 *cur_;
    Elem_0011e3e8 *end_;
    friend int operator-(const DequeIt_0011e3e8 &x, const DequeIt_0011e3e8 &y)
    {
        return (x.i_ - y.i_) * 42 - (x.end_ - x.cur_) + (y.end_ - y.cur_);
    }
    friend bool operator==(const DequeIt_0011e3e8 &x, const DequeIt_0011e3e8 &y) { return x.cur_ == y.cur_; }
};

extern "C" void FUN_0011e3e8(void *self, DequeIt_0011e3e8 first, DequeIt_0011e3e8 last)
{
    if (first == last)
        return;
    unsigned n = last - first;
    MapIt_0011e3e8 i = first.i_;
    Elem_0011e3e8 *b = first.cur_;
    Elem_0011e3e8 *e = b + Min_0011e3e8(int(n), first.end_ - first.cur_);
    for (;;) {
        n -= e - b;
        if (n == 0)
            break;
        ++i;
        b = *i;
        e = b + Min_0011e3e8(n, DAT_002da164);
    }
}
