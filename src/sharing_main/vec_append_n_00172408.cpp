/* HSTMATCH module=hstp_trans_main.prx start=0x00172408 end=0x0017268c symbol=FUN_00172408 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector of 20-byte elements (five floats): append n copies of x through the split-buffer idiom of
   src/sharing_main/vec_append_n_000eda20.cpp, line for line with the element type changed. The grow policy is the
   family's: max_size 0x0ccccccc = 0xffffffff/20, thirds at 0x04444444/0x08888888, +3/5 then +1/2. Retail copies
   the element as interleaved single-register lwc1/swc1 pairs, which needs the user-declared memberwise copy
   constructor (the implicit POD copy batches four loads before the stores). Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
inline void *operator new(unsigned, void *p) { return p; }
struct Flag { char v; Flag(char x) : v(x) {} };
struct False {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem { float a, b, c, d, e; Elem(const Elem &o) : a(o.a), b(o.b), c(o.c), d(o.d), e(o.e) {} };
struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
    void construct(Elem *p, const Elem &x) { new (p) Elem(x); }
};
struct Vec { Elem *data; unsigned size; unsigned capacity; };
class Buf;
extern "C" {
void FUN_00172990(Buf *buf, unsigned n, char f);
void FUN_00172800(Buf *buf, int flag);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_00172990(this, n, f.v); }
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
extern "C" void FUN_00172408(Vec *v, unsigned n, const Elem &x)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False());
    buf.move_in_front(v->data, v->data + v->size, False());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_00172800(&buf, -1);
}
