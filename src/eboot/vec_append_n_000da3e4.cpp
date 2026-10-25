/* HSTMATCH module=EBOOT.BIN start=0x000da3e4 end=0x000da648 symbol=FUN_000da3e4 lang=c++ */
/* Clone of src/sharing_main/vec_append_n_000de3a4.cpp (hstclone.py tag ag56e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#pragma inline_depth(8)

extern "C" void FUN_000043b4(void);

struct Flag { char v; Flag(char x) : v(x) {} };
struct True {};

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }

inline void *operator new(unsigned, void *p) { return p; }

struct Elem {
    short a0, a1, a2;
    Elem(const Elem &o) : a0(o.a0), a1(o.a1), a2(o.a2) {}
};

struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(Elem); }
};

struct Vec { Elem *data; unsigned size; unsigned capacity; };

class Buf;
extern "C" {
void FUN_000dada4(Buf *buf, unsigned n, char f);
void FUN_000dad14(Buf *buf, int flag);
}

class Buf {
public:
    Elem *data;
    unsigned size;
    unsigned capacity;
    unsigned *alloc;
    unsigned start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f) { FUN_000dada4(this, n, f.v); }
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

inline void FillN(Buf *buf, Elem *p, unsigned n, const Elem &x, True)
{
    Alloc();
    for (; n != 0; --n, ++p, ++buf->size)
        new (p) Elem(x);
}

inline void MoveBackward(Buf *buf, Elem *first, Elem *last, True)
{
    Alloc();
    Elem *dst = buf->data + buf->start;
    while (first < last) {
        --last;
        --dst;
        new (dst) Elem(*last);
        --buf->start;
        ++buf->size;
    }
}

extern "C" void FUN_000da3e4(Vec *v, unsigned n, const Elem &x)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    FillN(&buf, buf.data + buf.start + buf.size, n, x, True());
    Elem *old = v->data;
    MoveBackward(&buf, old, old + v->size, True());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_000dad14(&buf, -1);
}
