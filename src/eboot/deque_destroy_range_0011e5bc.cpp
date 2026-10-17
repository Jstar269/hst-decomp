/* HSTMATCH module=EBOOT.BIN start=0x0011e5bc end=0x0011e790 symbol=FUN_0011e5bc lang=c++ */
/* Clone of src/eboot/deque_destroy_range_0011e3e8.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deque segmented range walk (destroy [first, last) for a trivially destructible 12-byte element, 42 per
   block): iterators by value, map iterator is a circular-buffer iterator {p, first, beg, last} with a
   member-wise copy constructor; per-block destroy is empty. Names provisional. */
#pragma inline_depth(8)
extern "C" const unsigned DAT_002da160;

template <class T> inline const T &Min_0011e5bc(const T &a, const T &b) { return b < a ? b : a; }

struct Elem_0011e5bc { int a, b, c; };
typedef Elem_0011e5bc *Block_0011e5bc;

struct MapIt_0011e5bc {
    Block_0011e5bc *p_;
    Block_0011e5bc *first_;
    Block_0011e5bc *beg_;
    Block_0011e5bc *last_;
    MapIt_0011e5bc(const MapIt_0011e5bc &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
    Block_0011e5bc &operator*() const { return *p_; }
    MapIt_0011e5bc &operator++() { if (++p_ == last_) p_ = first_; return *this; }
    friend int operator-(const MapIt_0011e5bc &x, const MapIt_0011e5bc &y)
    {
        Block_0011e5bc *b = x.beg_;
        int n = x.p_ - y.p_;
        if (x.p_ >= b) {
            if (y.p_ < b)
                n -= x.last_ - x.first_;
        } else if (y.p_ >= b)
            n += x.last_ - x.first_;
        return n;
    }
};

struct DequeIt_0011e5bc {
    MapIt_0011e5bc i_;
    Elem_0011e5bc *cur_;
    Elem_0011e5bc *end_;
    friend int operator-(const DequeIt_0011e5bc &x, const DequeIt_0011e5bc &y)
    {
        return (x.i_ - y.i_) * 42 - (x.end_ - x.cur_) + (y.end_ - y.cur_);
    }
    friend bool operator==(const DequeIt_0011e5bc &x, const DequeIt_0011e5bc &y) { return x.cur_ == y.cur_; }
};

extern "C" void FUN_0011e5bc(void *self, DequeIt_0011e5bc first, DequeIt_0011e5bc last)
{
    if (first == last)
        return;
    unsigned n = last - first;
    MapIt_0011e5bc i = first.i_;
    Elem_0011e5bc *b = first.cur_;
    Elem_0011e5bc *e = b + Min_0011e5bc(int(n), first.end_ - first.cur_);
    for (;;) {
        n -= e - b;
        if (n == 0)
            break;
        ++i;
        b = *i;
        e = b + Min_0011e5bc(n, DAT_002da160);
    }
}
