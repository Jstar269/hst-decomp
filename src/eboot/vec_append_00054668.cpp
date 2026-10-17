/* HSTMATCH module=EBOOT.BIN start=0x00054668 end=0x00054898 symbol=FUN_00054668 lang=c++ */
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
struct E_00054668 {};
template <class T> inline const T &Max_00054668(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00054668(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_00054668(int *const &a, int *const &b) { return b - a; }
inline void FillN_00054668(int *p, int n, const int &x, E_00054668) { for (; n != 0; --n) *p++ = x; }
inline void Move_00054668(int *dst, int *src, unsigned bytes, E_00054668) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_00054668 { int *data; int size; unsigned capacity; };
inline void Clear_00054668(Vec_00054668 *v, E_00054668) { v->size = 0; }
class D_00054cbc {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_00054cbc(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_00054cbc();
};
extern "C" void FUN_00054e38(D_00054cbc *buf, unsigned n, E_00054668 f);
inline void Reserve2_00054668(D_00054cbc *b, unsigned n, E_00054668 f) { FUN_00054e38(b, n, f); }
inline void Reserve_00054668(D_00054cbc *b, unsigned n) { Reserve2_00054668(b, n, E_00054668()); }
static inline unsigned Grow_00054668(Vec_00054668 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_00054668((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_00054668((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_00054668(Vec_00054668 *v, int n, const int *value)
{
    D_00054cbc buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_00054668(&buf, Grow_00054668(v, need));
    buf.start = v->size;
    FillN_00054668(buf.data + buf.start + buf.size, n, *value, E_00054668());
    buf.size += n;
    int *old = v->data;
    int count = Distance_00054668(old, old + v->size);
    buf.start -= count;
    Move_00054668(buf.data + buf.start, old, count * 4, E_00054668());
    buf.size += count;
    Clear_00054668(v, E_00054668());
    Swap_00054668(v->capacity, buf.capacity);
    Swap_00054668(v->data, buf.data);
    Swap_00054668(v->size, buf.size);
}
