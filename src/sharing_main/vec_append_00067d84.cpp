/* HSTMATCH module=hstp_trans_main.prx start=0x00067d84 end=0x00067fb4 symbol=FUN_00067d84 lang=c++ */
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
struct E_00067d84 {};
template <class T> inline const T &Max_00067d84(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00067d84(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00067d84(int *const &a, int *const &b) { return b - a; }
inline void FillN_00067d84(int *p, int n, const int &x, E_00067d84) { for (; n != 0; --n) *p++ = x; }
inline void Move_00067d84(int *dst, int *src, unsigned bytes, E_00067d84) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_00067d84 { int *data; int size; unsigned capacity; };
inline void Clear_00067d84(Vec_00067d84 *v, E_00067d84) { v->size = 0; }
class D_000685d4 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000685d4(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000685d4();
};
extern "C" void FUN_00068644(D_000685d4 *buf, unsigned n, E_00067d84 f);
inline void Reserve2_00067d84(D_000685d4 *b, unsigned n, E_00067d84 f) { FUN_00068644(b, n, f); }
inline void Reserve_00067d84(D_000685d4 *b, unsigned n) { Reserve2_00067d84(b, n, E_00067d84()); }
static inline unsigned Grow_00067d84(Vec_00067d84 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00067d84((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00067d84((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_00067d84(Vec_00067d84 *v, int n, const int *value)
{
    D_000685d4 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_00067d84(&buf, Grow_00067d84(v, need));
    buf.start = v->size;
    FillN_00067d84(buf.data + buf.start + buf.size, n, *value, E_00067d84());
    buf.size += n;
    int *old = v->data;
    int count = Distance_00067d84(old, old + v->size);
    buf.start -= count;
    Move_00067d84(buf.data + buf.start, old, count * 4, E_00067d84());
    buf.size += count;
    Clear_00067d84(v, E_00067d84());
    Swap_00067d84(v->capacity, buf.capacity);
    Swap_00067d84(v->data, buf.data);
    Swap_00067d84(v->size, buf.size);
}
