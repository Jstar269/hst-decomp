/* HSTMATCH module=EBOOT.BIN start=0x00149d28 end=0x00149eec symbol=FUN_00149d28 lang=c++ */
/* Clone of src/eboot/vec_append_000b5088.cpp (hstclone.py tag c27): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" {
void FUN_000043b4(void);
}
struct E_00149d28 {};
struct T_00149d28 { int w[20]; };
template <class T> inline const T &Max_00149d28(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap_00149d28(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec_00149d28 { T_00149d28 *data; int size; unsigned capacity; };
class D_0014a95c {
public:
    T_00149d28 *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    D_0014a95c(unsigned *a, E_00149d28) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    ~D_0014a95c();
};
extern "C" void FUN_0014b208(D_0014a95c *buf, unsigned n, E_00149d28 f);
extern "C" void FUN_00149f94(D_0014a95c *buf, int n, const T_00149d28 *x, E_00149d28 f);
extern "C" void FUN_00149eec(D_0014a95c *buf, T_00149d28 *first, T_00149d28 *last, E_00149d28 f);
inline void Reserve2_00149d28(D_0014a95c *b, unsigned n, E_00149d28 f) { FUN_0014b208(b, n, f); }
inline void Reserve_00149d28(D_0014a95c *b, unsigned n) { Reserve2_00149d28(b, n, E_00149d28()); }
inline void FillW2_00149d28(D_0014a95c *b, int n, const T_00149d28 *x) { FUN_00149f94(b, n, x, E_00149d28()); }
inline void FillW_00149d28(D_0014a95c *b, int n, const T_00149d28 *x) { FillW2_00149d28(b, n, x); }
inline void MoveW2_00149d28(D_0014a95c *b, T_00149d28 *first, T_00149d28 *last) { FUN_00149eec(b, first, last, E_00149d28()); }
inline void MoveW_00149d28(D_0014a95c *b, T_00149d28 *first, T_00149d28 *last) { MoveW2_00149d28(b, first, last); }
static inline unsigned Grow_00149d28(Vec_00149d28 *v, unsigned need)
{
    unsigned cap = v->capacity;
    if (0x3333333 - cap < need)
        FUN_000043b4();
    if (cap < 0x1111111)
        return cap + Max_00149d28((cap + 1) * 3 / 5, need);
    if (cap < 0x2222222)
        return cap + Max_00149d28((cap + 1) / 2, need);
    return 0x3333333;
}
extern "C" void FUN_00149d28(Vec_00149d28 *v, int n, const T_00149d28 *value)
{
    D_0014a95c buf(&v->capacity, E_00149d28());
    unsigned need = v->size + n - v->capacity;
    Reserve_00149d28(&buf, Grow_00149d28(v, need));
    buf.start = v->size;
    FillW_00149d28(&buf, n, value);
    MoveW_00149d28(&buf, v->data, v->data + v->size);
    Swap_00149d28(v->capacity, buf.capacity);
    Swap_00149d28(v->data, buf.data);
    Swap_00149d28(v->size, buf.size);
}
