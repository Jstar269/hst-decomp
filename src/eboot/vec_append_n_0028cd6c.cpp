/* HSTMATCH module=EBOOT.BIN start=0x0028cd6c end=0x0028cfa0 symbol=FUN_0028cd6c lang=c++ */
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
struct Flag_0028cd6c { char v; Flag_0028cd6c(char x) : v(x) {} };
struct False_0028cd6c {};
template <class T> inline const T &Max_0028cd6c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0028cd6c(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_0028cd6c { float x, y; };
struct Alloc_0028cd6c {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_0028cd6c); }
    void construct(Elem_0028cd6c *p, const Elem_0028cd6c &x) { new (p) Elem_0028cd6c(x); }
};
struct Vec_0028cd6c { Elem_0028cd6c *data; unsigned size; unsigned capacity; };
class Buf_0028cd6c;
extern "C" {
void FUN_0028da84(Buf_0028cd6c *buf, unsigned n, char f);
void FUN_0028d78c(Buf_0028cd6c *buf, int flag);
}
class Buf_0028cd6c {
public:
    Elem_0028cd6c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_0028cd6c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_0028cd6c f) { FUN_0028da84(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_0028cd6c(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
    void construct_at_end(unsigned n, const Elem_0028cd6c &x, False_0028cd6c) {
        Elem_0028cd6c *p = data + start + size;
        for (; n != 0; --n) {
            Alloc_0028cd6c().construct(p, x);
            ++p;
            ++size;
        }
    }
    void move_in_front(Elem_0028cd6c *first, Elem_0028cd6c *last, False_0028cd6c) {
        Elem_0028cd6c *d = data + start;
        while (first < last) {
            --last;
            Alloc_0028cd6c().construct(--d, *last);
            --start;
            ++size;
        }
    }
};
inline unsigned MaxSize_0028cd6c() { return Alloc_0028cd6c().max_size(); }
static inline unsigned Grow_0028cd6c(Vec_0028cd6c *v, unsigned need)
{
    const unsigned ms = MaxSize_0028cd6c();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_0028cd6c((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_0028cd6c((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0028cd6c(Vec_0028cd6c *v, unsigned n, const Elem_0028cd6c &x)
{
    Buf_0028cd6c buf(&v->capacity);
    buf.reserve(Grow_0028cd6c(v, v->size + n - v->capacity));
    buf.start = v->size;
    buf.construct_at_end(n, x, False_0028cd6c());
    buf.move_in_front(v->data, v->data + v->size, False_0028cd6c());
    Swap_0028cd6c(v->capacity, buf.capacity);
    Swap_0028cd6c(v->data, buf.data);
    Swap_0028cd6c(v->size, buf.size);
    FUN_0028d78c(&buf, -1);
}
