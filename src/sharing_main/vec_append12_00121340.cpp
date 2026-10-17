/* HSTMATCH module=hstp_trans_main.prx start=0x00121340 end=0x001215a4 symbol=FUN_00121340 lang=c++ */
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
struct E_00121340 {};
struct T_00121340 { float x, y, z; };
template <class T> inline const T &Max_00121340(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00121340(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_00121340 { T_00121340 *data; int size; unsigned capacity; };
class D_00121b40 {
public:
    T_00121340 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_00121b40(unsigned *a, E_00121340) : data(0), size(0), capacity(0), alloc(a), start(0) {}
};
extern "C" void FUN_00121b40(D_00121b40 *buf, int flags);
extern "C" void FUN_00121c90(D_00121b40 *buf, unsigned n, E_00121340 f);
inline void Reserve2_00121340(D_00121b40 *b, unsigned n, E_00121340 f) { FUN_00121c90(b, n, f); }
inline void Reserve_00121340(D_00121b40 *b, unsigned n) { Reserve2_00121340(b, n, E_00121340()); }
inline void Fill_00121340(D_00121b40 *b, int n, const T_00121340 &x, E_00121340)
{
    T_00121340 *p = b->data + b->start + b->size;
    for (; n != 0; --n, ++p) {
        new (p) T_00121340(x);
        ++b->size;
    }
}
inline void Move_00121340(D_00121b40 *b, T_00121340 *first, T_00121340 *last, E_00121340)
{
    T_00121340 *p = b->data + b->start;
    while (first < last) {
        --p;
        --last;
        new (p) T_00121340(*last);
        --b->start;
        ++b->size;
    }
}
static inline unsigned Grow_00121340(Vec_00121340 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x15555555 - cap < need)
        FUN_000043b4();
    if (cap < 0x071c71c7)
        return cap + Max_00121340((cap + 1) * 3 / 5, need);
    if (cap < 0x0e38e38e)
        return cap + Max_00121340((cap + 1) / 2, need);
    return 0x15555555;
}
extern "C" void FUN_00121340(Vec_00121340 *v, int n, const T_00121340 *value)
{
    D_00121b40 buf(&v->capacity, E_00121340());
    unsigned need = v->size + n - v->capacity;
    Reserve_00121340(&buf, Grow_00121340(v, need));
    buf.start = v->size;
    Fill_00121340(&buf, n, *value, E_00121340());
    Move_00121340(&buf, v->data, v->data + v->size, E_00121340());
    Swap_00121340(v->capacity, buf.capacity);
    Swap_00121340(v->data, buf.data);
    Swap_00121340(v->size, buf.size);
    FUN_00121b40(&buf, -1);
}
