/* HSTMATCH module=hstp_trans_main.prx start=0x0007032c end=0x0007055c symbol=FUN_0007032c lang=c++ */
/* Clone of src/eboot/vec_append_000b49ec.cpp (hstclone.py tag c24): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Container append of n copies of *value through a local split buffer: grow, reserve, fill, move the old
   elements in front, clear the old storage, swap buffers; the buffer's destructor (0xb6320) frees the old
   block. Names provisional. */
extern "C" {
void FUN_000043b4(void);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}
/* Empty tag type (an int2type-style dispatch tag). Each by-value tag temporary reserves a phantom
   4-byte frame slot; the four tags (reserve, fill, move, clear) produce the retail 96-byte frame. */
struct E_0007032c {};
template <class T> inline const T &Max_0007032c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0007032c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0007032c(int *const &a, int *const &b) { return b - a; }
inline void FillN_0007032c(int *p, int n, const int &x, E_0007032c) { for (; n != 0; --n) *p++ = x; }
inline void Move_0007032c(int *dst, int *src, unsigned bytes, E_0007032c) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_0007032c { int *data; int size; unsigned capacity; };
inline void Clear_0007032c(Vec_0007032c *v, E_0007032c) { v->size = 0; }
class D_000706c4 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000706c4(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000706c4();
};
extern "C" void FUN_00070734(D_000706c4 *buf, unsigned n, E_0007032c f);
inline void Reserve2_0007032c(D_000706c4 *b, unsigned n, E_0007032c f) { FUN_00070734(b, n, f); }
inline void Reserve_0007032c(D_000706c4 *b, unsigned n) { Reserve2_0007032c(b, n, E_0007032c()); }
static inline unsigned Grow_0007032c(Vec_0007032c *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_0007032c((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_0007032c((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_0007032c(Vec_0007032c *v, int n, const int *value)
{
    D_000706c4 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_0007032c(&buf, Grow_0007032c(v, need));
    buf.start = v->size;
    FillN_0007032c(buf.data + buf.start + buf.size, n, *value, E_0007032c());
    buf.size += n;
    int *old = v->data;
    int count = Distance_0007032c(old, old + v->size);
    buf.start -= count;
    Move_0007032c(buf.data + buf.start, old, count * 4, E_0007032c());
    buf.size += count;
    Clear_0007032c(v, E_0007032c());
    Swap_0007032c(v->capacity, buf.capacity);
    Swap_0007032c(v->data, buf.data);
    Swap_0007032c(v->size, buf.size);
}
