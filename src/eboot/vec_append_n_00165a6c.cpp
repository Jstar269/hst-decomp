/* HSTMATCH module=EBOOT.BIN start=0x00165a6c end=0x00165c30 symbol=FUN_00165a6c lang=c++ */
/* Clone of src/sharing_main/vec_append_n_00171c5c.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_00165a6c { char v; Flag_00165a6c(char x) : v(x) {} };
struct False_00165a6c {};
template <class T> inline const T &Max_00165a6c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00165a6c(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00165a6c { int w[139]; };
struct Alloc_00165a6c {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00165a6c); }
};
struct Vec_00165a6c { Elem_00165a6c *data; unsigned size; unsigned capacity; };
class Buf_00165a6c;
extern "C" {
void FUN_00166910(Buf_00165a6c *buf, unsigned n, char f);
void FUN_00165cd8(Buf_00165a6c *buf, unsigned n, const Elem_00165a6c &x, False_00165a6c);
void FUN_00165c30(Buf_00165a6c *buf, Elem_00165a6c *first, Elem_00165a6c *last, False_00165a6c);
void FUN_001666a8(Buf_00165a6c *buf, int flag);
}
class Buf_00165a6c {
public:
    Elem_00165a6c *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00165a6c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00165a6c f) { FUN_00166910(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00165a6c(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_00165a6c() { return Alloc_00165a6c().max_size(); }
static inline unsigned Grow_00165a6c(Vec_00165a6c *v, unsigned need)
{
    const unsigned ms = MaxSize_00165a6c();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00165a6c((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00165a6c((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00165a6c(Vec_00165a6c *v, unsigned n, const Elem_00165a6c &x)
{
    Buf_00165a6c buf(&v->capacity);
    buf.reserve(Grow_00165a6c(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00165cd8(&buf, n, x, False_00165a6c());
    FUN_00165c30(&buf, v->data, v->data + v->size, False_00165a6c());
    Swap_00165a6c(v->capacity, buf.capacity);
    Swap_00165a6c(v->data, buf.data);
    Swap_00165a6c(v->size, buf.size);
    FUN_001666a8(&buf, -1);
}
