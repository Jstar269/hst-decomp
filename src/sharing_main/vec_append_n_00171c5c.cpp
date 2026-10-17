/* HSTMATCH module=hstp_trans_main.prx start=0x00171c5c end=0x00171e20 symbol=FUN_00171c5c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer, instance whose element is 556 bytes
   (modelled as int w[139]). Same retail code as src/sharing_main/vec_append_n_000678fc.cpp (12-byte
   element); this file was adapted from it: only sizeof(Elem), the derived max_size() constants and the
   four callee addresses (reserve, fill, move-in, buffer destructor) differ. The fill and move-in helpers
   take an empty tag by value; the reserve helper takes a char flag built one inline level below
   reserve(). Grow: 1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed.
   Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag_00171c5c { char v; Flag_00171c5c(char x) : v(x) {} };
struct False_00171c5c {};
template <class T> inline const T &Max_00171c5c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00171c5c(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00171c5c { int w[139]; };
struct Alloc_00171c5c {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00171c5c); }
};
struct Vec_00171c5c { Elem_00171c5c *data; unsigned size; unsigned capacity; };
class Buf_00171c5c;
extern "C" {
void FUN_00172ad4(Buf_00171c5c *buf, unsigned n, char f);
void FUN_00171ec8(Buf_00171c5c *buf, unsigned n, const Elem_00171c5c &x, False_00171c5c);
void FUN_00171e20(Buf_00171c5c *buf, Elem_00171c5c *first, Elem_00171c5c *last, False_00171c5c);
void FUN_0017286c(Buf_00171c5c *buf, int flag);
}
class Buf_00171c5c {
public:
    Elem_00171c5c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00171c5c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00171c5c f) { FUN_00172ad4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00171c5c(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_00171c5c() { return Alloc_00171c5c().max_size(); }
static inline unsigned Grow_00171c5c(Vec_00171c5c *v, unsigned need)
{
    const unsigned ms = MaxSize_00171c5c();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00171c5c((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00171c5c((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00171c5c(Vec_00171c5c *v, unsigned n, const Elem_00171c5c &x)
{
    Buf_00171c5c buf(&v->capacity);
    buf.reserve(Grow_00171c5c(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00171ec8(&buf, n, x, False_00171c5c());
    FUN_00171e20(&buf, v->data, v->data + v->size, False_00171c5c());
    Swap_00171c5c(v->capacity, buf.capacity);
    Swap_00171c5c(v->data, buf.data);
    Swap_00171c5c(v->size, buf.size);
    FUN_0017286c(&buf, -1);
}
