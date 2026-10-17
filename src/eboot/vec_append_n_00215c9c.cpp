/* HSTMATCH module=EBOOT.BIN start=0x00215c9c end=0x00215ed0 symbol=FUN_00215c9c lang=c++ */
/* Clone of src/eboot/vec_append_n_001084b8.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_00215c9c { char v; Flag_00215c9c(char x) : v(x) {} };
struct False_00215c9c {};
template <class T> inline const T &Max_00215c9c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00215c9c(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00215c9c { float x, y; };
struct Alloc_00215c9c {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00215c9c); }
    void construct(Elem_00215c9c *p, const Elem_00215c9c &x) { new (p) Elem_00215c9c(x); }
};
struct Vec_00215c9c { Elem_00215c9c *data; unsigned size; unsigned capacity; };
class Buf_00215c9c;
extern "C" {
void FUN_002160c8(Buf_00215c9c *buf, unsigned n, char f);
void FUN_00216038(Buf_00215c9c *buf, int flag);
}
class Buf_00215c9c {
public:
    Elem_00215c9c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00215c9c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00215c9c f) { FUN_002160c8(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00215c9c(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_00215c9c &x, False_00215c9c) {
        Elem_00215c9c *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_00215c9c().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_00215c9c *first, Elem_00215c9c *last, False_00215c9c) {
        Elem_00215c9c *d = data + start;
        while (first < last) {
            --last;
            Alloc_00215c9c().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_00215c9c() { return Alloc_00215c9c().max_size(); }
static inline unsigned Grow_00215c9c(Vec_00215c9c *v, unsigned need)
{
    const unsigned ms = MaxSize_00215c9c();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00215c9c((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00215c9c((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00215c9c(Vec_00215c9c *v, unsigned n, const Elem_00215c9c &x)
{
    Buf_00215c9c buf(&v->capacity);
    buf.reserve(Grow_00215c9c(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_00215c9c());
    buf.move_in_front(v->data, v->data + v->size, False_00215c9c());
    Swap_00215c9c(v->capacity, buf.capacity);
    Swap_00215c9c(v->data, buf.data);
    Swap_00215c9c(v->size, buf.size);
    FUN_00216038(&buf, -1);
}
