/* HSTMATCH module=EBOOT.BIN start=0x002374f4 end=0x002376c0 symbol=FUN_002374f4 lang=c++ */
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
void FUN_00238b5c(Buf *buf, unsigned n, char f);
void FUN_00237770(Buf *buf, unsigned n, const Elem &x, False);
void FUN_002376c0(Buf *buf, Elem *first, Elem *last, False);
void FUN_002387dc(Buf *buf, int flag);
}
class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_00238b5c(this, n, f.v); }
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
/* Appends n copies of x: grows through a split buffer sized by the family's grow policy, fills the copies, moves the old elements in and swaps buffers. */
extern "C" void FUN_002374f4(Vec *vec, unsigned n, const Elem &x)
{
    Buf buf(&vec->capacity);
    buf.reserve(Grow(vec, vec->size + n - vec->capacity));
    buf.start = vec->size;
    FUN_00237770(&buf, n, x, False());
    FUN_002376c0(&buf, vec->data, vec->data + vec->size, False());
    Swap(vec->capacity, buf.capacity);
    Swap(vec->data, buf.data);
    Swap(vec->size, buf.size);
    FUN_002387dc(&buf, -1);
}
