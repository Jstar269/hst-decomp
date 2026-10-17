/* HSTMATCH module=hstp_trans_main.prx start=0x000b8378 end=0x000b853c symbol=FUN_000b8378 lang=c++ */
/* Clone of src/eboot/vec_append_000b5088.cpp (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
struct E_000b8378 {};
struct T_000b8378 { int w[20]; };
template <class T> inline const T &Max_000b8378(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_000b8378(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_000b8378 { T_000b8378 *data; int size; unsigned capacity; };
class D_000b8770 {
public:
    T_000b8378 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_000b8770(unsigned *a, E_000b8378) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_000b8770();
};
extern "C" void FUN_000b9680(D_000b8770 *buf, unsigned n, E_000b8378 f);
extern "C" void FUN_000b85e4(D_000b8770 *buf, int n, const T_000b8378 *x, E_000b8378 f);
extern "C" void FUN_000b853c(D_000b8770 *buf, T_000b8378 *first, T_000b8378 *last, E_000b8378 f);
inline void Reserve2_000b8378(D_000b8770 *b, unsigned n, E_000b8378 f) { FUN_000b9680(b, n, f); }
inline void Reserve_000b8378(D_000b8770 *b, unsigned n) { Reserve2_000b8378(b, n, E_000b8378()); }
inline void FillW2_000b8378(D_000b8770 *b, int n, const T_000b8378 *x) { FUN_000b85e4(b, n, x, E_000b8378()); }
inline void FillW_000b8378(D_000b8770 *b, int n, const T_000b8378 *x) { FillW2_000b8378(b, n, x); }
inline void MoveW2_000b8378(D_000b8770 *b, T_000b8378 *first, T_000b8378 *last) { FUN_000b853c(b, first, last, E_000b8378()); }
inline void MoveW_000b8378(D_000b8770 *b, T_000b8378 *first, T_000b8378 *last) { MoveW2_000b8378(b, first, last); }
static inline unsigned Grow_000b8378(Vec_000b8378 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3333333 - cap < need)
        FUN_000043b4();
    if (cap < 0x1111111)
        return cap + Max_000b8378((cap + 1) * 3 / 5, need);
    if (cap < 0x2222222)
        return cap + Max_000b8378((cap + 1) / 2, need);
    return 0x3333333;
}
extern "C" void FUN_000b8378(Vec_000b8378 *v, int n, const T_000b8378 *value)
{
    D_000b8770 buf(&v->capacity, E_000b8378());
    unsigned need = v->size + n - v->capacity;
    Reserve_000b8378(&buf, Grow_000b8378(v, need));
    buf.start = v->size;
    FillW_000b8378(&buf, n, value);
    MoveW_000b8378(&buf, v->data, v->data + v->size);
    Swap_000b8378(v->capacity, buf.capacity);
    Swap_000b8378(v->data, buf.data);
    Swap_000b8378(v->size, buf.size);
}
