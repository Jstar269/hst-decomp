/* HSTMATCH module=EBOOT.BIN start=0x00190e5c end=0x00190ed0 symbol=FUN_00190e5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque (circular buffer) iterator operator+(n) for the block map of the 4-byte-element deque
   (0x191840 inlines the same code): copy, wrap the index into [0, cap) and return by value. Iterator is
   {ptr, buffer begin, logical first, buffer end}. Names provisional. */
#pragma inline_depth(8)
struct Elem_00190e5c { int a; };
typedef Elem_00190e5c *Block_00190e5c;
struct MapIt_00190e5c {
    Block_00190e5c *ptr;
    Block_00190e5c *beg;
    Block_00190e5c *first;
    Block_00190e5c *end;
    MapIt_00190e5c(const MapIt_00190e5c &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_00190e5c &operator+=(int n)
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
    MapIt_00190e5c operator+(int n) const { MapIt_00190e5c t(*this); return t += n; }
};
extern "C" MapIt_00190e5c FUN_00190e5c(const MapIt_00190e5c *self, int n)
{
    return *self + n;
}
