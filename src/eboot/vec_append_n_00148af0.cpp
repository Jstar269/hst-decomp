/* HSTMATCH module=EBOOT.BIN start=0x00148af0 end=0x00148cb4 symbol=FUN_00148af0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer, instance whose element (12 bytes, copy
   constructor 0x146b88) keeps the fill and move-in helpers out of line (0x148d5c, 0x148cb4, each taking an
   empty tag by value). Grow the capacity (1.6x below max/3, 1.5x below 2*max/3, else max_size; never less
   than needed), reserve through an inline chain that builds the char flag one level below reserve(), fill
   at the end, copy the old elements in front, swap buffers, destroy the buffer (destructor called
   explicitly). The two tag temporaries sit right below the buffer, then need, then the max() temporaries,
   then the flag, its by-value copy and the max_size() allocator temporary (96-byte frame).
   Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag_00148af0 { char v; Flag_00148af0(char x) : v(x) {} };
struct False_00148af0 {};
template <class T> inline const T &Max_00148af0(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00148af0(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00148af0 { int w[3]; };
struct Alloc_00148af0 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00148af0); }
};
struct Vec_00148af0 { Elem_00148af0 *data; unsigned size; unsigned capacity; };
class Buf_00148af0;
extern "C" {
void FUN_0014b400(Buf_00148af0 *buf, unsigned n, char f);
void FUN_00148d5c(Buf_00148af0 *buf, unsigned n, const Elem_00148af0 &x, False_00148af0);
void FUN_00148cb4(Buf_00148af0 *buf, Elem_00148af0 *first, Elem_00148af0 *last, False_00148af0);
void FUN_0014aaa0(Buf_00148af0 *buf, int flag);
}
class Buf_00148af0 {
public:
    Elem_00148af0 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00148af0(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00148af0 f) { FUN_0014b400(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00148af0(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_00148af0() { return Alloc_00148af0().max_size(); }
static inline unsigned Grow_00148af0(Vec_00148af0 *v, unsigned need)
{
    const unsigned ms = MaxSize_00148af0();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00148af0((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00148af0((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00148af0(Vec_00148af0 *v, unsigned n, const Elem_00148af0 &x)
{
    Buf_00148af0 buf(&v->capacity);
    buf.reserve(Grow_00148af0(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00148d5c(&buf, n, x, False_00148af0());
    FUN_00148cb4(&buf, v->data, v->data + v->size, False_00148af0());
    Swap_00148af0(v->capacity, buf.capacity);
    Swap_00148af0(v->data, buf.data);
    Swap_00148af0(v->size, buf.size);
    FUN_0014aaa0(&buf, -1);
}
