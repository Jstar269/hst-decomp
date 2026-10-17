/* HSTMATCH module=EBOOT.BIN start=0x0023e680 end=0x0023e844 symbol=FUN_0023e680 lang=c++ */
/* Clone of src/eboot/vec_append_n_00148af0.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_0023e680 { char v; Flag_0023e680(char x) : v(x) {} };
struct False_0023e680 {};
template <class T> inline const T &Max_0023e680(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0023e680(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_0023e680 { int w[3]; };
struct Alloc_0023e680 {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_0023e680); }
};
struct Vec_0023e680 { Elem_0023e680 *data; unsigned size; unsigned capacity; };
class Buf_0023e680;
extern "C" {
void FUN_0023ec10(Buf_0023e680 *buf, unsigned n, char f);
void FUN_0023e930(Buf_0023e680 *buf, unsigned n, const Elem_0023e680 &x, False_0023e680);
void FUN_0023e844(Buf_0023e680 *buf, Elem_0023e680 *first, Elem_0023e680 *last, False_0023e680);
void FUN_0023eb04(Buf_0023e680 *buf, int flag);
}
class Buf_0023e680 {
public:
    Elem_0023e680 *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_0023e680(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_0023e680 f) { FUN_0023ec10(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_0023e680(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_0023e680() { return Alloc_0023e680().max_size(); }
static inline unsigned Grow_0023e680(Vec_0023e680 *v, unsigned need)
{
    const unsigned ms = MaxSize_0023e680();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_0023e680((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_0023e680((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0023e680(Vec_0023e680 *v, unsigned n, const Elem_0023e680 &x)
{
    Buf_0023e680 buf(&v->capacity);
    buf.reserve(Grow_0023e680(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_0023e930(&buf, n, x, False_0023e680());
    FUN_0023e844(&buf, v->data, v->data + v->size, False_0023e680());
    Swap_0023e680(v->capacity, buf.capacity);
    Swap_0023e680(v->data, buf.data);
    Swap_0023e680(v->size, buf.size);
    FUN_0023eb04(&buf, -1);
}
