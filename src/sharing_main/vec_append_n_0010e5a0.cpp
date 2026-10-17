/* HSTMATCH module=hstp_trans_main.prx start=0x0010e5a0 end=0x0010e864 symbol=FUN_0010e5a0 lang=c++ */
/* Clone of src/eboot/vec_append_n_001087e0.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_0010e5a0 { char v; Flag_0010e5a0(char x) : v(x) {} };
struct False_0010e5a0 {};
template <class T> inline const T &Max_0010e5a0(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0010e5a0(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_0010e5a0 { float f[9]; };
struct Alloc_0010e5a0 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_0010e5a0); }
    void construct(Elem_0010e5a0 *p, const Elem_0010e5a0 &x) { new (p) Elem_0010e5a0(x); }
};
struct Vec_0010e5a0 { Elem_0010e5a0 *data; unsigned size; unsigned capacity; };
class Buf_0010e5a0;
extern "C" {
void FUN_0010f564(Buf_0010e5a0 *buf, unsigned n, char f);
void FUN_0010e948(Buf_0010e5a0 *buf, int flag);
}
class Buf_0010e5a0 {
public:
    Elem_0010e5a0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_0010e5a0(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_0010e5a0 f) { FUN_0010f564(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_0010e5a0(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_0010e5a0 &x, False_0010e5a0) {
        Elem_0010e5a0 *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_0010e5a0().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_0010e5a0 *first, Elem_0010e5a0 *last, False_0010e5a0) {
        Elem_0010e5a0 *d = data + start;
        while (first < last) {
            --last;
            Alloc_0010e5a0().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_0010e5a0() { return Alloc_0010e5a0().max_size(); }
static inline unsigned Grow_0010e5a0(Vec_0010e5a0 *v, unsigned need)
{
    const unsigned ms = MaxSize_0010e5a0();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_0010e5a0((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_0010e5a0((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0010e5a0(Vec_0010e5a0 *v, unsigned n, const Elem_0010e5a0 &x)
{
    Buf_0010e5a0 buf(&v->capacity);
    buf.reserve(Grow_0010e5a0(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_0010e5a0());
    buf.move_in_front(v->data, v->data + v->size, False_0010e5a0());
    Swap_0010e5a0(v->capacity, buf.capacity);
    Swap_0010e5a0(v->data, buf.data);
    Swap_0010e5a0(v->size, buf.size);
    FUN_0010e948(&buf, -1);
}
