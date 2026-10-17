/* HSTMATCH module=hstp_trans_main.prx start=0x0019d66c end=0x0019d6e0 symbol=FUN_0019d66c lang=c++ */
/* Clone of src/eboot/cdeque_iter_plus_00190e5c.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque (circular buffer) iterator operator+(n) for the block map of the 4-byte-element deque
   (0x191840 inlines the same code): copy, wrap the index into [0, cap) and return by value. Iterator is
   {ptr, buffer begin, logical first, buffer end}. Names provisional. */
#pragma inline_depth(8)
struct Elem_0019d66c { int a; };
typedef Elem_0019d66c *Block_0019d66c;
struct MapIt_0019d66c {
    Block_0019d66c *ptr;
    Block_0019d66c *beg;
    Block_0019d66c *first;
    Block_0019d66c *end;
    MapIt_0019d66c(const MapIt_0019d66c &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_0019d66c &operator+=(int n)
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
    MapIt_0019d66c operator+(int n) const { MapIt_0019d66c t(*this); return t += n; }
};
extern "C" MapIt_0019d66c FUN_0019d66c(const MapIt_0019d66c *self, int n)
{
    return *self + n;
}
