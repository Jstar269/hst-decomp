/* HSTMATCH module=hstp_trans_main.prx start=0x00101b3c end=0x00101d6c symbol=FUN_00101b3c lang=c++ */
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
struct E_00101b3c {};
template <class T> inline const T &Max_00101b3c(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00101b3c(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00101b3c(int *const &a, int *const &b) { return b - a; }
inline void FillN_00101b3c(int *p, int n, const int &x, E_00101b3c) { for (; n != 0; --n) *p++ = x; }
inline void Move_00101b3c(int *dst, int *src, unsigned bytes, E_00101b3c) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_00101b3c { int *data; int size; unsigned capacity; };
inline void Clear_00101b3c(Vec_00101b3c *v, E_00101b3c) { v->size = 0; }
class D_00101e50 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_00101e50(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_00101e50();
};
extern "C" void FUN_00101ec0(D_00101e50 *buf, unsigned n, E_00101b3c f);
inline void Reserve2_00101b3c(D_00101e50 *b, unsigned n, E_00101b3c f) { FUN_00101ec0(b, n, f); }
inline void Reserve_00101b3c(D_00101e50 *b, unsigned n) { Reserve2_00101b3c(b, n, E_00101b3c()); }
static inline unsigned Grow_00101b3c(Vec_00101b3c *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00101b3c((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00101b3c((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_00101b3c(Vec_00101b3c *v, int n, const int *value)
{
    D_00101e50 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_00101b3c(&buf, Grow_00101b3c(v, need));
    buf.start = v->size;
    FillN_00101b3c(buf.data + buf.start + buf.size, n, *value, E_00101b3c());
    buf.size += n;
    int *old = v->data;
    int count = Distance_00101b3c(old, old + v->size);
    buf.start -= count;
    Move_00101b3c(buf.data + buf.start, old, count * 4, E_00101b3c());
    buf.size += count;
    Clear_00101b3c(v, E_00101b3c());
    Swap_00101b3c(v->capacity, buf.capacity);
    Swap_00101b3c(v->data, buf.data);
    Swap_00101b3c(v->size, buf.size);
}
