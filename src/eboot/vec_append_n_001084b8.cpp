/* HSTMATCH module=EBOOT.BIN start=0x001084b8 end=0x001086ec symbol=FUN_001084b8 lang=c++ */
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
struct Flag_001084b8 { char v; Flag_001084b8(char x) : v(x) {} };
struct False_001084b8 {};
template <class T> inline const T &Max_001084b8(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001084b8(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_001084b8 { float x, y; };
struct Alloc_001084b8 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_001084b8); }
    void construct(Elem_001084b8 *p, const Elem_001084b8 &x) { new (p) Elem_001084b8(x); }
};
struct Vec_001084b8 { Elem_001084b8 *data; unsigned size; unsigned capacity; };
class Buf_001084b8;
extern "C" {
void FUN_0010984c(Buf_001084b8 *buf, unsigned n, char f);
void FUN_00108bf4(Buf_001084b8 *buf, int flag);
}
class Buf_001084b8 {
public:
    Elem_001084b8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_001084b8(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_001084b8 f) { FUN_0010984c(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_001084b8(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_001084b8 &x, False_001084b8) {
        Elem_001084b8 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_001084b8().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_001084b8 *first, Elem_001084b8 *last, False_001084b8) {
        Elem_001084b8 *d = data + start;
        while (first < last) {
            --last;
            Alloc_001084b8().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_001084b8() { return Alloc_001084b8().max_size(); }
static inline unsigned Grow_001084b8(Vec_001084b8 *v, unsigned need)
{
    const unsigned ms = MaxSize_001084b8();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_001084b8((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_001084b8((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_001084b8(Vec_001084b8 *v, unsigned n, const Elem_001084b8 &x)
{
    Buf_001084b8 buf(&v->capacity);
    buf.reserve(Grow_001084b8(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_001084b8());
    buf.move_in_front(v->data, v->data + v->size, False_001084b8());
    Swap_001084b8(v->capacity, buf.capacity);
    Swap_001084b8(v->data, buf.data);
    Swap_001084b8(v->size, buf.size);
    FUN_00108bf4(&buf, -1);
}
