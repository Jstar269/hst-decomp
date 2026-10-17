/* HSTMATCH module=EBOOT.BIN start=0x0011dad8 end=0x0011dd10 symbol=FUN_0011dad8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* MSL-style circular deque (cdeque) of 4-byte elements: reserve(n). When n exceeds capacity (cap - 1),
   check max_size(), build a temporary with an (n + 1)-slot buffer, copy-construct the elements from
   begin() to end() (iterator order compares through the wrap point), swap, and let the temporary's
   destructor clear (0x11d7e4) and free the old buffer. max_size() is a guarded function-local static
   in retail (guard byte 0x33b493, value 0x2c1334); the guard is written out against those globals, and
   the store-then-decrement keeps MWCC from folding 0x3fffffff - 1 (retail computes it at run time).
   The iterator constructor takes the buffer end before the logical first and ++ goes through a local;
   both fix the register allocation. Names provisional. */
extern "C" {
struct Reent_0011dad8 { int pad[3]; void *err; };
Reent_0011dad8 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da168[]; /* "cdeque::reserve length error" */
extern char DAT_002c138c[]; /* "Memory allocation failure" */
extern char DAT_0033b493;     /* max_size() static guard */
extern unsigned DAT_002c1334; /* max_size() static value */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_0011dad8;
struct Iter_0011dad8 {
    Elem_0011dad8 *ptr;
    Elem_0011dad8 *beg;
    Elem_0011dad8 *first;
    Elem_0011dad8 *end;
    Iter_0011dad8(Elem_0011dad8 *p, Elem_0011dad8 *b, Elem_0011dad8 *e, Elem_0011dad8 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_0011dad8 &operator++()
    {
        Elem_0011dad8 *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_0011dad8 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0011dad8 &x, const Iter_0011dad8 &y)
{
    Elem_0011dad8 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_0011dad8(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_0011dad8 {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_0011dad8 *allocate(unsigned n)
    {
        Elem_0011dad8 *p = (Elem_0011dad8 *)FUN_00000bcc(n * sizeof(Elem_0011dad8));
        if (p == 0)
            Error_0011dad8(DAT_002c138c);
        return p;
    }
    void construct(Elem_0011dad8 *p, const Elem_0011dad8 &v) { new (p) Elem_0011dad8(v); }
};
struct Cdeque_0011dad8;
extern "C" void FUN_0011d7e4(Cdeque_0011dad8 *self); /* clear() */
struct Cdeque_0011dad8 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0011dad8 *data_;
    Cdeque_0011dad8() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0011dad8()
    {
        if (data_) {
            FUN_0011d7e4(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_0033b493) {
            DAT_002c1334 = Alloc_0011dad8().max_size();
            --DAT_002c1334;
            DAT_0033b493 = 1;
        }
        return DAT_002c1334;
    }
    Iter_0011dad8 begin() { return Iter_0011dad8(data_ + start_, data_, data_ + cap_, data_ + start_); }
    Iter_0011dad8 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0011dad8(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0011dad8 &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_0011dad8 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_0011dad8(Cdeque_0011dad8 *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_0011dad8(DAT_002da168);
        Cdeque_0011dad8 tmp;
        Alloc_0011dad8 a;
        Elem_0011dad8 *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_0011dad8 last = self->end();
        for (Iter_0011dad8 i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
