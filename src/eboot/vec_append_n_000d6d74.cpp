/* HSTMATCH module=EBOOT.BIN start=0x000d6d74 end=0x000d6f30 symbol=FUN_000d6d74 lang=c++ */
/* Clone of src/sharing_main/vec_append_n_000daa64.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_000d6d74 { char v; Flag_000d6d74(char x) : v(x) {} };
struct False_000d6d74 {};
template <class T> inline const T &Max_000d6d74(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000d6d74(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_000d6d74 { int w[16]; };
struct Alloc_000d6d74 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000d6d74); }
};
struct Vec_000d6d74 { Elem_000d6d74 *data; unsigned size; unsigned capacity; };
class Buf_000d6d74;
extern "C" {
void FUN_000d7978(Buf_000d6d74 *buf, unsigned n, char f);
void FUN_000d6ffc(Buf_000d6d74 *buf, unsigned n, const Elem_000d6d74 &x, False_000d6d74);
void FUN_000d6f30(Buf_000d6d74 *buf, Elem_000d6d74 *first, Elem_000d6d74 *last, False_000d6d74);
void FUN_000d7608(Buf_000d6d74 *buf, int flag);
}
class Buf_000d6d74 {
public:
    Elem_000d6d74 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000d6d74(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000d6d74 f) { FUN_000d7978(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000d6d74(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_000d6d74() { return Alloc_000d6d74().max_size(); }
static inline unsigned Grow_000d6d74(Vec_000d6d74 *v, unsigned need)
{
    const unsigned ms = MaxSize_000d6d74();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000d6d74((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000d6d74((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000d6d74(Vec_000d6d74 *v, unsigned n, const Elem_000d6d74 &x)
{
    Buf_000d6d74 buf(&v->capacity);
    buf.reserve(Grow_000d6d74(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_000d6ffc(&buf, n, x, False_000d6d74());
    FUN_000d6f30(&buf, v->data, v->data + v->size, False_000d6d74());
    Swap_000d6d74(v->capacity, buf.capacity);
    Swap_000d6d74(v->data, buf.data);
    Swap_000d6d74(v->size, buf.size);
    FUN_000d7608(&buf, -1);
}
