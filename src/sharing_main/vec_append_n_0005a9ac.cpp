/* HSTMATCH module=hstp_trans_main.prx start=0x0005a9ac end=0x0005ab70 symbol=FUN_0005a9ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer, instance whose element is 144 bytes
   (modelled as int w[36]). Same retail code as src/sharing_main/vec_append_n_000678fc.cpp (12-byte
   element); this file was adapted from it: only sizeof(Elem), the derived max_size() constants and the
   four callee addresses (reserve, fill, move-in, buffer destructor) differ. The fill and move-in helpers
   take an empty tag by value; the reserve helper takes a char flag built one inline level below
   reserve(). Grow: 1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed.
   Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag_0005a9ac { char v; Flag_0005a9ac(char x) : v(x) {} };
struct False_0005a9ac {};
template <class T> inline const T &Max_0005a9ac(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0005a9ac(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_0005a9ac { int w[36]; };
struct Alloc_0005a9ac {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_0005a9ac); }
};
struct Vec_0005a9ac { Elem_0005a9ac *data; unsigned size; unsigned capacity; };
class Buf_0005a9ac;
extern "C" {
void FUN_0005aea4(Buf_0005a9ac *buf, unsigned n, char f);
void FUN_0005ac18(Buf_0005a9ac *buf, unsigned n, const Elem_0005a9ac &x, False_0005a9ac);
void FUN_0005ab70(Buf_0005a9ac *buf, Elem_0005a9ac *first, Elem_0005a9ac *last, False_0005a9ac);
void FUN_0005ada4(Buf_0005a9ac *buf, int flag);
}
class Buf_0005a9ac {
public:
    Elem_0005a9ac *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_0005a9ac(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_0005a9ac f) { FUN_0005aea4(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_0005a9ac(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_0005a9ac() { return Alloc_0005a9ac().max_size(); }
static inline unsigned Grow_0005a9ac(Vec_0005a9ac *v, unsigned need)
{
    const unsigned ms = MaxSize_0005a9ac();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_0005a9ac((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_0005a9ac((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0005a9ac(Vec_0005a9ac *v, unsigned n, const Elem_0005a9ac &x)
{
    Buf_0005a9ac buf(&v->capacity);
    buf.reserve(Grow_0005a9ac(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_0005ac18(&buf, n, x, False_0005a9ac());
    FUN_0005ab70(&buf, v->data, v->data + v->size, False_0005a9ac());
    Swap_0005a9ac(v->capacity, buf.capacity);
    Swap_0005a9ac(v->data, buf.data);
    Swap_0005a9ac(v->size, buf.size);
    FUN_0005ada4(&buf, -1);
}
