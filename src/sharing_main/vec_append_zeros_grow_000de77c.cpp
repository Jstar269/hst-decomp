/* HSTMATCH module=hstp_trans_main.prx start=0x000de77c end=0x000de99c symbol=FUN_000de77c lang=c++ */
/* Clone of src/eboot/vec_append_zeros_grow_000da7bc.cpp (hstclone.py tag ds1018ar1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the sibling split-buffer append recipe vec_append_000d8e34.cpp); exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
struct E_000de77c;
void FUN_0005f7ec(void *buf, unsigned n, E_000de77c tag);
void FUN_0005f5c8(void *buf, int flag);
}
struct E_000de77c {};
template <class T> inline const T &Max_000de77c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000de77c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000de77c(int *const &a, int *const &b) { return b - a; }
inline void Move_000de77c(int *dst, int *src, unsigned bytes, E_000de77c) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
inline void Fill_000de77c(int *p, unsigned n, E_000de77c) { FUN_000114c0(p, 0, n << 2); }
struct Vec_000de77c { int *data; int size; unsigned capacity; };
class D_000de77c {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000de77c(unsigned *a, E_000de77c) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
inline void Reserve2_000de77c(D_000de77c *b, unsigned n, E_000de77c f) { FUN_0005f7ec(b, n, f); }
inline void Reserve_000de77c(D_000de77c *b, unsigned n) { Reserve2_000de77c(b, n, E_000de77c()); }
static inline unsigned Grow_000de77c(Vec_000de77c *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_000de77c((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_000de77c((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_000de77c(Vec_000de77c *v, unsigned n)
{
    D_000de77c buf(&v->capacity, E_000de77c());
    unsigned need = v->size + n - v->capacity;
    Reserve_000de77c(&buf, Grow_000de77c(v, need));
    buf.start = v->size;
    Fill_000de77c(buf.data + buf.start + buf.size, n, E_000de77c());
    buf.size += n;
    int *old = v->data;
    int count = Distance_000de77c(old, old + v->size);
    buf.start -= count;
    Move_000de77c(buf.data + buf.start, old, count * 4, E_000de77c());
    buf.size += count;
    v->size = 0;
    Swap_000de77c(v->capacity, buf.capacity);
    Swap_000de77c(v->data, buf.data);
    Swap_000de77c(v->size, buf.size);
    FUN_0005f5c8(&buf, -1);
}
