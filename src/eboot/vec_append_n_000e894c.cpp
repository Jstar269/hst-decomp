/* HSTMATCH module=EBOOT.BIN start=0x000e894c end=0x000e8be0 symbol=FUN_000e894c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer (template instance): grow the capacity
   (1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed), reserve through an
   inline chain that builds the char flag one level below reserve() (so its slot follows the growth
   temporaries), copy-construct n elements at the end, copy the old elements in front, swap buffers,
   destroy the buffer (its destructor called explicitly). Empty tag and allocator temporaries only shape
   the frame: tags passed from this function sit right below the buffer, allocator temporaries in the
   inlined helpers next, then need, then the max() temporaries. Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
inline void *operator new(unsigned, void *p) { return p; }
struct Flag_000e894c { char v; Flag_000e894c(char x) : v(x) {} };
struct False_000e894c {};
template <class T> inline const T &Max_000e894c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000e894c(T &a, T &b) { T t = a; a = b; b = t; }
struct V4 { float x, y, z, w; V4(const V4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };
struct Elem_000e894c { V4 a, b; };
struct Alloc_000e894c {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000e894c); }
    void construct(Elem_000e894c *p, const Elem_000e894c &x) { new (p) Elem_000e894c(x); }
};
struct Vec_000e894c { Elem_000e894c *data; unsigned size; unsigned capacity; };
class Buf_000e894c;
extern "C" {
void FUN_000e9728(Buf_000e894c *buf, unsigned n, char f);
void FUN_000e9504(Buf_000e894c *buf, int flag);
}
class Buf_000e894c {
public:
    Elem_000e894c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000e894c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000e894c f) { FUN_000e9728(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000e894c(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_000e894c &x, False_000e894c) {
        Elem_000e894c *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_000e894c().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_000e894c *first, Elem_000e894c *last, False_000e894c) {
        Elem_000e894c *d = data + start;
        while (first < last) {
            --last;
            Alloc_000e894c().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_000e894c() { return Alloc_000e894c().max_size(); }
static inline unsigned Grow_000e894c(Vec_000e894c *v, unsigned need)
{
    const unsigned ms = MaxSize_000e894c();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000e894c((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000e894c((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000e894c(Vec_000e894c *v, unsigned n, const Elem_000e894c &x)
{
    Buf_000e894c buf(&v->capacity);
    buf.reserve(Grow_000e894c(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_000e894c());
    buf.move_in_front(v->data, v->data + v->size, False_000e894c());
    Swap_000e894c(v->capacity, buf.capacity);
    Swap_000e894c(v->data, buf.data);
    Swap_000e894c(v->size, buf.size);
    FUN_000e9504(&buf, -1);
}
