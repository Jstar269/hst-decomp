/* HSTMATCH module=hstp_trans_main.prx start=0x00247e54 end=0x00248018 symbol=FUN_00247e54 lang=c++ */
/* Clone of src/eboot/vec_append_n_00237d1c.cpp (hstclone.py tag s10170158a3r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_append_n_002374f4.cpp / vec_append_n_00215c9c.cpp with the 72-byte element, max_size 0x38e38e3 and growth bounds 0x12f684b / 0x25ed096, out-of-line fill 0x237ff4 / move 0x237ee0 / buffer dtor 0x238704); exact match verified; names and types await human review. */
#pragma inline_depth(8)
extern "C" void FUN_000043b4(void);
struct Flag { char v; Flag(char x) : v(x) {} };
struct False {};
template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Elem { int w[18]; };
struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
};
struct Vec { Elem *data; unsigned size; unsigned capacity; };
class Buf;
extern "C" {
void FUN_00248b44(Buf *buf, unsigned n, char f);
void FUN_0024812c(Buf *buf, unsigned n, const Elem &x, False);
void FUN_00248018(Buf *buf, Elem *first, Elem *last, False);
void FUN_0024883c(Buf *buf, int flag);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_00248b44(this, n, f.v); }
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
extern "C" void FUN_00247e54(Vec *v, unsigned n, const Elem &x)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    FUN_0024812c(&buf, n, x, False());
    FUN_00248018(&buf, v->data, v->data + v->size, False());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_0024883c(&buf, -1);
}
