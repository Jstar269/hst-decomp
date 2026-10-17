/* HSTMATCH module=EBOOT.BIN start=0x001486f8 end=0x001488bc symbol=FUN_001486f8 lang=c++ */
/* Clone of src/eboot/vec_append_000b5088.cpp (hstclone.py tag c27): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
struct E_001486f8 {};
struct T_001486f8 { int w[20]; };
template <class T> inline const T &Max_001486f8(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_001486f8(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_001486f8 { T_001486f8 *data; int size; unsigned capacity; };
class D_0014aba0 {
public:
    T_001486f8 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0014aba0(unsigned *a, E_001486f8) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_0014aba0();
};
extern "C" void FUN_0014b4a8(D_0014aba0 *buf, unsigned n, E_001486f8 f);
extern "C" void FUN_00148964(D_0014aba0 *buf, int n, const T_001486f8 *x, E_001486f8 f);
extern "C" void FUN_001488bc(D_0014aba0 *buf, T_001486f8 *first, T_001486f8 *last, E_001486f8 f);
inline void Reserve2_001486f8(D_0014aba0 *b, unsigned n, E_001486f8 f) { FUN_0014b4a8(b, n, f); }
inline void Reserve_001486f8(D_0014aba0 *b, unsigned n) { Reserve2_001486f8(b, n, E_001486f8()); }
inline void FillW2_001486f8(D_0014aba0 *b, int n, const T_001486f8 *x) { FUN_00148964(b, n, x, E_001486f8()); }
inline void FillW_001486f8(D_0014aba0 *b, int n, const T_001486f8 *x) { FillW2_001486f8(b, n, x); }
inline void MoveW2_001486f8(D_0014aba0 *b, T_001486f8 *first, T_001486f8 *last) { FUN_001488bc(b, first, last, E_001486f8()); }
inline void MoveW_001486f8(D_0014aba0 *b, T_001486f8 *first, T_001486f8 *last) { MoveW2_001486f8(b, first, last); }
static inline unsigned Grow_001486f8(Vec_001486f8 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3333333 - cap < need)
        FUN_000043b4();
    if (cap < 0x1111111)
        return cap + Max_001486f8((cap + 1) * 3 / 5, need);
    if (cap < 0x2222222)
        return cap + Max_001486f8((cap + 1) / 2, need);
    return 0x3333333;
}
extern "C" void FUN_001486f8(Vec_001486f8 *v, int n, const T_001486f8 *value)
{
    D_0014aba0 buf(&v->capacity, E_001486f8());
    unsigned need = v->size + n - v->capacity;
    Reserve_001486f8(&buf, Grow_001486f8(v, need));
    buf.start = v->size;
    FillW_001486f8(&buf, n, value);
    MoveW_001486f8(&buf, v->data, v->data + v->size);
    Swap_001486f8(v->capacity, buf.capacity);
    Swap_001486f8(v->data, buf.data);
    Swap_001486f8(v->size, buf.size);
}
