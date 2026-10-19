/* HSTMATCH module=EBOOT.BIN start=0x00165f20 end=0x00166150 symbol=vec_append_n_00165f20 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Container append of n copies of a 2-byte element through a local split buffer with inlined fill loop and memmove. */
#pragma inline_depth(8)

extern "C" {
void FUN_000043b4(void);
void *FUN_00011090(void *dst, const void *src, unsigned n);
void *FUN_000114c0(void *p, int c, unsigned n);
}

struct Flag { char v; Flag(char x) : v(x) {} };
struct True {};

struct Alloc {
    unsigned max_size() const { return 0xffffffffu / sizeof(short); }
};

template <class T> inline const T &Max(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }

inline int Distance(short *const &a, short *const &b) { return b - a; }
inline void FillN(short *p, int n, const short &x, True) { Alloc(); for (; n != 0; --n) *p++ = x; }
inline void Move(short *dst, short *src, unsigned bytes, True) { FUN_00011090(dst, src, bytes); FUN_000114c0(src, 0, bytes); }

struct Vec { short *data; int size; unsigned capacity; };
inline void Clear(Vec *v, True) { v->size = 0; }

class Buf;
extern "C" {
void FUN_00166874(Buf *buf, unsigned n, char f);
void FUN_0016675c(Buf *buf, int flag);
}

class Buf {
public:
    short *data;
    int size;
    unsigned capacity;
    unsigned *alloc;
    int start;
    Buf(unsigned *a) : data(0), size(0), capacity(0), alloc(a), start(0) {}
    void reserve(unsigned n, Flag f, True) { FUN_00166874(this, n, f.v); }
    void reserve_flagged(unsigned n) { reserve(n, Flag(0), True()); }
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

extern "C" void vec_append_n_00165f20(Vec *v, int n, const short *value)
{
    Buf buf(&v->capacity);
    buf.reserve(Grow(v, v->size + n - v->capacity));
    buf.start = v->size;
    FillN(buf.data + buf.start + buf.size, n, *value, True());
    buf.size += n;
    short *old = v->data;
    int count = Distance(old, old + v->size);
    buf.start -= count;
    Move(buf.data + buf.start, old, count * sizeof(short), True());
    buf.size += count;
    Clear(v, True());
    Swap(v->capacity, buf.capacity);
    Swap(v->data, buf.data);
    Swap(v->size, buf.size);
    FUN_0016675c(&buf, -1);
}
