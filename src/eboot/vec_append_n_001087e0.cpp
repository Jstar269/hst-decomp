/* HSTMATCH module=EBOOT.BIN start=0x001087e0 end=0x00108aa4 symbol=FUN_001087e0 lang=c++ */
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
struct Flag_001087e0 { char v; Flag_001087e0(char x) : v(x) {} };
struct False_001087e0 {};
template <class T> inline const T &Max_001087e0(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001087e0(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_001087e0 { float f[9]; };
struct Alloc_001087e0 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_001087e0); }
    void construct(Elem_001087e0 *p, const Elem_001087e0 &x) { new (p) Elem_001087e0(x); }
};
struct Vec_001087e0 { Elem_001087e0 *data; unsigned size; unsigned capacity; };
class Buf_001087e0;
extern "C" {
void FUN_001097a4(Buf_001087e0 *buf, unsigned n, char f);
void FUN_00108b88(Buf_001087e0 *buf, int flag);
}
class Buf_001087e0 {
public:
    Elem_001087e0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_001087e0(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_001087e0 f) { FUN_001097a4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_001087e0(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_001087e0 &x, False_001087e0) {
        Elem_001087e0 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_001087e0().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_001087e0 *first, Elem_001087e0 *last, False_001087e0) {
        Elem_001087e0 *d = data + start;
        while (first < last) {
            --last;
            Alloc_001087e0().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_001087e0() { return Alloc_001087e0().max_size(); }
static inline unsigned Grow_001087e0(Vec_001087e0 *v, unsigned need)
{
    const unsigned ms = MaxSize_001087e0();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_001087e0((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_001087e0((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_001087e0(Vec_001087e0 *v, unsigned n, const Elem_001087e0 &x)
{
    Buf_001087e0 buf(&v->capacity);
    buf.reserve(Grow_001087e0(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_001087e0());
    buf.move_in_front(v->data, v->data + v->size, False_001087e0());
    Swap_001087e0(v->capacity, buf.capacity);
    Swap_001087e0(v->data, buf.data);
    Swap_001087e0(v->size, buf.size);
    FUN_00108b88(&buf, -1);
}
