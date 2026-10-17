/* HSTMATCH module=EBOOT.BIN start=0x0025a678 end=0x0025a80c symbol=FUN_0025a678 lang=c++ */
/* Clone of src/eboot/deque_destroy_range_00191000.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* MSL-style deque of 4-byte elements (128 per block, block pointers in a cdeque): destroy(first, last) for a
   trivially destructible element type, so only the per-block walk survives. Called from clear() (0x190cc8)
   and the destructor (0x190b1c). The iterators are taken by value; their user-defined copy constructor makes
   MWCC pass them by invisible reference with no callee-side copy. Names provisional. */
extern "C" {
extern const unsigned DAT_002fd81c; /* block size (128), static const member */
}
#pragma inline_depth(8)
template <class T> inline const T &Min_0025a678(const T &a, const T &b) { return b < a ? b : a; }

typedef int Elem_0025a678;
typedef Elem_0025a678 *Block_0025a678;

struct BlkIter_0025a678 {
    Block_0025a678 *ptr;
    Block_0025a678 *beg;
    Block_0025a678 *first;
    Block_0025a678 *end;
};
inline int operator-(const BlkIter_0025a678 &x, const BlkIter_0025a678 &y)
{
    Block_0025a678 *f = x.first;
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

struct Iter_0025a678 {
    BlkIter_0025a678 i_;
    Elem_0025a678 *cur_;
    Elem_0025a678 *end_;
    Iter_0025a678(const Iter_0025a678 &o) : i_(o.i_), cur_(o.cur_), end_(o.end_) {}
};
inline int operator-(const Iter_0025a678 &x, const Iter_0025a678 &y)
{
    return (y.end_ - y.cur_) + ((x.i_ - y.i_) * 128 - (x.end_ - x.cur_));
}
inline bool operator==(const Iter_0025a678 &x, const Iter_0025a678 &y) { return x.cur_ == y.cur_; }

struct Deque_0025a678;

extern "C" void FUN_0025a678(Deque_0025a678 *self, Iter_0025a678 first, Iter_0025a678 last)
{
    if (first == last)
        return;
    unsigned n = last - first;
    Elem_0025a678 *b = first.cur_;
    Block_0025a678 *p = first.i_.ptr;
    Block_0025a678 *beg = first.i_.beg;
    Block_0025a678 *end = first.i_.end;
    Elem_0025a678 *e = b + Min_0025a678(int(n), int(first.end_ - first.cur_));
    while (true) {
        n -= e - b; /* the (empty) destroy of [b, e) */
        if (n == 0)
            break;
        if (++p == end)
            p = beg;
        b = *p;
        e = b + Min_0025a678(n, DAT_002fd81c);
    }
}
