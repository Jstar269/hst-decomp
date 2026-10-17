/* HSTMATCH module=hstp_trans_main.prx start=0x0014a304 end=0x0014a568 symbol=FUN_0014a304 lang=c++ */
/* Clone of src/eboot/vec_append12_00116424.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
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
struct E_0014a304 {};
struct T_0014a304 { float x, y, z; };
template <class T> inline const T &Max_0014a304(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_0014a304(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_0014a304 { T_0014a304 *data; int size; unsigned capacity; };
class D_0014a64c {
public:
    T_0014a304 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0014a64c(unsigned *a, E_0014a304) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
extern "C" void FUN_0014a64c(D_0014a64c *buf, int flags);
extern "C" void FUN_0014ab2c(D_0014a64c *buf, unsigned n, E_0014a304 f);
inline void Reserve2_0014a304(D_0014a64c *b, unsigned n, E_0014a304 f) { FUN_0014ab2c(b, n, f); }
inline void Reserve_0014a304(D_0014a64c *b, unsigned n) { Reserve2_0014a304(b, n, E_0014a304()); }
inline void Fill_0014a304(D_0014a64c *b, int n, const T_0014a304 &x, E_0014a304)
{
    T_0014a304 *p = b->data + b->start + b->size;
    for (; n != 0; --n, ++p) {
        new (p) T_0014a304(x);
        ++b->size;
    }
}
inline void Move_0014a304(D_0014a64c *b, T_0014a304 *first, T_0014a304 *last, E_0014a304)
{
    T_0014a304 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        new (p) T_0014a304(*last);
        --b->start;
        ++b->size;
    }
}
static inline unsigned Grow_0014a304(Vec_0014a304 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x15555555 - cap < need)
        FUN_000043b4();
    if (cap < 0x071c71c7)
        return cap + Max_0014a304((cap + 1) * 3 / 5, need);
    if (cap < 0x0e38e38e)
        return cap + Max_0014a304((cap + 1) / 2, need);
    return 0x15555555;
}
extern "C" void FUN_0014a304(Vec_0014a304 *v, int n, const T_0014a304 *value)
{
    D_0014a64c buf(&v->capacity, E_0014a304());
    unsigned need = v->size + n - v->capacity;
    Reserve_0014a304(&buf, Grow_0014a304(v, need));
    buf.start = v->size;
    Fill_0014a304(&buf, n, *value, E_0014a304());
    Move_0014a304(&buf, v->data, v->data + v->size, E_0014a304());
    Swap_0014a304(v->capacity, buf.capacity);
    Swap_0014a304(v->data, buf.data);
    Swap_0014a304(v->size, buf.size);
    FUN_0014a64c(&buf, -1);
}
