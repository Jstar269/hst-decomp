/* HSTMATCH module=EBOOT.BIN start=0x0017e0f4 end=0x0017e324 symbol=FUN_0017e0f4 lang=c++ */
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
struct E_0017e0f4 {};
template <class T> inline const T &Max_0017e0f4(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0017e0f4(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0017e0f4(int *const &a, int *const &b) { return b - a; }
inline void FillN_0017e0f4(int *p, int n, const int &x, E_0017e0f4) { for (; n != 0; --n) *p++ = x; }
inline void Move_0017e0f4(int *dst, int *src, unsigned bytes, E_0017e0f4) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_0017e0f4 { int *data; int size; unsigned capacity; };
inline void Clear_0017e0f4(Vec_0017e0f4 *v, E_0017e0f4) { v->size = 0; }
class D_0017e48c {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0017e48c(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_0017e48c();
};
extern "C" void FUN_0017e4fc(D_0017e48c *buf, unsigned n, E_0017e0f4 f);
inline void Reserve2_0017e0f4(D_0017e48c *b, unsigned n, E_0017e0f4 f) { FUN_0017e4fc(b, n, f); }
inline void Reserve_0017e0f4(D_0017e48c *b, unsigned n) { Reserve2_0017e0f4(b, n, E_0017e0f4()); }
static inline unsigned Grow_0017e0f4(Vec_0017e0f4 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_0017e0f4((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_0017e0f4((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_0017e0f4(Vec_0017e0f4 *v, int n, const int *value)
{
    D_0017e48c buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_0017e0f4(&buf, Grow_0017e0f4(v, need));
    buf.start = v->size;
    FillN_0017e0f4(buf.data + buf.start + buf.size, n, *value, E_0017e0f4());
    buf.size += n;
    int *old = v->data;
    int count = Distance_0017e0f4(old, old + v->size);
    buf.start -= count;
    Move_0017e0f4(buf.data + buf.start, old, count * 4, E_0017e0f4());
    buf.size += count;
    Clear_0017e0f4(v, E_0017e0f4());
    Swap_0017e0f4(v->capacity, buf.capacity);
    Swap_0017e0f4(v->data, buf.data);
    Swap_0017e0f4(v->size, buf.size);
}
