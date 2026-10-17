/* HSTMATCH module=hstp_trans_main.prx start=0x001b5410 end=0x001b55d4 symbol=FUN_001b5410 lang=c++ */
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
struct Flag_001b5410 { char v; Flag_001b5410(char x) : v(x) {} };
struct False_001b5410 {};
template <class T> inline const T &Max_001b5410(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001b5410(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_001b5410 { int w[3]; };
struct Alloc_001b5410 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_001b5410); }
};
struct Vec_001b5410 { Elem_001b5410 *data; unsigned size; unsigned capacity; };
class Buf_001b5410;
extern "C" {
void FUN_001b63a4(Buf_001b5410 *buf, unsigned n, char f);
void FUN_001b567c(Buf_001b5410 *buf, unsigned n, const Elem_001b5410 &x, False_001b5410);
void FUN_001b55d4(Buf_001b5410 *buf, Elem_001b5410 *first, Elem_001b5410 *last, False_001b5410);
void FUN_001b5c9c(Buf_001b5410 *buf, int flag);
}
class Buf_001b5410 {
public:
    Elem_001b5410 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_001b5410(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_001b5410 f) { FUN_001b63a4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_001b5410(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_001b5410() { return Alloc_001b5410().max_size(); }
static inline unsigned Grow_001b5410(Vec_001b5410 *v, unsigned need)
{
    const unsigned ms = MaxSize_001b5410();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_001b5410((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_001b5410((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_001b5410(Vec_001b5410 *v, unsigned n, const Elem_001b5410 &x)
{
    Buf_001b5410 buf(&v->capacity);
    buf.reserve(Grow_001b5410(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_001b567c(&buf, n, x, False_001b5410());
    FUN_001b55d4(&buf, v->data, v->data + v->size, False_001b5410());
    Swap_001b5410(v->capacity, buf.capacity);
    Swap_001b5410(v->data, buf.data);
    Swap_001b5410(v->size, buf.size);
    FUN_001b5c9c(&buf, -1);
}
