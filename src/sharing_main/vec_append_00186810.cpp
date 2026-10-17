/* HSTMATCH module=hstp_trans_main.prx start=0x00186810 end=0x00186a40 symbol=FUN_00186810 lang=c++ */
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
struct E_00186810 {};
template <class T> inline const T &Max_00186810(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00186810(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00186810(int *const &a, int *const &b) { return b - a; }
inline void FillN_00186810(int *p, int n, const int &x, E_00186810) { for (; n != 0; --n) *p++ = x; }
inline void Move_00186810(int *dst, int *src, unsigned bytes, E_00186810) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_00186810 { int *data; int size; unsigned capacity; };
inline void Clear_00186810(Vec_00186810 *v, E_00186810) { v->size = 0; }
class D_001871b4 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_001871b4(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_001871b4();
};
extern "C" void FUN_001874a0(D_001871b4 *buf, unsigned n, E_00186810 f);
inline void Reserve2_00186810(D_001871b4 *b, unsigned n, E_00186810 f) { FUN_001874a0(b, n, f); }
inline void Reserve_00186810(D_001871b4 *b, unsigned n) { Reserve2_00186810(b, n, E_00186810()); }
static inline unsigned Grow_00186810(Vec_00186810 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00186810((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00186810((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_00186810(Vec_00186810 *v, int n, const int *value)
{
    D_001871b4 buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_00186810(&buf, Grow_00186810(v, need));
    buf.start = v->size;
    FillN_00186810(buf.data + buf.start + buf.size, n, *value, E_00186810());
    buf.size += n;
    int *old = v->data;
    int count = Distance_00186810(old, old + v->size);
    buf.start -= count;
    Move_00186810(buf.data + buf.start, old, count * 4, E_00186810());
    buf.size += count;
    Clear_00186810(v, E_00186810());
    Swap_00186810(v->capacity, buf.capacity);
    Swap_00186810(v->data, buf.data);
    Swap_00186810(v->size, buf.size);
}
