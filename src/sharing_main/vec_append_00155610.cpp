/* HSTMATCH module=hstp_trans_main.prx start=0x00155610 end=0x001557d4 symbol=FUN_00155610 lang=c++ */
/* Clone of src/eboot/vec_append_000b5088.cpp (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
struct E_00155610 {};
struct T_00155610 { int w[20]; };
template <class T> inline const T &Max_00155610(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00155610(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_00155610 { T_00155610 *data; int size; unsigned capacity; };
class D_00156244 {
public:
    T_00155610 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_00156244(unsigned *a, E_00155610) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_00156244();
};
extern "C" void FUN_00156af0(D_00156244 *buf, unsigned n, E_00155610 f);
extern "C" void FUN_0015587c(D_00156244 *buf, int n, const T_00155610 *x, E_00155610 f);
extern "C" void FUN_001557d4(D_00156244 *buf, T_00155610 *first, T_00155610 *last, E_00155610 f);
inline void Reserve2_00155610(D_00156244 *b, unsigned n, E_00155610 f) { FUN_00156af0(b, n, f); }
inline void Reserve_00155610(D_00156244 *b, unsigned n) { Reserve2_00155610(b, n, E_00155610()); }
inline void FillW2_00155610(D_00156244 *b, int n, const T_00155610 *x) { FUN_0015587c(b, n, x, E_00155610()); }
inline void FillW_00155610(D_00156244 *b, int n, const T_00155610 *x) { FillW2_00155610(b, n, x); }
inline void MoveW2_00155610(D_00156244 *b, T_00155610 *first, T_00155610 *last) { FUN_001557d4(b, first, last, E_00155610()); }
inline void MoveW_00155610(D_00156244 *b, T_00155610 *first, T_00155610 *last) { MoveW2_00155610(b, first, last); }
static inline unsigned Grow_00155610(Vec_00155610 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3333333 - cap < need)
        FUN_000043b4();
    if (cap < 0x1111111)
        return cap + Max_00155610((cap + 1) * 3 / 5, need);
    if (cap < 0x2222222)
        return cap + Max_00155610((cap + 1) / 2, need);
    return 0x3333333;
}
extern "C" void FUN_00155610(Vec_00155610 *v, int n, const T_00155610 *value)
{
    D_00156244 buf(&v->capacity, E_00155610());
    unsigned need = v->size + n - v->capacity;
    Reserve_00155610(&buf, Grow_00155610(v, need));
    buf.start = v->size;
    FillW_00155610(&buf, n, value);
    MoveW_00155610(&buf, v->data, v->data + v->size);
    Swap_00155610(v->capacity, buf.capacity);
    Swap_00155610(v->data, buf.data);
    Swap_00155610(v->size, buf.size);
}
