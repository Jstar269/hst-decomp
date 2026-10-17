/* HSTMATCH module=EBOOT.BIN start=0x00149278 end=0x0014943c symbol=FUN_00149278 lang=c++ */
/* Clone of src/sharing_main/vec_append_n_00154b60.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_00149278 { char v; Flag_00149278(char x) : v(x) {} };
struct False_00149278 {};
template <class T> inline const T &Max_00149278(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00149278(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_00149278 { int w[10]; };
struct Alloc_00149278 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_00149278); }
};
struct Vec_00149278 { Elem_00149278 *data; unsigned size; unsigned capacity; };
class Buf_00149278;
extern "C" {
void FUN_0014b028(Buf_00149278 *buf, unsigned n, char f);
void FUN_0014943c(Buf_00149278 *buf, unsigned n, const Elem_00149278 &x, False_00149278);
void FUN_00148fd0(Buf_00149278 *buf, Elem_00149278 *first, Elem_00149278 *last, False_00149278);
void FUN_0014762c(Buf_00149278 *buf, int flag);
}
class Buf_00149278 {
public:
    Elem_00149278 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_00149278(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_00149278 f) { FUN_0014b028(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_00149278(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_00149278() { return Alloc_00149278().max_size(); }
static inline unsigned Grow_00149278(Vec_00149278 *v, unsigned need)
{
    const unsigned ms = MaxSize_00149278();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_00149278((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_00149278((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_00149278(Vec_00149278 *v, unsigned n, const Elem_00149278 &x)
{
    Buf_00149278 buf(&v->capacity);
    buf.reserve(Grow_00149278(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_0014943c(&buf, n, x, False_00149278());
    FUN_00148fd0(&buf, v->data, v->data + v->size, False_00149278());
    Swap_00149278(v->capacity, buf.capacity);
    Swap_00149278(v->data, buf.data);
    Swap_00149278(v->size, buf.size);
    FUN_0014762c(&buf, -1);
}
