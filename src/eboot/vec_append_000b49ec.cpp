/* HSTMATCH module=EBOOT.BIN start=0x000b49ec end=0x000b4c1c symbol=FUN_000b49ec lang=c++ */
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
/* Empty tag type (int2type-style dispatch tag / empty allocator). Every by-value tag temporary reserves a
   phantom 4-byte frame slot: the buffer constructor, reserve, fill and move-front tags give the 16 bytes
   between the buffer and `need`; Reserve2's forwarded copy is a hidden slot below the max temporaries. */
struct E_000b49ec {};
template <class T> inline const T &Max_000b49ec(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000b49ec(T &a, T &b) { T t = a; a = b; b = t; }
inline int Distance_000b49ec(int *const &a, int *const &b) { return b - a; }
inline void FillN_000b49ec(int *p, int n, const int &x, E_000b49ec) { for (; n != 0; --n) *p++ = x; }
inline void Move_000b49ec(int *dst, int *src, unsigned bytes, E_000b49ec) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }
struct Vec_000b49ec { int *data; int size; unsigned capacity; };
class D_000b6320 {
public:
    int *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000b6320(unsigned *a, E_000b49ec) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000b6320();
};
extern "C" void FUN_000b64e0(D_000b6320 *buf, unsigned n, E_000b49ec f);
inline void Reserve2_000b49ec(D_000b6320 *b, unsigned n, E_000b49ec f) { FUN_000b64e0(b, n, f); }
inline void Reserve_000b49ec(D_000b6320 *b, unsigned n) { Reserve2_000b49ec(b, n, E_000b49ec()); }
/* `need` must be a by-value parameter here (its copy is the address-taken slot at sp+56). */
static inline unsigned Grow_000b49ec(Vec_000b49ec *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3fffffff - cap < need)
        FUN_000043b4();
    if (cap < 0x15555555)
        return cap + Max_000b49ec((cap + 1) * 3 / 5, need);
    if (cap < 0x2aaaaaaa)
        return cap + Max_000b49ec((cap + 1) / 2, need);
    return 0x3fffffff;
}
extern "C" void FUN_000b49ec(Vec_000b49ec *v, int n, const int *value)
{
    D_000b6320 buf(&v->capacity, E_000b49ec());
    unsigned need = v->size + n - v->capacity;
    Reserve_000b49ec(&buf, Grow_000b49ec(v, need));
    buf.start = v->size;
    FillN_000b49ec(buf.data + buf.start + buf.size, n, *value, E_000b49ec());
    buf.size += n;
    int *old = v->data;
    int count = Distance_000b49ec(old, old + v->size);
    buf.start -= count;
    Move_000b49ec(buf.data + buf.start, old, count * 4, E_000b49ec());
    buf.size += count;
    v->size = 0;
    Swap_000b49ec(v->capacity, buf.capacity);
    Swap_000b49ec(v->data, buf.data);
    Swap_000b49ec(v->size, buf.size);
}
