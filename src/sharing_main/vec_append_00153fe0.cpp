/* HSTMATCH module=hstp_trans_main.prx start=0x00153fe0 end=0x001541a4 symbol=FUN_00153fe0 lang=c++ */
/* Clone of src/eboot/vec_append_000b5088.cpp (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
struct E_00153fe0 {};
struct T_00153fe0 { int w[20]; };
template <class T> inline const T &Max_00153fe0(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00153fe0(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_00153fe0 { T_00153fe0 *data; int size; unsigned capacity; };
class D_00156488 {
public:
    T_00153fe0 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_00156488(unsigned *a, E_00153fe0) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_00156488();
};
extern "C" void FUN_00156d90(D_00156488 *buf, unsigned n, E_00153fe0 f);
extern "C" void FUN_0015424c(D_00156488 *buf, int n, const T_00153fe0 *x, E_00153fe0 f);
extern "C" void FUN_001541a4(D_00156488 *buf, T_00153fe0 *first, T_00153fe0 *last, E_00153fe0 f);
inline void Reserve2_00153fe0(D_00156488 *b, unsigned n, E_00153fe0 f) { FUN_00156d90(b, n, f); }
inline void Reserve_00153fe0(D_00156488 *b, unsigned n) { Reserve2_00153fe0(b, n, E_00153fe0()); }
inline void FillW2_00153fe0(D_00156488 *b, int n, const T_00153fe0 *x) { FUN_0015424c(b, n, x, E_00153fe0()); }
inline void FillW_00153fe0(D_00156488 *b, int n, const T_00153fe0 *x) { FillW2_00153fe0(b, n, x); }
inline void MoveW2_00153fe0(D_00156488 *b, T_00153fe0 *first, T_00153fe0 *last) { FUN_001541a4(b, first, last, E_00153fe0()); }
inline void MoveW_00153fe0(D_00156488 *b, T_00153fe0 *first, T_00153fe0 *last) { MoveW2_00153fe0(b, first, last); }
static inline unsigned Grow_00153fe0(Vec_00153fe0 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3333333 - cap < need)
        FUN_000043b4();
    if (cap < 0x1111111)
        return cap + Max_00153fe0((cap + 1) * 3 / 5, need);
    if (cap < 0x2222222)
        return cap + Max_00153fe0((cap + 1) / 2, need);
    return 0x3333333;
}
extern "C" void FUN_00153fe0(Vec_00153fe0 *v, int n, const T_00153fe0 *value)
{
    D_00156488 buf(&v->capacity, E_00153fe0());
    unsigned need = v->size + n - v->capacity;
    Reserve_00153fe0(&buf, Grow_00153fe0(v, need));
    buf.start = v->size;
    FillW_00153fe0(&buf, n, value);
    MoveW_00153fe0(&buf, v->data, v->data + v->size);
    Swap_00153fe0(v->capacity, buf.capacity);
    Swap_00153fe0(v->data, buf.data);
    Swap_00153fe0(v->size, buf.size);
}
