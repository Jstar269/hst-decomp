/* HSTMATCH module=EBOOT.BIN start=0x000664a8 end=0x0006666c symbol=FUN_000664a8 lang=c++ */
/* Clone of src/eboot/vec_append_n_00148af0.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_000664a8 { char v; Flag_000664a8(char x) : v(x) {} };
struct False_000664a8 {};
template <class T> inline const T &Max_000664a8(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000664a8(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_000664a8 { int w[3]; };
struct Alloc_000664a8 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000664a8); }
};
struct Vec_000664a8 { Elem_000664a8 *data; unsigned size; unsigned capacity; };
class Buf_000664a8;
extern "C" {
void FUN_0006728c(Buf_000664a8 *buf, unsigned n, char f);
void FUN_00066714(Buf_000664a8 *buf, unsigned n, const Elem_000664a8 &x, False_000664a8);
void FUN_0006666c(Buf_000664a8 *buf, Elem_000664a8 *first, Elem_000664a8 *last, False_000664a8);
void FUN_0006705c(Buf_000664a8 *buf, int flag);
}
class Buf_000664a8 {
public:
    Elem_000664a8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000664a8(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000664a8 f) { FUN_0006728c(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000664a8(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_000664a8() { return Alloc_000664a8().max_size(); }
static inline unsigned Grow_000664a8(Vec_000664a8 *v, unsigned need)
{
    const unsigned ms = MaxSize_000664a8();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000664a8((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000664a8((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000664a8(Vec_000664a8 *v, unsigned n, const Elem_000664a8 &x)
{
    Buf_000664a8 buf(&v->capacity);
    buf.reserve(Grow_000664a8(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00066714(&buf, n, x, False_000664a8());
    FUN_0006666c(&buf, v->data, v->data + v->size, False_000664a8());
    Swap_000664a8(v->capacity, buf.capacity);
    Swap_000664a8(v->data, buf.data);
    Swap_000664a8(v->size, buf.size);
    FUN_0006705c(&buf, -1);
}
