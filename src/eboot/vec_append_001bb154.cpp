/* HSTMATCH module=EBOOT.BIN start=0x001bb154 end=0x001bb384 symbol=FUN_001bb154 lang=c++ */
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
struct E_001bb154 {};
template <class T> inline const T &Max_001bb154(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001bb154(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_001bb154(int *const &a, int *const &b) { return b - a; }
inline void FillN_001bb154(int *p, int n, const int &x, E_001bb154) { for (; n != 0; --n) *p++ = x; }
inline void Move_001bb154(int *dst, int *src, unsigned bytes, E_001bb154) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_001bb154 { int *data; int size; unsigned capacity; };
inline void Clear_001bb154(Vec_001bb154 *v, E_001bb154) { v->size = 0; }
class D_001bb4ec {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_001bb4ec(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_001bb4ec();
};
extern "C" void FUN_001bb55c(D_001bb4ec *buf, unsigned n, E_001bb154 f);
inline void Reserve2_001bb154(D_001bb4ec *b, unsigned n, E_001bb154 f) { FUN_001bb55c(b, n, f); }
inline void Reserve_001bb154(D_001bb4ec *b, unsigned n) { Reserve2_001bb154(b, n, E_001bb154()); }
static inline unsigned Grow_001bb154(Vec_001bb154 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_001bb154((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_001bb154((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_001bb154(Vec_001bb154 *v, int n, const int *value)
{
    D_001bb4ec buf(&v->capacity);
    unsigned need = v->size + n - v->capacity;
    Reserve_001bb154(&buf, Grow_001bb154(v, need));
    buf.start = v->size;
    FillN_001bb154(buf.data + buf.start + buf.size, n, *value, E_001bb154());
    buf.size += n;
    int *old = v->data;
    int count = Distance_001bb154(old, old + v->size);
    buf.start -= count;
    Move_001bb154(buf.data + buf.start, old, count * 4, E_001bb154());
    buf.size += count;
    Clear_001bb154(v, E_001bb154());
    Swap_001bb154(v->capacity, buf.capacity);
    Swap_001bb154(v->data, buf.data);
    Swap_001bb154(v->size, buf.size);
}
