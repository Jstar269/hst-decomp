/* HSTMATCH module=hstp_trans_main.prx start=0x000678fc end=0x00067ac0 symbol=FUN_000678fc lang=c++ */
/* Clone of src/eboot/vec_append_n_000664a8.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct Flag_000678fc { char v; Flag_000678fc(char x) : v(x) {} };
struct False_000678fc {};
template <class T> inline const T &Max_000678fc(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000678fc(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem_000678fc { int w[3]; };
struct Alloc_000678fc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem_000678fc); }
};
struct Vec_000678fc { Elem_000678fc *data; unsigned size; unsigned capacity; };
class Buf_000678fc;
extern "C" {
void FUN_000686e0(Buf_000678fc *buf, unsigned n, char f);
void FUN_00067b68(Buf_000678fc *buf, unsigned n, const Elem_000678fc &x, False_000678fc);
void FUN_00067ac0(Buf_000678fc *buf, Elem_000678fc *first, Elem_000678fc *last, False_000678fc);
void FUN_000684b0(Buf_000678fc *buf, int flag);
}
class Buf_000678fc {
public:
    Elem_000678fc *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf_000678fc(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag_000678fc f) { FUN_000686e0(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag_000678fc(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize_000678fc() { return Alloc_000678fc().max_size(); }
static inline unsigned Grow_000678fc(Vec_000678fc *v, unsigned need)
{
    const unsigned ms = MaxSize_000678fc();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max_000678fc((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max_000678fc((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_000678fc(Vec_000678fc *v, unsigned n, const Elem_000678fc &x)
{
    Buf_000678fc buf(&v->capacity);
    buf.reserve(Grow_000678fc(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_00067b68(&buf, n, x, False_000678fc());
    FUN_00067ac0(&buf, v->data, v->data + v->size, False_000678fc());
    Swap_000678fc(v->capacity, buf.capacity);
    Swap_000678fc(v->data, buf.data);
    Swap_000678fc(v->size, buf.size);
    FUN_000684b0(&buf, -1);
}
