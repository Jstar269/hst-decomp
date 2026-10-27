/* HSTMATCH module=hstp_trans_main.prx start=0x00092f80 end=0x00093204 symbol=FUN_00092f80 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same template as src/sharing_main/vec_append_n_000eda20.cpp with this instance's 32-byte element
   {int, unsigned char, int, 16-aligned Vec4}. Container append of n copies of x through a local split buffer (template instance): grow the capacity
   (1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed), reserve through an
   inline chain that builds the char flag one level below reserve() (so its slot follows the growth
   temporaries), copy-construct n elements at the end, copy the old elements in front, swap buffers,
   destroy the buffer (its destructor called explicitly). Empty tag and allocator temporaries only shape
   the frame: tags passed from this function sit right below the buffer, allocator temporaries in the
   inlined helpers next, then need, then the max() temporaries. Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
inline void *operator new(unsigned, void *p) { return p; }
struct Flag_00092f80 { char v; Flag_00092f80(char x) : v(x) {} };
struct False_00092f80 {};
template <class T> inline const T &Max_00092f80(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00092f80(T &a, T &b) { T t = a; a = b; b = t; }
struct V4 { float x, y, z, w; V4(const V4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} } __attribute__((aligned(16)));
struct Elem_00092f80 { int a; unsigned char b; int c; V4 v; };
struct Alloc_00092f80 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00092f80); }
    void construct(Elem_00092f80 *p, const Elem_00092f80 &x) { new (p) Elem_00092f80(x); }
};
struct Vec_00092f80 { Elem_00092f80 *data; unsigned size; unsigned capacity; };
class Buf_00092f80;
extern "C" {
void FUN_000933fc(Buf_00092f80 *buf, unsigned n, char f);
void FUN_0009336c(Buf_00092f80 *buf, int flag);
}
class Buf_00092f80 {
public:
    Elem_00092f80 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00092f80(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00092f80 f) { FUN_000933fc(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00092f80(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00092f80 &x, False_00092f80) {
        Elem_00092f80 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00092f80().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00092f80 *first, Elem_00092f80 *last, False_00092f80) {
        Elem_00092f80 *d = data + start;
        while (first < last) {
            --last;
            Alloc_00092f80().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00092f80() { return Alloc_00092f80().max_size(); }
static inline unsigned Grow_00092f80(Vec_00092f80 *v, unsigned need)
{
    const unsigned ms = MaxSize_00092f80();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00092f80((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00092f80((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00092f80(Vec_00092f80 *v, unsigned n, const Elem_00092f80 &x)
{
    Buf_00092f80 buf(&v->capacity);
    buf.reserve(Grow_00092f80(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00092f80());
    buf.move_in_front(v->data, v->data + v->size, False_00092f80());
    Swap_00092f80(v->capacity, buf.capacity);
    Swap_00092f80(v->data, buf.data);
    Swap_00092f80(v->size, buf.size);
    FUN_0009336c(&buf, -1);
}
