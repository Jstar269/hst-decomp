/* HSTMATCH module=EBOOT.BIN start=0x001918f4 end=0x001923d0 symbol=FUN_001918f4 lang=c++ */
/* MSL-style circular deque (cdeque) of 4-byte elements (pointers): insert(position, first, last,
   forward_iterator_tag) for a cdeque iterator range (caller 0x1915f4). n = distance; if size()+n fits the
   capacity, shift the shorter side (front: push the head of [first,last) / old front elements in front of
   begin(), copy the rest; back: the mirror image with copy_backward); otherwise grow into a temporary cdeque
   (capacity from 0x192a3c), copy [begin,pos) + [first,last) + [pos,end) with const_iterators, swap, destroy.
   Iterator {ptr, beg, first, end}; names provisional. */extern "C" {
struct Reent_001918f4 { int pad[3]; void *err; };
Reent_001918f4 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c2788[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

struct Obj_001918f4;
typedef Obj_001918f4 *T;

struct Iter {
    T *ptr;
    T *beg;
    T *first;
    T *end;
    Iter(T *p, T *b, T *e, T *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter(const Iter &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    T &operator*() const { return *ptr; }
    Iter &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    Iter &operator--()
    {
        if (ptr == beg)
            ptr = end;
        --ptr;
        return *this;
    }
    Iter &operator+=(int n)
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
    Iter &operator-=(int n) { return *this += -n; }
    Iter operator+(int n) const { return Iter(*this) += n; }
    Iter operator-(int n) const { return Iter(*this) -= n; }
    T &operator[](int n) const { return *(*this + n); }
};
inline int operator-(const Iter &x, const Iter &y)
{
    T *f = x.first;
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
inline bool operator!=(const Iter &x, const Iter &y) { return x.ptr != y.ptr; }
struct CIter {
    T *ptr;
    T *beg;
    T *first;
    T *end;
    CIter(const CIter &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    CIter(const Iter &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    T &operator*() const { return *ptr; }
    CIter &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    CIter &operator--()
    {
        if (ptr == beg)
            ptr = end;
        --ptr;
        return *this;
    }
    CIter &operator+=(int n)
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
    CIter operator+(int n) const { return CIter(*this) += n; }
};
inline int operator-(const CIter &x, const CIter &y)
{
    T *f = x.first;
    T *b = x.beg;
    T *e = x.end;
    int d = x.ptr - y.ptr;
    if (x.ptr >= f) {
        if (y.ptr < f)
            d -= e - b;
    } else {
        if (y.ptr >= f)
            d += e - b;
    }
    return d;
}
inline bool operator!=(const CIter &x, const CIter &y) { return x.ptr != y.ptr; }
inline bool operator<(const CIter &x, const CIter &y)
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

template <class U> inline const U &Min(const U &a, const U &b) { return b < a ? b : a; }
template <class U> inline void Swap(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}
template <class I, class O> inline O Copy(I first, I last, O result)
{
    for (; first != last; ++first, ++result)
        *result = *first;
    return result;
}
template <class I, class O> inline O CopyBackward(I first, I last, O result)
{
    while (last != first)
        *--result = *--last;
    return result;
}

struct Alloc {
    T *allocate(unsigned n)
    {
        T *p = (T *)FUN_00000bcc(n * sizeof(T));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2788);
            FUN_0000d518();
        }
        return p;
    }
    void construct(T *p, const T &v) { new (p) T(v); }
};

struct Cdeque;
extern "C" {
unsigned FUN_00192a3c(const Cdeque *self, unsigned n); /* grow-to capacity */
void FUN_00190f50(Cdeque *self);                       /* clear */
}
struct Cdeque {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T *data_;
    Cdeque() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque()
    {
        if (data_) {
            FUN_00190f50(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter begin() { return Iter(data_ + start_, data_, data_ + cap_, data_ + start_); }
    Iter end() { unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0; return Iter(data_ + i, data_, data_ + cap_, data_ + start_); }
    void swap(Cdeque &x)
    {
        if (this != &x) {
            Swap(cap_, x.cap_);
            Swap(size_, x.size_);
            Swap(start_, x.start_);
            Swap(data_, x.data_);
        }
    }
};

struct InTag {};
struct FwdTag : InTag {};

extern "C" void FUN_001918f4(Cdeque *self, Iter position, CIter first, CIter last, FwdTag)
{
    unsigned n = (unsigned)(last - first);
    if (n == 0)
        return;
    Alloc a;
    unsigned cap0 = self->capacity();
    if (self->size() + n <= cap0) {
        Iter i = self->begin();
        unsigned pb = (unsigned)(position - i);
        unsigned pe = self->size() - pb;
        if (pb < pe) {
            if (pb < n) {
                first += n - pb;
                CIter m = first;
                for (unsigned j = pb; j < n; ++j) {
                    --i;
                    --m;
                    a.construct(i.ptr, *m);
                    self->start_ = i.ptr - self->data_;
                    ++self->size_;
                }
            }
            unsigned c = Min(pb, n);
            for (unsigned j = 0; j < c; ++j) {
                --i;
                a.construct(i.ptr, i[n]);
                self->start_ = i.ptr - self->data_;
                ++self->size_;
            }
            i += n;
            if (n < pb)
                i = Copy(i + n, i + pb, i);
            Copy(first, last, i);
        } else {
            i = self->end();
            if (pe < n) {
                last = first + pe;
                CIter m = last;
                for (unsigned j = pe; j < n; ++j, ++i, ++m) {
                    a.construct(i.ptr, *m);
                    ++self->size_;
                }
            }
            unsigned c = Min(pe, n);
            for (unsigned j = 0; j < c; ++j, ++i) {
                a.construct(i.ptr, i[-n]);
                ++self->size_;
            }
            i -= n;
            if (n < pe)
                i = CopyBackward(i - pe, i - n, i);
            CopyBackward(first, last, i);
        }
    } else {
        unsigned cap = FUN_00192a3c(self, self->size() + n);
        Cdeque tmp;
        tmp.data_ = a.allocate(cap + 1);
        tmp.cap_ = cap + 1;
        T *p = tmp.data_;
        CIter j = self->begin();
        for (; j < position; ++j, ++p, ++tmp.size_)
            a.construct(p, *j);
        for (; n > 0; --n, ++p, ++tmp.size_, ++first)
            a.construct(p, *first);
        CIter e = self->end();
        for (; j < e; ++j, ++p, ++tmp.size_)
            a.construct(p, *j);
        tmp.swap(*self);
    }
}

// WIP (2026-10-15, agent famL-01): 14 words from exact (695/695 words, frame/stack slots/control flow all
// match). Remaining:
//  * entry (8 words): retail loads first.ptr, last.ptr, then last.beg/end/first with last.ptr in t1 and
//    last.first in a0 (`move s3,a0` scheduled after the last.ptr load); ours puts last.ptr in a0 and
//    last.first in t1. Tried all 24 orders of the b/e/f/d locals in CIter operator- (fbed best), x.first used
//    directly, xp/yp locals, by-value Distance() helpers with and without a random-access tag (tag adds a
//    16-byte frame), f-only operator- with by-value copies.
//  * `addu a1,v1,t3` (size + n) comes out as n + size whatever the source operand order (also tried a
//    named sum, n as int then unsigned, `!(cap < sz)`, `capacity() - size() >= n`).
//  * realloc loop-1 preheader: retail schedules `li t0,1` (operator< `true`) after `addu end; move ptr`,
//    ours before (3 words). Tried j via direct-init/copy-init/named Iter, CIter(const Iter&) body-assignment
//    orders (24), operator<(CIter, Iter), f-local operator<, position copied to a CIter first, const
//    begin() returning CIter (worse: breaks the cap_ reload).
// Findings that got it from 660 to 14 differing words (see MWCC-NOTES 0x1918f4 line): the copy_backward
// arguments' stack temporaries (sp+52/36) come from `Iter(*this) -= n` with `-=` forwarding to `+= -n`
// (two reference-returning levels); `*(i - n)`/`k = i - n` must not use that form (`i[-n]` via
// `*(*this + n)`, `i -= n` in place); unsigned `-n` keeps negu; `+=` must modify its parameter
// (`n += ptr - beg`) so arguments are evaluated before the body; `Iter(*this) += n` keeps the signed
// division select inside loops; begin()/end() non-const vs capacity() const stops the cap_ CSE; 4-pointer
// iterator ctor (p, b, e, f) with begin() args right-to-left gives retail's register order; the realloc
// copies iterate with a const_iterator converted from begin(); the n loop is `--n, ++p, ++size, ++first`.
