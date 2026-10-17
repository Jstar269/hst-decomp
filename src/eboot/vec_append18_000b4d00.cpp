/* HSTMATCH module=EBOOT.BIN start=0x000b4d00 end=0x000b4f94 symbol=FUN_000b4d00 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
inline void *operator new(unsigned, void *p) { return p; }
struct E_000b4d00 {};
struct T_000b4d00 { char c[18]; };
template <class T> inline const T &Max_000b4d00(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000b4d00(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_000b4d00 { T_000b4d00 *data; int size; unsigned capacity; };
class D_000b54ec {
public:
    T_000b4d00 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000b54ec(unsigned *a, E_000b4d00) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000b54ec();
};
extern "C" void FUN_000b6438(D_000b54ec *buf, unsigned n, E_000b4d00 f);
inline void Reserve2_000b4d00(D_000b54ec *b, unsigned n, E_000b4d00 f) { FUN_000b6438(b, n, f); }
inline void Reserve_000b4d00(D_000b54ec *b, unsigned n) { Reserve2_000b4d00(b, n, E_000b4d00()); }
inline void Fill_000b4d00(D_000b54ec *b, int n, const T_000b4d00 &x, E_000b4d00)
{
    T_000b4d00 *p = b->data + b->start + b->size;
    for (; n != 0; --n, ++p) {
        new (p) T_000b4d00(x);
        ++b->size;
    }
}
inline void Move_000b4d00(D_000b54ec *b, T_000b4d00 *first, T_000b4d00 *last, E_000b4d00)
{
    T_000b4d00 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        new (p) T_000b4d00(*last);
        --b->start;
        ++b->size;
    }
}
static inline unsigned Grow_000b4d00(Vec_000b4d00 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x0e38e38e - cap < need)
        FUN_000043b4();
    if (cap < 0x04bda12f)
        return cap + Max_000b4d00((cap + 1) * 3 / 5, need);
    if (cap < 0x097b425e)
        return cap + Max_000b4d00((cap + 1) / 2, need);
    return 0x0e38e38e;
}
extern "C" void FUN_000b4d00(Vec_000b4d00 *v, int n, const T_000b4d00 *value)
{
    D_000b54ec buf(&v->capacity, E_000b4d00());
    unsigned need = v->size + n - v->capacity;
    Reserve_000b4d00(&buf, Grow_000b4d00(v, need));
    buf.start = v->size;
    Fill_000b4d00(&buf, n, *value, E_000b4d00());
    Move_000b4d00(&buf, v->data, v->data + v->size, E_000b4d00());
    Swap_000b4d00(v->capacity, buf.capacity);
    Swap_000b4d00(v->data, buf.data);
    Swap_000b4d00(v->size, buf.size);
}
