/* HSTMATCH module=hstp_trans_main.prx start=0x000daa64 end=0x000dac20 symbol=FUN_000daa64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Container append of n copies of x through a local split buffer, instance whose element is 64 bytes
   (modelled as int w[16]). Same retail code as src/sharing_main/vec_append_n_000678fc.cpp (12-byte
   element); this file was adapted from it: only sizeof(Elem), the derived max_size() constants and the
   four callee addresses (reserve, fill, move-in, buffer destructor) differ. The fill and move-in helpers
   take an empty tag by value; the reserve helper takes a char flag built one inline level below
   reserve(). Grow: 1.6x below max/3, 1.5x below 2*max/3, else max_size; never less than needed.
   Names provisional. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag_000daa64 { char v; Flag_000daa64(char x) : v(x) {} };
struct False_000daa64 {};
template <class T> inline const T &Max_000daa64(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000daa64(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_000daa64 { int w[16]; };
struct Alloc_000daa64 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000daa64); }
};
struct Vec_000daa64 { Elem_000daa64 *data; unsigned size; unsigned capacity; };
class Buf_000daa64;
extern "C" {
void FUN_000db668(Buf_000daa64 *buf, unsigned n, char f);
void FUN_000dacec(Buf_000daa64 *buf, unsigned n, const Elem_000daa64 &x, False_000daa64);
void FUN_000dac20(Buf_000daa64 *buf, Elem_000daa64 *first, Elem_000daa64 *last, False_000daa64);
void FUN_000db2f8(Buf_000daa64 *buf, int flag);
}
class Buf_000daa64 {
public:
    Elem_000daa64 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000daa64(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000daa64 f) { FUN_000db668(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000daa64(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_000daa64() { return Alloc_000daa64().max_size(); }
static inline unsigned Grow_000daa64(Vec_000daa64 *v, unsigned need)
{
    const unsigned ms = MaxSize_000daa64();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000daa64((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000daa64((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000daa64(Vec_000daa64 *v, unsigned n, const Elem_000daa64 &x)
{
    Buf_000daa64 buf(&v->capacity);
    buf.reserve(Grow_000daa64(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_000dacec(&buf, n, x, False_000daa64());
    FUN_000dac20(&buf, v->data, v->data + v->size, False_000daa64());
    Swap_000daa64(v->capacity, buf.capacity);
    Swap_000daa64(v->data, buf.data);
    Swap_000daa64(v->size, buf.size);
    FUN_000db2f8(&buf, -1);
}
