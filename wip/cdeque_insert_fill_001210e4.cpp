/* HSTMATCH module=EBOOT.BIN start=0x001210e4 end=0x00121aa8 symbol=FUN_001210e4 lang=c++ */
/* MSL-style circular deque (cdeque) of 4-byte elements: insert(position, n, x) (fill insert; resize() at
   0x11d638 calls it with end()). If size() + n fits capacity(), open the gap on the shorter side (front:
   construct copies of x / the first min(pb, n) old elements in front of begin(), shift [begin+n, begin+pb)
   down, fill the rest; back: the mirror image with copy_backward and a backward fill); x is first copied when
   it lies inside the buffer. Otherwise grow into a temporary cdeque, copy [begin,pos) + n copies of x +
   [pos,end), swap, destroy. Iterator {ptr, beg, first, end}; names provisional. */
extern "C" {
struct Reent_001210e4 { int pad[3]; void *err; };
Reent_001210e4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002da188[]; /* "cdeque max_size error" */
extern char DAT_002c138c[]; /* "Memory allocation failure" */
extern char DAT_0033b493;
extern unsigned DAT_002c1334;
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef int T_001210e4;

template <class U> inline const U &min_001210e4(const U &a, const U &b) { return b < a ? b : a; }

template <int C> struct It_001210e4 {
    T_001210e4 *ptr;
    T_001210e4 *beg;
    T_001210e4 *first;
    T_001210e4 *end;
    It_001210e4() {}
    It_001210e4(T_001210e4 *p, T_001210e4 *b, T_001210e4 *e, T_001210e4 *f) : ptr(p), beg(b), first(f), end(e) {}
    It_001210e4(T_001210e4 *d, unsigned cap, unsigned start, unsigned i) { first = d + start; end = d + cap; beg = d; ptr = d + i; }
    It_001210e4(const It_001210e4<0> &i) : ptr(i.ptr), beg(i.beg), first(i.first), end(i.end) {}
    It_001210e4(const It_001210e4<1> &i) : ptr(i.ptr), beg(i.beg), first(i.first), end(i.end) {}
    T_001210e4 &operator*() const { return *ptr; }
    It_001210e4 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    It_001210e4 &operator--()
    {
        if (ptr == beg)
            ptr = end;
        --ptr;
        return *this;
    }
    It_001210e4 &operator+=(int n)
    {
        int cap = end - beg;
        n += ptr - beg;
        if (n < 0)
            n += cap;
        else if (n >= cap)
            n -= cap;
        ptr = beg + n;
        return *this;
    }
    It_001210e4 operator+(int n) const { return It_001210e4(*this) += n; }
    T_001210e4 &operator[](int n) const { return *(*this + n); }
    It_001210e4 &operator-=(int n) { return *this += -n; }
    It_001210e4 operator-(int n) const { return It_001210e4(*this) -= n; }
};
typedef It_001210e4<0> Iter_001210e4;
typedef It_001210e4<1> CIter_001210e4;
template <int A, int B> inline int operator-(const It_001210e4<A> &x, const It_001210e4<B> &y)
{
    T_001210e4 *f = x.first;
    int d = x.ptr - y.ptr;
    if (x.ptr >= f) {
        if (y.ptr < f)
            d -= x.end - x.beg;
    } else {
        if (y.ptr >= f)
            d += x.end - x.beg;
    }
    return d;
}
template <class I> inline int distance_001210e4(I first, I last) { return last - first; }
template <int A, int B> inline bool operator!=(const It_001210e4<A> &x, const It_001210e4<B> &y) { return x.ptr != y.ptr; }
template <int A, int B> inline bool operator<(const It_001210e4<A> &x, const It_001210e4<B> &y)
{
    if (x.ptr >= x.first) {
        if (y.ptr < x.first)
            return true;
    } else {
        if (y.ptr >= x.first)
            return false;
    }
    return x.ptr < y.ptr;
}

template <class I, class O> inline O copy_001210e4(I first, I last, O result)
{
    for (; first != last; ++first, ++result)
        *result = *first;
    return result;
}
template <class I, class O> inline O copy_backward_001210e4(I first, I last, O result)
{
    while (last != first)
        *--result = *--last;
    return result;
}

inline void Error_001210e4(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_001210e4 {
    unsigned max_size() const { return 0x3fffffff; }
    T_001210e4 *allocate(unsigned n)
    {
        T_001210e4 *p = (T_001210e4 *)FUN_00000bcc(n * sizeof(T_001210e4));
        if (p == 0)
            Error_001210e4(DAT_002c138c);
        return p;
    }
    void construct(T_001210e4 *p, const T_001210e4 &v) { new (p) T_001210e4(v); }
};
struct ForwardTag_001210e4 {};

struct Cdeque_001210e4;
extern "C" void FUN_0011d7e4(Cdeque_001210e4 *self);
struct Cdeque_001210e4 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_001210e4 *data_;
    Cdeque_001210e4() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_001210e4()
    {
        if (data_) {
            FUN_0011d7e4(this);
            FUN_00000a00(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_0033b493) {
            DAT_002c1334 = Alloc_001210e4().max_size();
            --DAT_002c1334;
            DAT_0033b493 = 1;
        }
        return DAT_002c1334;
    }
    static unsigned grow2_001210e4(unsigned c, unsigned n, unsigned ms)
    {
        while (n > c)
            c = c < ms / 2 ? c * 2 : ms;
        return c;
    }
    unsigned grow(unsigned n) const
    {
        unsigned ms = max_size();
        if (n > ms)
            Error_001210e4(DAT_002da188);
        return grow2_001210e4(cap_ ? cap_ - 1 : 1, n, ms);
    }
    Iter_001210e4 begin()
    {
        Iter_001210e4 r(data_, cap_, start_, start_);
        return r;
    }
    Iter_001210e4 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_001210e4(data_ + i, data_, &data_[cap_], data_ + start_);
    }
    void swap(Cdeque_001210e4 &x)
    {
        if (&x != this) {
            unsigned t;
            T_001210e4 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};

extern "C" void FUN_001210e4(Cdeque_001210e4 *self, Iter_001210e4 position, unsigned n, const T_001210e4 &x)
{
    Alloc_001210e4 a;
    if (n == 0)
        return;
    if (self->size_ + n <= self->capacity()) {
        Iter_001210e4 b;
        b = self->begin();
        unsigned pb = (unsigned)(position - b);
        unsigned pe = self->size_ - pb;
        const T_001210e4 &xr = (self->data_ <= &x && &x < self->data_ + self->cap_) ? T_001210e4(x) : x;
        if (pb < pe) {
            for (unsigned i = pb; i < n; ++i) {
                --b;
                a.construct(&*b, xr);
                self->start_ = b.ptr - self->data_;
                ++self->size_;
            }
            unsigned m = min_001210e4(pb, n);
            for (unsigned i = 0; i < m; ++i) {
                --b;
                a.construct(&*b, *(b + n));
                self->start_ = b.ptr - self->data_;
                ++self->size_;
            }
            Iter_001210e4 i = b + n;
            if (n < pb)
                i = copy_001210e4(i + n, i + pb, i);
            for (; m > 0; ++i, --m)
                *i = xr;
        } else {
            Iter_001210e4 e = self->end();
            for (unsigned k = pe; k < n; ++k, ++e) {
                a.construct(&*e, xr);
                ++self->size_;
            }
            unsigned m = min_001210e4(pe, n);
            for (unsigned k = 0; k < m; ++k, ++e) {
                a.construct(&*e, e[-(int)n]);
                ++self->size_;
            }
            Iter_001210e4 i = e;
            i -= n;
            if (n < pe)
                i = copy_backward_001210e4(i - pe, i - n, i);
            for (; m > 0; --m)
                *--i = xr;
        }
    } else {
        unsigned c = self->grow(self->size_ + n);
        Cdeque_001210e4 tmp;
        tmp.data_ = a.allocate(c + 1);
        tmp.cap_ = c + 1;
        T_001210e4 *p = tmp.data_;
        Iter_001210e4 i = self->begin();
        for (; i < position; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        for (; n > 0; --n, ++tmp.size_, ++p)
            a.construct(p, x);
        for (Iter_001210e4 e = self->end(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}

// WIP (2026-10-15, agent famL-00): 7 words from exact (625/625 words; frame, slots, control flow, s- and
// t-registers match). Remaining: (1) front path, 4 words: retail loads position.first (`lw a3,8(s3)`) after
// `subu v1,a1,t0` (position.ptr - begin.ptr), ours right after `lw a1,0(s3)`; computing the byte difference
// first and dividing after the x.first load (`int d = (char *)x.ptr - (char *)y.ptr; T *f = x.first;
// d /= 4;`) fixes the placement but swaps a1/a3 (6 words); x.ptr/y.ptr/f local orders, operator- and
// distance() forms tried. (2) realloc loop-1 preheader, 3 words: hoisted `li t0,1` scheduled before
// `addu v1; move a2,a0` (same as wip/cdeque_insert_range_0011f5e0.cpp and _001918f4.cpp).
// Notes: unlike the 0x11f5e0 sibling, this one needs the IMPLICIT iterator copy-assignment for
// `Iter b; b = begin();` (any user operator=, whatever the field order, gives 38 front-path words); the back
// path's end() needs `&data_[cap_]` for end_ (cap*4 computed before the data_ load, so data_ reuses cap's
// register); the x-in-buffer test is `const T &xr = (data_ <= &x && &x < data_ + cap_) ? T(x) : x;` (two
// identical loads in the diamond); fill loops `for (; m > 0; ++i, --m) *i = xr;` and
// `for (; m > 0; --m) *--i = xr;`; realloc fill `for (; n > 0; --n, ++tmp.size_, ++p) construct(p, x);`.
