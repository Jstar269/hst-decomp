/* HSTMATCH module=hstp_trans_main.prx start=0x00129790 end=0x00129964 symbol=FUN_00129790 lang=c++ */
/* Clone of src/eboot/deque_destroy_range_0011e3e8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deque segmented range walk (destroy [first, last) for a trivially destructible 12-byte element, 42 per
   block): iterators by value, map iterator is a circular-buffer iterator {p, first, beg, last} with a
   member-wise copy constructor; per-block destroy is empty. Names provisional. */
#pragma inline_depth(8)
extern "C" const unsigned DAT_00381140;

template <class T> inline const T &Min_00129790(const T &a, const T &b) { return b < a ? b : a; }

struct Elem_00129790 { int a, b, c; };
typedef Elem_00129790 *Block_00129790;

struct MapIt_00129790 {
    Block_00129790 *p_;
    Block_00129790 *first_;
    Block_00129790 *beg_;
    Block_00129790 *last_;
    MapIt_00129790(const MapIt_00129790 &o) : p_(o.p_), first_(o.first_), beg_(o.beg_), last_(o.last_) {}
    Block_00129790 &operator*() const { return *p_; }
    MapIt_00129790 &operator++() { if (++p_ == last_) p_ = first_; return *this; }
    friend int operator-(const MapIt_00129790 &x, const MapIt_00129790 &y)
    {
        Block_00129790 *b = x.beg_;
        int n = x.p_ - y.p_;
        if (x.p_ >= b) {
            if (y.p_ < b)
                n -= x.last_ - x.first_;
        } else if (y.p_ >= b)
            n += x.last_ - x.first_;
        return n;
    }
};

struct DequeIt_00129790 {
    MapIt_00129790 i_;
    Elem_00129790 *cur_;
    Elem_00129790 *end_;
    friend int operator-(const DequeIt_00129790 &x, const DequeIt_00129790 &y)
    {
        return (x.i_ - y.i_) * 42 - (x.end_ - x.cur_) + (y.end_ - y.cur_);
    }
    friend bool operator==(const DequeIt_00129790 &x, const DequeIt_00129790 &y) { return x.cur_ == y.cur_; }
};

extern "C" void FUN_00129790(void *self, DequeIt_00129790 first, DequeIt_00129790 last)
{
    if (first == last)
        return;
    unsigned n = last - first;
    MapIt_00129790 i = first.i_;
    Elem_00129790 *b = first.cur_;
    Elem_00129790 *e = b + Min_00129790(int(n), first.end_ - first.cur_);
    for (;;) {
        n -= e - b;
        if (n == 0)
            break;
        ++i;
        b = *i;
        e = b + Min_00129790(n, DAT_00381140);
    }
}
