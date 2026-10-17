/* HSTMATCH module=hstp_trans_main.prx start=0x00154b60 end=0x00154d24 symbol=FUN_00154b60 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer, instance whose element is 40 bytes
   (modelled as int w[10]). Same retail code as src/sharing_main/vec_append_n_000678fc.cpp (12-byte
   element); this file was adapted from it: only sizeof(Elem), the derived max_size() constants and the
   four callee addresses (reserve, fill, move-in, buffer destructor) differ. The fill and move-in helpers
   take an empty tag by value; the reserve helper takes a char flag built one inline level below
   reserve(). Grow: 1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed.
   Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag_00154b60 { char v; Flag_00154b60(char x) : v(x) {} };
struct False_00154b60 {};
template <class T> inline const T &Max_00154b60(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00154b60(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00154b60 { int w[10]; };
struct Alloc_00154b60 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00154b60); }
};
struct Vec_00154b60 { Elem_00154b60 *data; unsigned size; unsigned capacity; };
class Buf_00154b60;
extern "C" {
void FUN_00156910(Buf_00154b60 *buf, unsigned n, char f);
void FUN_00154d24(Buf_00154b60 *buf, unsigned n, const Elem_00154b60 &x, False_00154b60);
void FUN_001548b8(Buf_00154b60 *buf, Elem_00154b60 *first, Elem_00154b60 *last, False_00154b60);
void FUN_00152f14(Buf_00154b60 *buf, int flag);
}
class Buf_00154b60 {
public:
    Elem_00154b60 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00154b60(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00154b60 f) { FUN_00156910(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00154b60(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_00154b60() { return Alloc_00154b60().max_size(); }
static inline unsigned Grow_00154b60(Vec_00154b60 *v, unsigned need)
{
    const unsigned ms = MaxSize_00154b60();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00154b60((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00154b60((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00154b60(Vec_00154b60 *v, unsigned n, const Elem_00154b60 &x)
{
    Buf_00154b60 buf(&v->capacity);
    buf.reserve(Grow_00154b60(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00154d24(&buf, n, x, False_00154b60());
    FUN_001548b8(&buf, v->data, v->data + v->size, False_00154b60());
    Swap_00154b60(v->capacity, buf.capacity);
    Swap_00154b60(v->data, buf.data);
    Swap_00154b60(v->size, buf.size);
    FUN_00152f14(&buf, -1);
}
