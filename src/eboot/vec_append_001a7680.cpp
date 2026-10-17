/* HSTMATCH module=EBOOT.BIN start=0x001a7680 end=0x001a78b0 symbol=FUN_001a7680 lang=c++ */
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
struct E_001a7680 {};
template <class T> inline const T &Max_001a7680(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001a7680(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001a7680(int *const &a, int *const &b) { return b - a; }
inline void FillN_001a7680(int *p, int n, const int &x, E_001a7680) { for (; n != 0; --n) *p++ = x; }
inline void Move_001a7680(int *dst, int *src, unsigned bytes, E_001a7680) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_001a7680 { int *data; int size; unsigned capacity; };
inline void Clear_001a7680(Vec_001a7680 *v, E_001a7680) { v->size = 0; }
class D_001a87f4 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_001a87f4(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_001a87f4();
};
extern "C" void FUN_001a8f1c(D_001a87f4 *buf, unsigned n, E_001a7680 f);
inline void Reserve2_001a7680(D_001a87f4 *b, unsigned n, E_001a7680 f) { FUN_001a8f1c(b, n, f); }
inline void Reserve_001a7680(D_001a87f4 *b, unsigned n) { Reserve2_001a7680(b, n, E_001a7680()); }
static inline unsigned Grow_001a7680(Vec_001a7680 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_001a7680((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_001a7680((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_001a7680(Vec_001a7680 *v, int n, const int *value)
{
    D_001a87f4 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_001a7680(&buf, Grow_001a7680(v, need));
    buf.start = v->size;
    FillN_001a7680(buf.data + buf.start + buf.size, n, *value, E_001a7680());
    buf.size += n;
    int *old = v->data;
    int count = Distance_001a7680(old, old + v->size);
    buf.start -= count;
    Move_001a7680(buf.data + buf.start, old, count * 4, E_001a7680());
    buf.size += count;
    Clear_001a7680(v, E_001a7680());
    Swap_001a7680(v->capacity, buf.capacity);
    Swap_001a7680(v->data, buf.data);
    Swap_001a7680(v->size, buf.size);
}
