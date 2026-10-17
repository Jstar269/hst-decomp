/* HSTMATCH module=EBOOT.BIN start=0x0011f5e0 end=0x00120154 symbol=FUN_0011f5e0 lang=c++ */
/* MSL-style circular deque (cdeque) of 4-byte elements: insert(position, first, last, forward_iterator_tag)
   for a const_iterator range. n = distance(first, last); if size() + n fits capacity(), open the gap on the
   shorter side (front: construct the head of [first,last) and the first min(pb, n) old elements in front of
   begin(), shift [begin+n, begin+pb) down, copy the rest of the range; back: the mirror image with
   copy_backward); otherwise grow (max_size check, doubling from capacity, clamp) into a temporary cdeque,
   copy [begin,pos) + [first,last) + [pos,end), swap, destroy (0x11d7e4 clear + delete). Iterator
   {ptr, beg, first, end}; It<0> = iterator, It<1> = const_iterator. Names provisional. */
extern "C" {
struct Reent_0011f5e0 { int pad[3]; void *err; };
Reent_0011f5e0 *FUN_0000fe3c(void);
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

typedef int T_0011f5e0;

template <class U> inline const U &min_0011f5e0(const U &a, const U &b) { return b < a ? b : a; }

template <int C> struct It_0011f5e0 {
    T_0011f5e0 *ptr;
    T_0011f5e0 *beg;
    T_0011f5e0 *first;
    T_0011f5e0 *end;
    It_0011f5e0() {}
    It_0011f5e0(T_0011f5e0 *p, T_0011f5e0 *b, T_0011f5e0 *e, T_0011f5e0 *f) : ptr(p), beg(b), first(f), end(e) {}
    It_0011f5e0(T_0011f5e0 *d, unsigned cap, unsigned start, unsigned i) { first = d + start; end = d + cap; beg = d; ptr = d + i; }
    It_0011f5e0(const It_0011f5e0<0> &i) : ptr(i.ptr), beg(i.beg), first(i.first), end(i.end) {}
    It_0011f5e0(const It_0011f5e0<1> &i) : ptr(i.ptr), beg(i.beg), first(i.first), end(i.end) {}
    It_0011f5e0 &operator=(const It_0011f5e0<0> &i)
    {
        first = i.first;
        end = i.end;
        beg = i.beg;
        ptr = i.ptr;
        return *this;
    }
    T_0011f5e0 &operator*() const { return *ptr; }
    It_0011f5e0 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    It_0011f5e0 &operator--()
    {
        if (ptr == beg)
            ptr = end;
        --ptr;
        return *this;
    }
    It_0011f5e0 &operator+=(int n)
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
    It_0011f5e0 operator+(int n) const { return It_0011f5e0(*this) += n; }
    T_0011f5e0 &operator[](int n) const { return *(*this + n); }
    It_0011f5e0 &operator-=(int n) { return *this += -n; }
    It_0011f5e0 operator-(int n) const { return It_0011f5e0(*this) -= n; }
};
typedef It_0011f5e0<0> Iter_0011f5e0;
typedef It_0011f5e0<1> CIter_0011f5e0;
template <int A, int B> inline int operator-(const It_0011f5e0<A> &x, const It_0011f5e0<B> &y)
{
    T_0011f5e0 *f = x.first;
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
template <class I> inline int distance_0011f5e0(I first, I last) { return last - first; }
template <int A, int B> inline bool operator!=(const It_0011f5e0<A> &x, const It_0011f5e0<B> &y) { return x.ptr != y.ptr; }
template <int A, int B> inline bool operator<(const It_0011f5e0<A> &x, const It_0011f5e0<B> &y)
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

template <class I, class O> inline O copy_0011f5e0(I first, I last, O result)
{
    for (; first != last; ++first, ++result)
        *result = *first;
    return result;
}
template <class I, class O> inline O copy_backward_0011f5e0(I first, I last, O result)
{
    while (last != first)
        *--result = *--last;
    return result;
}

inline void Error_0011f5e0(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_0011f5e0 {
    unsigned max_size() const { return 0x3fffffff; }
    T_0011f5e0 *allocate(unsigned n)
    {
        T_0011f5e0 *p = (T_0011f5e0 *)FUN_00000bcc(n * sizeof(T_0011f5e0));
        if (p == 0)
            Error_0011f5e0(DAT_002c138c);
        return p;
    }
    void construct(T_0011f5e0 *p, const T_0011f5e0 &v) { new (p) T_0011f5e0(v); }
};
struct ForwardTag_0011f5e0 {};

struct Cdeque_0011f5e0;
extern "C" void FUN_0011d7e4(Cdeque_0011f5e0 *self);
struct Cdeque_0011f5e0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0011f5e0 *data_;
    Cdeque_0011f5e0() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0011f5e0()
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
            DAT_002c1334 = Alloc_0011f5e0().max_size();
            --DAT_002c1334;
            DAT_0033b493 = 1;
        }
        return DAT_002c1334;
    }
    static unsigned grow2_0011f5e0(unsigned c, unsigned n, unsigned ms)
    {
        while (n > c)
            c = c < ms / 2 ? c * 2 : ms;
        return c;
    }
    unsigned grow(unsigned n) const
    {
        unsigned ms = max_size();
        if (n > ms)
            Error_0011f5e0(DAT_002da188);
        return grow2_0011f5e0(cap_ ? cap_ - 1 : 1, n, ms);
    }
    Iter_0011f5e0 begin()
    {
        Iter_0011f5e0 r(data_, cap_, start_, start_);
        return r;
    }
    Iter_0011f5e0 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        T_0011f5e0 *b = data_;
        return Iter_0011f5e0(b + i, b, b + cap_, b + start_);
    }
    void swap(Cdeque_0011f5e0 &x)
    {
        if (&x != this) {
            unsigned t;
            T_0011f5e0 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};

extern "C" void FUN_0011f5e0(Cdeque_0011f5e0 *self, Iter_0011f5e0 position, CIter_0011f5e0 first, CIter_0011f5e0 last, ForwardTag_0011f5e0)
{
    Alloc_0011f5e0 a;
    unsigned n = (unsigned)distance_0011f5e0(first, last);
    if (n == 0)
        return;
    if (self->size_ + n <= self->capacity()) {
        Iter_0011f5e0 b;
        b = self->begin();
        unsigned pb = (unsigned)(position - b);
        unsigned pe = self->size_ - pb;
        if (pb < pe) {
            if (pb < n) {
                first += n - pb;
                CIter_0011f5e0 j = first;
                for (unsigned i = pb; i < n; ++i) {
                    --b;
                    --j;
                    a.construct(&*b, *j);
                    self->start_ = b.ptr - self->data_;
                    ++self->size_;
                }
            }
            unsigned m = min_0011f5e0(pb, n);
            for (unsigned i = 0; i < m; ++i) {
                --b;
                a.construct(&*b, *(b + n));
                self->start_ = b.ptr - self->data_;
                ++self->size_;
            }
            Iter_0011f5e0 i = b + n;
            if (n < pb)
                i = copy_0011f5e0(i + n, i + pb, i);
            copy_0011f5e0(first, last, i);
        } else {
            Iter_0011f5e0 e;
            e = self->end();
            if (pe < n) {
                last = first + pe;
                CIter_0011f5e0 j = last;
                for (unsigned k = pe; k < n; ++k, ++e, ++j) {
                    a.construct(&*e, *j);
                    ++self->size_;
                }
            }
            unsigned m = min_0011f5e0(pe, n);
            for (unsigned k = 0; k < m; ++k, ++e) {
                a.construct(&*e, e[-(int)n]);
                ++self->size_;
            }
            Iter_0011f5e0 i = e;
            i -= n;
            if (n < pe)
                i = copy_backward_0011f5e0(i - pe, i - n, i);
            copy_backward_0011f5e0(first, last, i);
        }
    } else {
        unsigned c = self->grow(self->size_ + n);
        Cdeque_0011f5e0 tmp;
        tmp.data_ = a.allocate(c + 1);
        tmp.cap_ = c + 1;
        T_0011f5e0 *p = tmp.data_;
        Iter_0011f5e0 i = self->begin();
        for (; i < position; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        for (; n > 0; --n, ++tmp.size_, ++p, ++first)
            a.construct(p, *first);
        for (Iter_0011f5e0 e = self->end(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}

// WIP (2026-10-15, agent famL-00): 3 words from exact (733/733 words; frame, stack slots, control flow,
// s-registers and t-registers all match). Remaining: realloc path, loop-1 preheader: retail schedules the
// hoisted `li t0,1` (operator< `return true`) after `addu v1 (i.end); move a2,a0 (i.ptr)`, ours before them
// (same 3-word issue as wip/cdeque_insert_range_001918f4.cpp). Tried: all begin() construction forms for that
// site (4-pointer ctor x24 orders, (d,cap,start,i) ctor x24 bodies, field assignment x24, named/unnamed
// return, begin2 without named return), `Iter i; i = begin()`, CIter i/e, CIter position, `position > i`,
// operator< with int return / 1/0 / separate returns / shared tail, increment-list orders, post-increment.
// What fixed the rest (from 755 words / 737 differing): grow capacity computed by a static helper taking it
// as a PARAMETER (inline params are coloured before named locals: c gets s0); the iterator needs a user
// copy ctor for BOTH It<0> and It<1> (by-reference params) but a user copy-assignment (first, end, beg, ptr)
// only for It<0>, with `Iter b; b = begin();` / `Iter e; e = end();` (front/back t0-t2 colouring) while
// `last = first + pe` (It<1>, implicit op=) keeps retail's store order; begin() through a named local
// (`It r(...); return r;`) for the realloc colouring; `e[-(int)n]` and `i = e; i -= n;` keep those iterators
// in registers while copy_backward(i - pe, i - n, i) stays in the sp+64/48 slots; n loop increments
// `--n, ++tmp.size_, ++p, ++first`.
