/* HSTMATCH module=hstp_trans_main.prx start=0x00155d90 end=0x00155fc0 symbol=FUN_00155d90 lang=c++ */
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
struct E_00155d90 {};
template <class T> inline const T &Max_00155d90(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00155d90(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00155d90(int *const &a, int *const &b) { return b - a; }
inline void FillN_00155d90(int *p, int n, const int &x, E_00155d90) { for (; n != 0; --n) *p++ = x; }
inline void Move_00155d90(int *dst, int *src, unsigned bytes, E_00155d90) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_00155d90 { int *data; int size; unsigned capacity; };
inline void Clear_00155d90(Vec_00155d90 *v, E_00155d90) { v->size = 0; }
class D_0015681c {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0015681c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_0015681c();
};
extern "C" void FUN_001569b8(D_0015681c *buf, unsigned n, E_00155d90 f);
inline void Reserve2_00155d90(D_0015681c *b, unsigned n, E_00155d90 f) { FUN_001569b8(b, n, f); }
inline void Reserve_00155d90(D_0015681c *b, unsigned n) { Reserve2_00155d90(b, n, E_00155d90()); }
static inline unsigned Grow_00155d90(Vec_00155d90 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00155d90((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00155d90((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_00155d90(Vec_00155d90 *v, int n, const int *value)
{
    D_0015681c buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_00155d90(&buf, Grow_00155d90(v, need));
    buf.start = v->size;
    FillN_00155d90(buf.data + buf.start + buf.size, n, *value, E_00155d90());
    buf.size += n;
    int *old = v->data;
    int count = Distance_00155d90(old, old + v->size);
    buf.start -= count;
    Move_00155d90(buf.data + buf.start, old, count * 4, E_00155d90());
    buf.size += count;
    Clear_00155d90(v, E_00155d90());
    Swap_00155d90(v->capacity, buf.capacity);
    Swap_00155d90(v->data, buf.data);
    Swap_00155d90(v->size, buf.size);
}
