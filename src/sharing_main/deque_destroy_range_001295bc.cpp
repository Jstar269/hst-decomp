/* HSTMATCH module=hstp_trans_main.prx start=0x001295bc end=0x00129790 symbol=FUN_001295bc lang=c++ */
/* Clone of src/eboot/deque_destroy_range_0011e3e8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deque segmented range walk (destroy [first, last) for a trivially destructible 12-byte element, 42 per
   block): iterators by value, map iterator is a circular-buffer iterator {p, first, beg, last} with a
   member-wise copy constructor; per-block destroy is empty. Names provisional. */
#pragma inline_depth(8)
extern "C" const unsigned DAT_00381144;

template <class T> inline const T &Min_001295bc(const T &a, const T &b) { return b < a ? b : a; }

struct Elem_001295bc { int a, b, c; };
typedef Elem_001295bc *Block_001295bc;

struct MapIt_001295bc {
    Block_001295bc *p_;
    Block_001295bc *first_;
    Block_001295bc *beg_;
    Block_001295bc *last_;
    MapIt_001295bc(const MapIt_001295bc &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
    Block_001295bc &operator*() const { return *p_; }
    MapIt_001295bc &operator++() { if (++p_ == last_) p_ = first_; return *this; }
    friend int operator-(const MapIt_001295bc &x, const MapIt_001295bc &y)
    {
        Block_001295bc *b = x.beg_;
        int n = x.p_ - y.p_;
        if (x.p_ >= b) {
            if (y.p_ < b)
                n -= x.last_ - x.first_;
        } else if (y.p_ >= b)
            n += x.last_ - x.first_;
        return n;
    }
};

struct DequeIt_001295bc {
    MapIt_001295bc i_;
    Elem_001295bc *cur_;
    Elem_001295bc *end_;
    friend int operator-(const DequeIt_001295bc &x, const DequeIt_001295bc &y)
    {
        return (x.i_ - y.i_) * 42 - (x.end_ - x.cur_) + (y.end_ - y.cur_);
    }
    friend bool operator==(const DequeIt_001295bc &x, const DequeIt_001295bc &y) { return x.cur_ == y.cur_; }
};

extern "C" void FUN_001295bc(void *self, DequeIt_001295bc first, DequeIt_001295bc last)
{
    if (first == last)
        return;
    unsigned n = last - first;
    MapIt_001295bc i = first.i_;
    Elem_001295bc *b = first.cur_;
    Elem_001295bc *e = b + Min_001295bc(int(n), first.end_ - first.cur_);
    for (;;) {
        n -= e - b;
        if (n == 0)
            break;
        ++i;
        b = *i;
        e = b + Min_001295bc(n, DAT_00381144);
    }
}
