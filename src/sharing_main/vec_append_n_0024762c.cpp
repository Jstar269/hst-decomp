/* HSTMATCH module=hstp_trans_main.prx start=0x0024762c end=0x002477f8 symbol=FUN_0024762c lang=c++ */
/* Clone of src/eboot/vec_append_n_002374f4.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_append_n_00215c9c.cpp with the 560-byte element, growth bounds 0x270270/0x4e04e0 = max_size/3, 2*max_size/3 for max_size 0x750750, and out-of-line fill 0x237770 / move 0x2376c0 / buffer dtor 0x2387dc); exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag { char v; Flag(char x) : v(x) {} };
struct False {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem { int w[140]; };
struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
};
struct Vec { Elem *data; unsigned size; unsigned capacity; };
class Buf;
extern "C" {
void FUN_00248c94(Buf *buf, unsigned n, char f);
void FUN_002478a8(Buf *buf, unsigned n, const Elem &x, False);
void FUN_002477f8(Buf *buf, Elem *first, Elem *last, False);
void FUN_00248914(Buf *buf, int flag);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_00248c94(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag(0)); }
    void reserve(unsigned n) { reserve_flagged(n); }
};
inline unsigned MaxSize() { return Alloc().max_size(); }
static inline unsigned Grow(Vec *v, unsigned need)
{
    const unsigned ms = MaxSize();
    unsigned cap = v->capacity;
    if (ms - cap < need)
        FUN_000043b4();
    if (cap < ms / 3)
        return cap + Max((cap + 1) * 3 / 5, need);
    if (cap < ms / 3 * 2)
        return cap + Max((cap + 1) / 2, need);
    return ms;
}
extern "C" void FUN_0024762c(Vec *v, unsigned n, const Elem &x)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_002478a8(&buf, n, x, False());
    FUN_002477f8(&buf, v->data, v->data + v->size, False());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_00248914(&buf, -1);
}
