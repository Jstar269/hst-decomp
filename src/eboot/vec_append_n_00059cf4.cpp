/* HSTMATCH module=EBOOT.BIN start=0x00059cf4 end=0x00059eb8 symbol=FUN_00059cf4 lang=c++ */
/* Clone of src/sharing_main/vec_append_n_0005a9ac.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_00059cf4 { char v; Flag_00059cf4(char x) : v(x) {} };
struct False_00059cf4 {};
template <class T> inline const T &Max_00059cf4(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00059cf4(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00059cf4 { int w[36]; };
struct Alloc_00059cf4 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00059cf4); }
};
struct Vec_00059cf4 { Elem_00059cf4 *data; unsigned size; unsigned capacity; };
class Buf_00059cf4;
extern "C" {
void FUN_0005a1ec(Buf_00059cf4 *buf, unsigned n, char f);
void FUN_00059f60(Buf_00059cf4 *buf, unsigned n, const Elem_00059cf4 &x, False_00059cf4);
void FUN_00059eb8(Buf_00059cf4 *buf, Elem_00059cf4 *first, Elem_00059cf4 *last, False_00059cf4);
void FUN_0005a0ec(Buf_00059cf4 *buf, int flag);
}
class Buf_00059cf4 {
public:
    Elem_00059cf4 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00059cf4(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00059cf4 f) { FUN_0005a1ec(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00059cf4(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_00059cf4() { return Alloc_00059cf4().max_size(); }
static inline unsigned Grow_00059cf4(Vec_00059cf4 *v, unsigned need)
{
    const unsigned ms = MaxSize_00059cf4();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00059cf4((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00059cf4((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00059cf4(Vec_00059cf4 *v, unsigned n, const Elem_00059cf4 &x)
{
    Buf_00059cf4 buf(&v->capacity);
    buf.reserve(Grow_00059cf4(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00059f60(&buf, n, x, False_00059cf4());
    FUN_00059eb8(&buf, v->data, v->data + v->size, False_00059cf4());
    Swap_00059cf4(v->capacity, buf.capacity);
    Swap_00059cf4(v->data, buf.data);
    Swap_00059cf4(v->size, buf.size);
    FUN_0005a0ec(&buf, -1);
}
