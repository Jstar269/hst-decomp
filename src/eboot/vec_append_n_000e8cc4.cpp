/* HSTMATCH module=EBOOT.BIN start=0x000e8cc4 end=0x000e8f90 symbol=FUN_000e8cc4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same split-buffer append as src/eboot/vec_append_n_000c1b1c.cpp (recipe of vec_append_n_002374f4.cpp), 752-byte
   element: int id, five floats, and a 704-byte tail whose copy constructor is a real out-of-line call (0x5b9d0),
   so the 12-byte gaps at +4 and +0x24 are never copied. max_size 0x00572620 = 0xffffffff/752. The frame needs the
   by-value empty `True` on each inlined helper plus a bare `Alloc();` opening it, as in 0xc1b1c. Names provisional. */
/* Appends n copies of x to a vector of 752-byte elements: the grow policy (thirds of the maximum, +3/5 then +1/2)
   sizes a split buffer, the copies are filled in after the old size, the old elements are moved in backwards one at
   a time (each pass re-reads start and size from the frame) and the buffers are swapped. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
extern "C" void FUN_0005b9d0(void *dst, void *src);
struct Flag { char v; Flag(char x) : v(x) {} };
struct True {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
inline void *operator new(unsigned, void *p) { return p; }
struct Elem {
    int id;
    char gap0[12];
    float v[5];
    char gap1[12];
    char tail[704];
    Elem(const Elem &o) : id(o.id)
    {
        v[0] = o.v[0]; v[1] = o.v[1]; v[2] = o.v[2]; v[3] = o.v[3]; v[4] = o.v[4];
        FUN_0005b9d0(tail, (void *)(o.tail));
    }
};
struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
};
struct Vec { Elem *data; unsigned size; unsigned capacity; };
class Buf;
extern "C" {
void FUN_000e9678(Buf *buf, unsigned n, char f);
void FUN_000e9418(Buf *buf, int flag);
void FUN_0005b9d0(void *dst, void *src);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_000e9678(this, n, f.v); }
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
extern "C" void FUN_000e8cc4(Vec *vec, unsigned n, const Elem &x)
{
    Buf buf(&vec->capacity);
    buf.reserve(Grow(vec, vec->size + n - vec->capacity));
    buf.start = vec->size;
    FillN(&buf, buf.data + buf.start + buf.size, n, x, True());
    Elem *old = vec->data;
    MoveBackward(&buf, old, old + vec->size, True());
    Swap(vec->capacity, buf.capacity);
    Swap(vec->data, buf.data);
    Swap(vec->size, buf.size);
    FUN_000e9418(&buf, -1);
}
