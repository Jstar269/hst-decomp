/* HSTMATCH module=hstp_trans_main.prx start=0x0028c640 end=0x0028c870 symbol=FUN_0028c640 lang=c++ */
/* Clone of src/eboot/vec_append_00054668.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
struct E_0028c640 {};
template <class T> inline const T &Max_0028c640(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0028c640(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_0028c640(int *const &a, int *const &b) { return b - a; }
inline void FillN_0028c640(int *p, int n, const int &x, E_0028c640) { for (; n != 0; --n) *p++ = x; }
inline void Move_0028c640(int *dst, int *src, unsigned bytes, E_0028c640) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_0028c640 { int *data; int size; unsigned capacity; };
inline void Clear_0028c640(Vec_0028c640 *v, E_0028c640) { v->size = 0; }
class D_0028c9e4 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0028c9e4(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_0028c9e4();
};
extern "C" void FUN_0028ca54(D_0028c9e4 *buf, unsigned n, E_0028c640 f);
inline void Reserve2_0028c640(D_0028c9e4 *b, unsigned n, E_0028c640 f) { FUN_0028ca54(b, n, f); }
inline void Reserve_0028c640(D_0028c9e4 *b, unsigned n) { Reserve2_0028c640(b, n, E_0028c640()); }
static inline unsigned Grow_0028c640(Vec_0028c640 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_0028c640((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_0028c640((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_0028c640(Vec_0028c640 *v, int n, const int *value)
{
    D_0028c9e4 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_0028c640(&buf, Grow_0028c640(v, need));
    buf.start = v->size;
    FillN_0028c640(buf.data + buf.start + buf.size, n, *value, E_0028c640());
    buf.size += n;
    int *old = v->data;
    int count = Distance_0028c640(old, old + v->size);
    buf.start -= count;
    Move_0028c640(buf.data + buf.start, old, count * 4, E_0028c640());
    buf.size += count;
    Clear_0028c640(v, E_0028c640());
    Swap_0028c640(v->capacity, buf.capacity);
    Swap_0028c640(v->data, buf.data);
    Swap_0028c640(v->size, buf.size);
}
