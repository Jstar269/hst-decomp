/* HSTMATCH module=EBOOT.BIN start=0x0013ecb8 end=0x0013ef1c symbol=FUN_0013ecb8 lang=c++ */
/* Clone of src/eboot/vec_append12_00116424.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Container append of n copies of a 12-byte float triple through a local split buffer (adapted from
   src/eboot/vec_append18_000b4d00.cpp): grow, reserve, placement-copy fill, move the old elements in
   front, swap buffers. The buffer destructor (0x116c24) is called explicitly because its mangled name is
   not in the symbol map; the generated code is the same. Names provisional. */
extern "C" {
void FUN_000043b4(void);
}
inline void *operator new(unsigned, void *p) { return p; }
struct E_0013ecb8 {};
struct T_0013ecb8 { float x, y, z; };
template <class T> inline const T &Max_0013ecb8(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0013ecb8(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_0013ecb8 { T_0013ecb8 *data; int size; unsigned capacity; };
class D_0013f000 {
public:
    T_0013ecb8 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0013f000(unsigned *a, E_0013ecb8) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
extern "C" void FUN_0013f000(D_0013f000 *buf, int flags);
extern "C" void FUN_0013f4e0(D_0013f000 *buf, unsigned n, E_0013ecb8 f);
inline void Reserve2_0013ecb8(D_0013f000 *b, unsigned n, E_0013ecb8 f) { FUN_0013f4e0(b, n, f); }
inline void Reserve_0013ecb8(D_0013f000 *b, unsigned n) { Reserve2_0013ecb8(b, n, E_0013ecb8()); }
inline void Fill_0013ecb8(D_0013f000 *b, int n, const T_0013ecb8 &x, E_0013ecb8)
{
    T_0013ecb8 *p = b->data + b->start + b->size;
    for (; n != 0; --n, ++p) {
        new (p) T_0013ecb8(x);
        ++b->size;
    }
}
inline void Move_0013ecb8(D_0013f000 *b, T_0013ecb8 *first, T_0013ecb8 *last, E_0013ecb8)
{
    T_0013ecb8 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        new (p) T_0013ecb8(*last);
        --b->start;
        ++b->size;
    }
}
static inline unsigned Grow_0013ecb8(Vec_0013ecb8 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x15555555 - cap < need)
        FUN_000043b4();
    if (cap < 0x071c71c7)
        return cap + Max_0013ecb8((cap + 1) * 3 / 5, need);
    if (cap < 0x0e38e38e)
        return cap + Max_0013ecb8((cap + 1) / 2, need);
    return 0x15555555;
}
extern "C" void FUN_0013ecb8(Vec_0013ecb8 *v, int n, const T_0013ecb8 *value)
{
    D_0013f000 buf(&v->capacity, E_0013ecb8());
    unsigned need = v->size + n - v->capacity;
    Reserve_0013ecb8(&buf, Grow_0013ecb8(v, need));
    buf.start = v->size;
    Fill_0013ecb8(&buf, n, *value, E_0013ecb8());
    Move_0013ecb8(&buf, v->data, v->data + v->size, E_0013ecb8());
    Swap_0013ecb8(v->capacity, buf.capacity);
    Swap_0013ecb8(v->data, buf.data);
    Swap_0013ecb8(v->size, buf.size);
    FUN_0013f000(&buf, -1);
}
