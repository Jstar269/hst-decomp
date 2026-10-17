/* HSTMATCH module=hstp_trans_main.prx start=0x000eda20 end=0x000edcb4 symbol=FUN_000eda20 lang=c++ */
/* Clone of src/eboot/vec_append_n_000e894c.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_000eda20 { char v; Flag_000eda20(char x) : v(x) {} };
struct False_000eda20 {};
template <class T> inline const T &Max_000eda20(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000eda20(T &a, T &b) { T t = a; a = b; b = t; }
struct V4 { float x, y, z, w; V4(const V4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {} };
struct Elem_000eda20 { V4 a, b; };
struct Alloc_000eda20 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000eda20); }
    void construct(Elem_000eda20 *p, const Elem_000eda20 &x) { new (p) Elem_000eda20(x); }
};
struct Vec_000eda20 { Elem_000eda20 *data; unsigned size; unsigned capacity; };
class Buf_000eda20;
extern "C" {
void FUN_000ee7fc(Buf_000eda20 *buf, unsigned n, char f);
void FUN_000ee5d8(Buf_000eda20 *buf, int flag);
}
class Buf_000eda20 {
public:
    Elem_000eda20 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000eda20(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000eda20 f) { FUN_000ee7fc(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000eda20(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_000eda20 &x, False_000eda20) {
        Elem_000eda20 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_000eda20().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_000eda20 *first, Elem_000eda20 *last, False_000eda20) {
        Elem_000eda20 *d = data + start;
        while (first < last) {
            --last;
            Alloc_000eda20().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_000eda20() { return Alloc_000eda20().max_size(); }
static inline unsigned Grow_000eda20(Vec_000eda20 *v, unsigned need)
{
    const unsigned ms = MaxSize_000eda20();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000eda20((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000eda20((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000eda20(Vec_000eda20 *v, unsigned n, const Elem_000eda20 &x)
{
    Buf_000eda20 buf(&v->capacity);
    buf.reserve(Grow_000eda20(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_000eda20());
    buf.move_in_front(v->data, v->data + v->size, False_000eda20());
    Swap_000eda20(v->capacity, buf.capacity);
    Swap_000eda20(v->data, buf.data);
    Swap_000eda20(v->size, buf.size);
    FUN_000ee5d8(&buf, -1);
}
