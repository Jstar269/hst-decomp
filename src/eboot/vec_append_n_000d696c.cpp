/* HSTMATCH module=EBOOT.BIN start=0x000d696c end=0x000d6b30 symbol=FUN_000d696c lang=c++ */
/* Clone of src/sharing_main/vec_append_n_000da65c.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer, instance whose element is 24 bytes
   (modelled as int w[6]). Same retail code as src/sharing_main/vec_append_n_000678fc.cpp (12-byte
   element); this file was adapted from it: only sizeof(Elem), the derived max_size() constants and the
   four callee addresses (reserve, fill, move-in, buffer destructor) differ. The fill and move-in helpers
   take an empty tag by value; the reserve helper takes a char flag built one inline level below
   reserve(). Grow: 1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed.
   Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag_000d696c { char v; Flag_000d696c(char x) : v(x) {} };
struct False_000d696c {};
template <class T> inline const T &Max_000d696c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000d696c(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_000d696c { int w[6]; };
struct Alloc_000d696c {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000d696c); }
};
struct Vec_000d696c { Elem_000d696c *data; unsigned size; unsigned capacity; };
class Buf_000d696c;
extern "C" {
void FUN_000d7a14(Buf_000d696c *buf, unsigned n, char f);
void FUN_000d6bd8(Buf_000d696c *buf, unsigned n, const Elem_000d696c &x, False_000d696c);
void FUN_000d6b30(Buf_000d696c *buf, Elem_000d696c *first, Elem_000d696c *last, False_000d696c);
void FUN_000d7674(Buf_000d696c *buf, int flag);
}
class Buf_000d696c {
public:
    Elem_000d696c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000d696c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000d696c f) { FUN_000d7a14(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000d696c(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_000d696c() { return Alloc_000d696c().max_size(); }
static inline unsigned Grow_000d696c(Vec_000d696c *v, unsigned need)
{
    const unsigned ms = MaxSize_000d696c();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000d696c((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000d696c((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000d696c(Vec_000d696c *v, unsigned n, const Elem_000d696c &x)
{
    Buf_000d696c buf(&v->capacity);
    buf.reserve(Grow_000d696c(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_000d6bd8(&buf, n, x, False_000d696c());
    FUN_000d6b30(&buf, v->data, v->data + v->size, False_000d696c());
    Swap_000d696c(v->capacity, buf.capacity);
    Swap_000d696c(v->data, buf.data);
    Swap_000d696c(v->size, buf.size);
    FUN_000d7674(&buf, -1);
}
