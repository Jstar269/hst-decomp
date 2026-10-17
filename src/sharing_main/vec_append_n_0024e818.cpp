/* HSTMATCH module=hstp_trans_main.prx start=0x0024e818 end=0x0024e9dc symbol=FUN_0024e818 lang=c++ */
/* Clone of src/eboot/vec_append_n_000664a8.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_0024e818 { char v; Flag_0024e818(char x) : v(x) {} };
struct False_0024e818 {};
template <class T> inline const T &Max_0024e818(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0024e818(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_0024e818 { int w[3]; };
struct Alloc_0024e818 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_0024e818); }
};
struct Vec_0024e818 { Elem_0024e818 *data; unsigned size; unsigned capacity; };
class Buf_0024e818;
extern "C" {
void FUN_0024eda8(Buf_0024e818 *buf, unsigned n, char f);
void FUN_0024eac8(Buf_0024e818 *buf, unsigned n, const Elem_0024e818 &x, False_0024e818);
void FUN_0024e9dc(Buf_0024e818 *buf, Elem_0024e818 *first, Elem_0024e818 *last, False_0024e818);
void FUN_0024ec9c(Buf_0024e818 *buf, int flag);
}
class Buf_0024e818 {
public:
    Elem_0024e818 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_0024e818(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_0024e818 f) { FUN_0024eda8(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_0024e818(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_0024e818() { return Alloc_0024e818().max_size(); }
static inline unsigned Grow_0024e818(Vec_0024e818 *v, unsigned need)
{
    const unsigned ms = MaxSize_0024e818();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_0024e818((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_0024e818((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0024e818(Vec_0024e818 *v, unsigned n, const Elem_0024e818 &x)
{
    Buf_0024e818 buf(&v->capacity);
    buf.reserve(Grow_0024e818(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_0024eac8(&buf, n, x, False_0024e818());
    FUN_0024e9dc(&buf, v->data, v->data + v->size, False_0024e818());
    Swap_0024e818(v->capacity, buf.capacity);
    Swap_0024e818(v->data, buf.data);
    Swap_0024e818(v->size, buf.size);
    FUN_0024ec9c(&buf, -1);
}
