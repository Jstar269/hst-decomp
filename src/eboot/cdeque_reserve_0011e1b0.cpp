/* HSTMATCH module=EBOOT.BIN start=0x0011e1b0 end=0x0011e3e8 symbol=FUN_0011e1b0 lang=c++ */
/* Clone of src/eboot/cdeque_reserve_0011dad8.cpp (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* MSL-style circular deque (cdeque) of 4-byte elements: reserve(n). When n exceeds capacity (cap - 1),
   check max_size(), build a temporary with an (n + 1)-slot buffer, copy-construct the elements from
   begin() to end() (iterator order compares through the wrap point), swap, and let the temporary's
   destructor clear (0x11d7e4) and free the old buffer. max_size() is a guarded function-local static
   in retail (guard byte 0x33b492, value 0x2c1330); the guard is written out against those globals, and
   the store-then-decrement keeps MWCC from folding 0x3fffffff - 1 (retail computes it at run time).
   The iterator constructor takes the buffer end before the logical first and ++ goes through a local;
   both fix the register allocation. Names provisional. */
extern "C" {
struct Reent_0011e1b0 { int pad[3]; void *err; };
Reent_0011e1b0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002da168[]; /* "cdeque::reserve length error" */
extern char DAT_002c1354[]; /* "Memory allocation failure" */
extern char DAT_0033b492;     /* max_size() static guard */
extern unsigned DAT_002c1330; /* max_size() static value */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_0011e1b0;
struct Iter_0011e1b0 {
    Elem_0011e1b0 *ptr;
    Elem_0011e1b0 *beg;
    Elem_0011e1b0 *first;
    Elem_0011e1b0 *end;
    Iter_0011e1b0(Elem_0011e1b0 *p, Elem_0011e1b0 *b, Elem_0011e1b0 *e, Elem_0011e1b0 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_0011e1b0 &operator++()
    {
        Elem_0011e1b0 *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_0011e1b0 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0011e1b0 &x, const Iter_0011e1b0 &y)
{
    Elem_0011e1b0 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_0011e1b0(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_0011e1b0 {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_0011e1b0 *allocate(unsigned n)
    {
        Elem_0011e1b0 *p = (Elem_0011e1b0 *)FUN_00000bcc(n * sizeof(Elem_0011e1b0));
        if (p == 0)
            Error_0011e1b0(DAT_002c1354);
        return p;
    }
    void construct(Elem_0011e1b0 *p, const Elem_0011e1b0 &v) { new (p) Elem_0011e1b0(v); }
};
struct Cdeque_0011e1b0;
extern "C" void FUN_0011debc(Cdeque_0011e1b0 *self); /* clear() */
struct Cdeque_0011e1b0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0011e1b0 *data_;
    Cdeque_0011e1b0() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0011e1b0()
    {
        if (data_) {
            FUN_0011debc(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_0033b492) {
            DAT_002c1330 = Alloc_0011e1b0().max_size();
            --DAT_002c1330;
            DAT_0033b492 = 1;
        }
        return DAT_002c1330;
    }
    Iter_0011e1b0 begin() { return Iter_0011e1b0(data_ + start_, data_, data_ + cap_, data_ + start_); }
    Iter_0011e1b0 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0011e1b0(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0011e1b0 &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_0011e1b0 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_0011e1b0(Cdeque_0011e1b0 *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_0011e1b0(DAT_002da168);
        Cdeque_0011e1b0 tmp;
        Alloc_0011e1b0 a;
        Elem_0011e1b0 *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_0011e1b0 last = self->end();
        for (Iter_0011e1b0 i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
