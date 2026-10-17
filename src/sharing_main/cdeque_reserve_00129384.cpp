/* HSTMATCH module=hstp_trans_main.prx start=0x00129384 end=0x001295bc symbol=FUN_00129384 lang=c++ */
/* Clone of src/eboot/cdeque_reserve_0011dad8.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* MSL-style circular deque (cdeque) of 4-byte elements: reserve(n). When n exceeds capacity (cap - 1),
   check max_size(), build a temporary with an (n + 1)-slot buffer, copy-construct the elements from
   begin() to end() (iterator order compares through the wrap point), swap, and let the temporary's
   destructor clear (0x11d7e4) and free the old buffer. max_size() is a guarded function-local static
   in retail (guard byte 0x3e47d2, value 0x2d1710); the guard is written out against those globals, and
   the store-then-decrement keeps MWCC from folding 0x3fffffff - 1 (retail computes it at run time).
   The iterator constructor takes the buffer end before the logical first and ++ goes through a local;
   both fix the register allocation. Names provisional. */
extern "C" {
struct Reent_00129384 { int pad[3]; void *err; };
Reent_00129384 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00381148[]; /* "cdeque::reserve length error" */
extern char DAT_002d1734[]; /* "Memory allocation failure" */
extern char DAT_003e47d2;     /* max_size() static guard */
extern unsigned DAT_002d1710; /* max_size() static value */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_00129384;
struct Iter_00129384 {
    Elem_00129384 *ptr;
    Elem_00129384 *beg;
    Elem_00129384 *first;
    Elem_00129384 *end;
    Iter_00129384(Elem_00129384 *p, Elem_00129384 *b, Elem_00129384 *e, Elem_00129384 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_00129384 &operator++()
    {
        Elem_00129384 *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_00129384 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_00129384 &x, const Iter_00129384 &y)
{
    Elem_00129384 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_00129384(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
struct Alloc_00129384 {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_00129384 *allocate(unsigned n)
    {
        Elem_00129384 *p = (Elem_00129384 *)FUN_00000bcc(n * sizeof(Elem_00129384));
        if (p == 0)
            Error_00129384(DAT_002d1734);
        return p;
    }
    void construct(Elem_00129384 *p, const Elem_00129384 &v) { new (p) Elem_00129384(v); }
};
struct Cdeque_00129384;
extern "C" void FUN_00129090(Cdeque_00129384 *self); /* clear() */
struct Cdeque_00129384 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00129384 *data_;
    Cdeque_00129384() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_00129384()
    {
        if (data_) {
            FUN_00129090(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_003e47d2) {
            DAT_002d1710 = Alloc_00129384().max_size();
            --DAT_002d1710;
            DAT_003e47d2 = 1;
        }
        return DAT_002d1710;
    }
    Iter_00129384 begin() { return Iter_00129384(data_ + start_, data_, data_ + cap_, data_ + start_); }
    Iter_00129384 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_00129384(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_00129384 &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_00129384 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_00129384(Cdeque_00129384 *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_00129384(DAT_00381148);
        Cdeque_00129384 tmp;
        Alloc_00129384 a;
        Elem_00129384 *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_00129384 last = self->end();
        for (Iter_00129384 i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
