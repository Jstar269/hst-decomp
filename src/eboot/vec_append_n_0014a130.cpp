/* HSTMATCH module=EBOOT.BIN start=0x0014a130 end=0x0014a3c4 symbol=FUN_0014a130 lang=c++ */
/* Clone of src/eboot/vec_append_n_000e894c.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_0014a130 { char v; Flag_0014a130(char x) : v(x) {} };
struct False_0014a130 {};
template <class T> inline const T &Max_0014a130(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0014a130(T &a, T &b) { T t = a; a = b; b = t; }
struct V4 { float x, y, z, w; V4(const V4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };
struct Elem_0014a130 { V4 a, b; };
struct Alloc_0014a130 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_0014a130); }
    void construct(Elem_0014a130 *p, const Elem_0014a130 &x) { new (p) Elem_0014a130(x); }
};
struct Vec_0014a130 { Elem_0014a130 *data; unsigned size; unsigned capacity; };
class Buf_0014a130;
extern "C" {
void FUN_0014b16c(Buf_0014a130 *buf, unsigned n, char f);
void FUN_0014a8f0(Buf_0014a130 *buf, int flag);
}
class Buf_0014a130 {
public:
    Elem_0014a130 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_0014a130(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_0014a130 f) { FUN_0014b16c(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_0014a130(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_0014a130 &x, False_0014a130) {
        Elem_0014a130 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_0014a130().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_0014a130 *first, Elem_0014a130 *last, False_0014a130) {
        Elem_0014a130 *d = data + start;
        while (first < last) {
            --last;
            Alloc_0014a130().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_0014a130() { return Alloc_0014a130().max_size(); }
static inline unsigned Grow_0014a130(Vec_0014a130 *v, unsigned need)
{
    const unsigned ms = MaxSize_0014a130();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_0014a130((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_0014a130((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0014a130(Vec_0014a130 *v, unsigned n, const Elem_0014a130 &x)
{
    Buf_0014a130 buf(&v->capacity);
    buf.reserve(Grow_0014a130(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_0014a130());
    buf.move_in_front(v->data, v->data + v->size, False_0014a130());
    Swap_0014a130(v->capacity, buf.capacity);
    Swap_0014a130(v->data, buf.data);
    Swap_0014a130(v->size, buf.size);
    FUN_0014a8f0(&buf, -1);
}
