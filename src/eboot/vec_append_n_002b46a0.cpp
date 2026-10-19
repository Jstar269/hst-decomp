/* HSTMATCH module=EBOOT.BIN start=0x002b46a0 end=0x002b4ac8 symbol=FUN_002b46a0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same split-buffer append as src/eboot/vec_append_n_000c1b1c.cpp (recipe of vec_append_n_002374f4.cpp), 100-byte
   element (int, two 32-byte character blocks, eight signed/unsigned bytes, two ints, a 16-byte block); max_size
   0x028f5c28 = 0xffffffff/100. An explicit copy ctor with the blocks as sub-structs is what keeps the copy
   field-by-field (implicit gives one 25-iteration word loop, 97 words shorter); the lb/lbu mix comes from the
   signed and unsigned byte members. Frame as in 0xc1b1c. Names provisional. */
/* Vector of 80-byte elements: append n copies of x through the split-buffer idiom of
   src/eboot/vec_append_n_002374f4.cpp, with both helpers inlined. Retail's frame only comes out when each inlined
   helper takes a by-value empty `True` (which reserves a never-written 8-byte slot) AND opens with a bare
   `Alloc();` statement (the extra 4-byte slot that moves the Max() temporaries from 0x3c/0x38/0x34 down to
   retail's 0x38/0x34/0x30; without it the code is word-for-word right and only the slot offsets differ). The grow
   policy is the family's: max_size 0x03333333 = 0xffffffff/80, thirds at 0x01111111/0x02222222, +3/5 then +1/2.
   The old elements are moved backwards one element at a time, decrementing `start` and incrementing `size` as it
   goes, so each pass re-reads both counters from the frame. Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag { char v; Flag(char x) : v(x) {} };
struct True {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
inline void *operator new(unsigned, void *p) { return p; }
struct Name { char v[32]; };
struct Tail16 { char v[16]; };
struct Elem {
    int id;
    Name a;
    Name b;
    signed char c0, c1, c2;
    unsigned char d0, d1;
    signed char c3, c4, c5;
    int e0, e1;
    Tail16 f;
    Elem(const Elem &o)
        : id(o.id), a(o.a), b(o.b), c0(o.c0), c1(o.c1), c2(o.c2), d0(o.d0), d1(o.d1),
          c3(o.c3), c4(o.c4), c5(o.c5), e0(o.e0), e1(o.e1), f(o.f) {}
};
struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
};
struct Vec { Elem *data; unsigned size; unsigned capacity; };
class Buf;
extern "C" {
void FUN_002b4cd4(Buf *buf, unsigned n, char f);
void FUN_002b4c44(Buf *buf, int flag);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_002b4cd4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize() { return Alloc().max_size(); }
static inline unsigned Grow(Vec *v, unsigned need)
{
    const unsigned ms = MaxSize();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max((cap + 1) / 2, need);
    return ms;
}
inline void FillN(Buf *buf, Elem *p, unsigned n, const Elem &x, True)
{
    Alloc();
    for (; n != 0; --n, ++p, ++buf->size)
        new (p) Elem(x);
}
inline void MoveBackward(Buf *buf, Elem *first, Elem *last, True)
{
    Alloc();
    Elem *dst = buf->data + buf->start;
    while (first < last) {
        --last;
        --dst;
        new (dst) Elem(*last);
        --buf->start;
        ++buf->size;
    }
}
extern "C" void FUN_002b46a0(Vec *v, unsigned n, const Elem &x)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    FillN(&buf, buf.data + buf.start + buf.size, n, x, True());
    Elem *old = v->data;
    MoveBackward(&buf, old, old + v->size, True());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_002b4c44(&buf, -1);
}
