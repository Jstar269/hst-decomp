/* HSTMATCH module=EBOOT.BIN start=0x00294088 end=0x0029430c symbol=FUN_00294088 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 10-byte elements (five shorts): append n copies of x, written from the 20-byte sibling
   src/eboot/vec_append_n_00166244.cpp with the element type and callees substituted. max_size 0x19999999
   = 0xffffffff/10, thirds at 0x08888888/0x11111110, +3/5 then +1/2. The element is plain POD: the
   implicit copy MWCC inlines for `new (p) Elem(x)` is the five-iteration lh/sh loop WITH its own null
   guard, so the construct loops must not add an `if (p)` of their own (a user copy ctor unrolls instead). */
extern "C" void FUN_000043b4(void);
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }
struct Flag { char v; Flag(char x) : v(x) {} };
struct False {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem { short v[5]; };
struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
    void construct(Elem *p, const Elem &x) { new (p) Elem(x); }
};
struct Vec { Elem *data; unsigned size; unsigned capacity; };
class Buf;
extern "C" {
void FUN_002944ac(Buf *buf, unsigned n, char f);
void FUN_002943f0(Buf *buf, int flag);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_002944ac(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem &x, False) {
        Elem *p = data + start + size;
        for (; n != 0; --n) {
            Alloc().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem *first, Elem *last, False) {
        Elem *d = data + start;
        while (first < last) {
            --last;
            Alloc().construct(--d, *last);
            --start;
            ++size;
        }
    }
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
extern "C" void FUN_00294088(Vec *v, unsigned n, const Elem &x)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False());
    buf.move_in_front(v->data, v->data + v->size, False());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_002943f0(&buf, -1);
}
