/* HSTMATCH module=EBOOT.BIN start=0x00116424 end=0x00116688 symbol=FUN_00116424 lang=c++ */
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
struct E_00116424 {};
struct T_00116424 { float x, y, z; };
template <class T> inline const T &Max_00116424(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00116424(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_00116424 { T_00116424 *data; int size; unsigned capacity; };
class D_00116c24 {
public:
    T_00116424 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_00116c24(unsigned *a, E_00116424) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
extern "C" void FUN_00116c24(D_00116c24 *buf, int flags);
extern "C" void FUN_00116d74(D_00116c24 *buf, unsigned n, E_00116424 f);
inline void Reserve2_00116424(D_00116c24 *b, unsigned n, E_00116424 f) { FUN_00116d74(b, n, f); }
inline void Reserve_00116424(D_00116c24 *b, unsigned n) { Reserve2_00116424(b, n, E_00116424()); }
inline void Fill_00116424(D_00116c24 *b, int n, const T_00116424 &x, E_00116424)
{
    T_00116424 *p = b->data + b->start + b->size;
    for (; n != 0; --n, ++p) {
        new (p) T_00116424(x);
        ++b->size;
    }
}
inline void Move_00116424(D_00116c24 *b, T_00116424 *first, T_00116424 *last, E_00116424)
{
    T_00116424 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        new (p) T_00116424(*last);
        --b->start;
        ++b->size;
    }
}
static inline unsigned Grow_00116424(Vec_00116424 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x15555555 - cap < need)
        FUN_000043b4();
    if (cap < 0x071c71c7)
        return cap + Max_00116424((cap + 1) * 3 / 5, need);
    if (cap < 0x0e38e38e)
        return cap + Max_00116424((cap + 1) / 2, need);
    return 0x15555555;
}
extern "C" void FUN_00116424(Vec_00116424 *v, int n, const T_00116424 *value)
{
    D_00116c24 buf(&v->capacity, E_00116424());
    unsigned need = v->size + n - v->capacity;
    Reserve_00116424(&buf, Grow_00116424(v, need));
    buf.start = v->size;
    Fill_00116424(&buf, n, *value, E_00116424());
    Move_00116424(&buf, v->data, v->data + v->size, E_00116424());
    Swap_00116424(v->capacity, buf.capacity);
    Swap_00116424(v->data, buf.data);
    Swap_00116424(v->size, buf.size);
    FUN_00116c24(&buf, -1);
}
