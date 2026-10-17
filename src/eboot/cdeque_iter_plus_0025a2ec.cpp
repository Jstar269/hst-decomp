/* HSTMATCH module=EBOOT.BIN start=0x0025a2ec end=0x0025a360 symbol=FUN_0025a2ec lang=c++ */
/* Clone of src/eboot/cdeque_iter_plus_00190e5c.cpp (hstclone.py tag c38): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Out-of-line cdeque (circular buffer) iterator operator+(n) for the block map of the 4-byte-element deque
   (0x191840 inlines the same code): copy, wrap the index into [0, cap) and return by value. Iterator is
   {ptr, buffer begin, logical first, buffer end}. Names provisional. */
#pragma inline_depth(8)
struct Elem_0025a2ec { int a; };
typedef Elem_0025a2ec *Block_0025a2ec;
struct MapIt_0025a2ec {
    Block_0025a2ec *ptr;
    Block_0025a2ec *beg;
    Block_0025a2ec *first;
    Block_0025a2ec *end;
    MapIt_0025a2ec(const MapIt_0025a2ec &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    MapIt_0025a2ec &operator+=(int n)
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
    MapIt_0025a2ec operator+(int n) const { MapIt_0025a2ec t(*this); return t += n; }
};
extern "C" MapIt_0025a2ec FUN_0025a2ec(const MapIt_0025a2ec *self, int n)
{
    return *self + n;
}
