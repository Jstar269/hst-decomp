/* HSTMATCH module=EBOOT.BIN start=0x0005e434 end=0x0005e664 symbol=FUN_0005e434 lang=c++ */
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
struct E_0005e434 {};
template <class T> inline const T &Max_0005e434(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0005e434(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0005e434(int *const &a, int *const &b) { return b - a; }
inline void FillN_0005e434(int *p, int n, const int &x, E_0005e434) { for (; n != 0; --n) *p++ = x; }
inline void Move_0005e434(int *dst, int *src, unsigned bytes, E_0005e434) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_0005e434 { int *data; int size; unsigned capacity; };
inline void Clear_0005e434(Vec_0005e434 *v, E_0005e434) { v->size = 0; }
class D_0005e848 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0005e848(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_0005e848();
};
extern "C" void FUN_0005e8b8(D_0005e848 *buf, unsigned n, E_0005e434 f);
inline void Reserve2_0005e434(D_0005e848 *b, unsigned n, E_0005e434 f) { FUN_0005e8b8(b, n, f); }
inline void Reserve_0005e434(D_0005e848 *b, unsigned n) { Reserve2_0005e434(b, n, E_0005e434()); }
static inline unsigned Grow_0005e434(Vec_0005e434 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_0005e434((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_0005e434((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_0005e434(Vec_0005e434 *v, int n, const int *value)
{
    D_0005e848 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_0005e434(&buf, Grow_0005e434(v, need));
    buf.start = v->size;
    FillN_0005e434(buf.data + buf.start + buf.size, n, *value, E_0005e434());
    buf.size += n;
    int *old = v->data;
    int count = Distance_0005e434(old, old + v->size);
    buf.start -= count;
    Move_0005e434(buf.data + buf.start, old, count * 4, E_0005e434());
    buf.size += count;
    Clear_0005e434(v, E_0005e434());
    Swap_0005e434(v->capacity, buf.capacity);
    Swap_0005e434(v->data, buf.data);
    Swap_0005e434(v->size, buf.size);
}
