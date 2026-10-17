/* HSTMATCH module=EBOOT.BIN start=0x000bf13c end=0x000bf36c symbol=FUN_000bf13c lang=c++ */
/* Clone of src/eboot/vec_append_000b49ec.cpp (hstclone.py tag c26): addresses substituted; exact match verified; names and types await human review. */
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
struct E_000bf13c {};
template <class T> inline const T &Max_000bf13c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000bf13c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000bf13c(int *const &a, int *const &b) { return b - a; }
inline void FillN_000bf13c(int *p, int n, const int &x, E_000bf13c) { for (; n != 0; --n) *p++ = x; }
inline void Move_000bf13c(int *dst, int *src, unsigned bytes, E_000bf13c) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_000bf13c { int *data; int size; unsigned capacity; };
inline void Clear_000bf13c(Vec_000bf13c *v, E_000bf13c) { v->size = 0; }
class D_000bf844 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000bf844(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000bf844();
};
extern "C" void FUN_000bf9c0(D_000bf844 *buf, unsigned n, E_000bf13c f);
inline void Reserve2_000bf13c(D_000bf844 *b, unsigned n, E_000bf13c f) { FUN_000bf9c0(b, n, f); }
inline void Reserve_000bf13c(D_000bf844 *b, unsigned n) { Reserve2_000bf13c(b, n, E_000bf13c()); }
static inline unsigned Grow_000bf13c(Vec_000bf13c *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_000bf13c((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_000bf13c((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_000bf13c(Vec_000bf13c *v, int n, const int *value)
{
    D_000bf844 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_000bf13c(&buf, Grow_000bf13c(v, need));
    buf.start = v->size;
    FillN_000bf13c(buf.data + buf.start + buf.size, n, *value, E_000bf13c());
    buf.size += n;
    int *old = v->data;
    int count = Distance_000bf13c(old, old + v->size);
    buf.start -= count;
    Move_000bf13c(buf.data + buf.start, old, count * 4, E_000bf13c());
    buf.size += count;
    Clear_000bf13c(v, E_000bf13c());
    Swap_000bf13c(v->capacity, buf.capacity);
    Swap_000bf13c(v->data, buf.data);
    Swap_000bf13c(v->size, buf.size);
}
