/* HSTMATCH module=EBOOT.BIN start=0x00191000 end=0x00191194 symbol=FUN_00191000 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per block, block pointers in a cdeque): destroy(first, last) for a
   trivially destructible element type, so only the per-block walk survives. Called from clear() (0x190cc8)
   and the destructor (0x190b1c). The iterators are taken by value; their user-defined copy constructor makes
   MWCC pass them by invisible reference with no callee-side copy. Names provisional. */
extern "C" {
extern const unsigned DAT_002e138c; /* block size (128), static const member */
}
#pragma inline_depth(8)
template <class T> inline const T &Min_00191000(const T &a, const T &b) { return b < a ? b : a; }

typedef int Elem_00191000;
typedef Elem_00191000 *Block_00191000;

struct BlkIter_00191000 {
    Block_00191000 *ptr;
    Block_00191000 *beg;
    Block_00191000 *first;
    Block_00191000 *end;
};
inline int operator-(const BlkIter_00191000 &x, const BlkIter_00191000 &y)
{
    Block_00191000 *f = x.first;
    int d = x.ptr - y.ptr;
    if (x.ptr >= f) {
        if (y.ptr < f)
            d -= x.end - x.beg;
    } else {
        if (y.ptr >= f)
            d += x.end - x.beg;
    }
    return d;
}

struct Iter_00191000 {
    BlkIter_00191000 i_;
    Elem_00191000 *cur_;
    Elem_00191000 *end_;
    Iter_00191000(const Iter_00191000 &o) : i_(o.i_), cur_(o.cur_), end_(o.end_) {}
};
inline int operator-(const Iter_00191000 &x, const Iter_00191000 &y)
{
    return (y.end_ - y.cur_) + ((x.i_ - y.i_) * 128 - (x.end_ - x.cur_));
}
inline bool operator==(const Iter_00191000 &x, const Iter_00191000 &y) { return x.cur_ == y.cur_; }

struct Deque_00191000;

extern "C" void FUN_00191000(Deque_00191000 *self, Iter_00191000 first, Iter_00191000 last)
{
    if (first == last)
        return;
    unsigned n = last - first;
    Elem_00191000 *b = first.cur_;
    Block_00191000 *p = first.i_.ptr;
    Block_00191000 *beg = first.i_.beg;
    Block_00191000 *end = first.i_.end;
    Elem_00191000 *e = b + Min_00191000(int(n), int(first.end_ - first.cur_));
    while (true) {
        n -= e - b; /* the (empty) destroy of [b, e) */
        if (n == 0)
            break;
        if (++p == end)
            p = beg;
        b = *p;
        e = b + Min_00191000(n, DAT_002e138c);
    }
}
