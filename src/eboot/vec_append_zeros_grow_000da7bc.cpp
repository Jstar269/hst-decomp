/* HSTMATCH module=EBOOT.BIN start=0x000da7bc end=0x000da9dc symbol=FUN_000da7bc lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the sibling split-buffer append recipe vec_append_000d8e34.cpp); exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
struct E_000da7bc;
void FUN_0005e9fc(void *buf, unsigned n, E_000da7bc tag);
void FUN_0005e7d8(void *buf, int flag);
}
struct E_000da7bc {};
template <class T> inline const T &Max_000da7bc(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000da7bc(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000da7bc(int *const &a, int *const &b) { return b - a; }
inline void Move_000da7bc(int *dst, int *src, unsigned bytes, E_000da7bc) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
inline void Fill_000da7bc(int *p, unsigned n, E_000da7bc) { FUN_000114c0(p, 0, n << 2); }
struct Vec_000da7bc { int *data; int size; unsigned capacity; };
class D_000da7bc {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000da7bc(unsigned *a, E_000da7bc) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
inline void Reserve2_000da7bc(D_000da7bc *b, unsigned n, E_000da7bc f) { FUN_0005e9fc(b, n, f); }
inline void Reserve_000da7bc(D_000da7bc *b, unsigned n) { Reserve2_000da7bc(b, n, E_000da7bc()); }
static inline unsigned Grow_000da7bc(Vec_000da7bc *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_000da7bc((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_000da7bc((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_000da7bc(Vec_000da7bc *v, unsigned n)
{
    D_000da7bc buf(&v->capacity, E_000da7bc());
    unsigned need = v->size + n - v->capacity;
    Reserve_000da7bc(&buf, Grow_000da7bc(v, need));
    buf.start = v->size;
    Fill_000da7bc(buf.data + buf.start + buf.size, n, E_000da7bc());
    buf.size += n;
    int *old = v->data;
    int count = Distance_000da7bc(old, old + v->size);
    buf.start -= count;
    Move_000da7bc(buf.data + buf.start, old, count * 4, E_000da7bc());
    buf.size += count;
    v->size = 0;
    Swap_000da7bc(v->capacity, buf.capacity);
    Swap_000da7bc(v->data, buf.data);
    Swap_000da7bc(v->size, buf.size);
    FUN_0005e7d8(&buf, -1);
}
