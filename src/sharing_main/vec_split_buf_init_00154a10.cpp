/* HSTMATCH module=hstp_trans_main.prx start=0x00154a10 end=0x00154b60 symbol=FUN_00154a10 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 40-byte records (data, size, capacity): prepares the split buffer used by insert(pos, x) (see vec_insert_one_0015284c.cpp) -- asks the growth policy (cap * 8/5 below 0x2222222, cap * 3/2 below 0x4444444, else the 0x6666666 maximum; throws via 0x43b4 when the request exceeds the maximum), reserves that much (0x156910) and records the insertion index pos - data in the buffer's start field. The growth policy and Max() are the 0x153fe0 recipe at a 40-byte element size. Matching idiom: the grown capacity is computed into a local BEFORE the call `buf->reserve(cap2, Flag(0))` (inline call arguments are evaluated right to left; written as `reserve(Grow(..), Flag(0))` the flag byte is computed early and held in a saved register). Names provisional. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
struct Flag { char v; Flag(char x) : v(x) {} };
struct Elem { int w[10]; };
struct Vec { Elem *data; unsigned size; unsigned capacity; };
struct Buf {
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    void reserve(unsigned n, Flag f);
};
extern "C" void FUN_00156910(Buf *b, unsigned n, char f);
inline void Buf::reserve(unsigned n, Flag f) { FUN_00156910(this, n, f.v); }
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
static inline unsigned Grow(Vec *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x6666666 - cap < need)
        FUN_000043b4();
    if (cap < 0x2222222)
        return cap + Max((cap + 1) * 3 / 5, need);
    if (cap < 0x4444444)
        return cap + Max((cap + 1) / 2, need);
    return 0x6666666;
}
extern "C" void FUN_00154a10(Vec *v, Buf *buf, Elem *pos, unsigned n)
{
    unsigned need = v->size + n - v->capacity;
    unsigned cap2 = Grow(v, need);
    buf->reserve(cap2, Flag(0));
    buf->start = pos - v->data;
}
