/* HSTMATCH module=hstp_trans_main.prx start=0x001543d8 end=0x0015459c symbol=FUN_001543d8 lang=c++ */
/* Clone of src/eboot/vec_append_n_000664a8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_001543d8 { char v; Flag_001543d8(char x) : v(x) {} };
struct False_001543d8 {};
template <class T> inline const T &Max_001543d8(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001543d8(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_001543d8 { int w[3]; };
struct Alloc_001543d8 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_001543d8); }
};
struct Vec_001543d8 { Elem_001543d8 *data; unsigned size; unsigned capacity; };
class Buf_001543d8;
extern "C" {
void FUN_00156ce8(Buf_001543d8 *buf, unsigned n, char f);
void FUN_00154644(Buf_001543d8 *buf, unsigned n, const Elem_001543d8 &x, False_001543d8);
void FUN_0015459c(Buf_001543d8 *buf, Elem_001543d8 *first, Elem_001543d8 *last, False_001543d8);
void FUN_00156388(Buf_001543d8 *buf, int flag);
}
class Buf_001543d8 {
public:
    Elem_001543d8 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_001543d8(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_001543d8 f) { FUN_00156ce8(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_001543d8(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_001543d8() { return Alloc_001543d8().max_size(); }
static inline unsigned Grow_001543d8(Vec_001543d8 *v, unsigned need)
{
    const unsigned ms = MaxSize_001543d8();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_001543d8((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_001543d8((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_001543d8(Vec_001543d8 *v, unsigned n, const Elem_001543d8 &x)
{
    Buf_001543d8 buf(&v->capacity);
    buf.reserve(Grow_001543d8(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00154644(&buf, n, x, False_001543d8());
    FUN_0015459c(&buf, v->data, v->data + v->size, False_001543d8());
    Swap_001543d8(v->capacity, buf.capacity);
    Swap_001543d8(v->data, buf.data);
    Swap_001543d8(v->size, buf.size);
    FUN_00156388(&buf, -1);
}
