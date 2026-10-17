/* HSTMATCH module=hstp_trans_main.prx start=0x00128cac end=0x00128ee4 symbol=FUN_00128cac lang=c++ */
/* Clone of src/eboot/cdeque_reserve_0011dad8.cpp (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* MSL-style circular deque (cdeque) of 4-byte elements: reserve(n). When n exceeds capacity (cap - 1),
   check max_size(), build a temporary with an (n + 1)-slot buffer, copy-construct the elements from
   begin() to end() (iterator order compares through the wrap point), swap, and let the temporary's
   destructor clear (0x11d7e4) and free the old buffer. max_size() is a guarded function-local static
   in retail (guard byte 0x3e47d3, value 0x2d1714); the guard is written out against those globals, and
   the store-then-decrement keeps MWCC from folding 0x3fffffff - 1 (retail computes it at run time).
   The iterator constructor takes the buffer end before the logical first and ++ goes through a local;
   both fix the register allocation. Names provisional. */
extern "C" {
struct Reent_00128cac { int pad[3]; void *err; };
Reent_00128cac *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_00381148[]; /* "cdeque::reserve length error" */
extern char DAT_002d176c[]; /* "Memory allocation failure" */
extern char DAT_003e47d3;     /* max_size() static guard */
extern unsigned DAT_002d1714; /* max_size() static value */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_00128cac;
struct Iter_00128cac {
    Elem_00128cac *ptr;
    Elem_00128cac *beg;
    Elem_00128cac *first;
    Elem_00128cac *end;
    Iter_00128cac(Elem_00128cac *p, Elem_00128cac *b, Elem_00128cac *e, Elem_00128cac *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_00128cac &operator++()
    {
        Elem_00128cac *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_00128cac &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_00128cac &x, const Iter_00128cac &y)
{
    Elem_00128cac *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_00128cac(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
struct Alloc_00128cac {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_00128cac *allocate(unsigned n)
    {
        Elem_00128cac *p = (Elem_00128cac *)FUN_00000bcc(n * sizeof(Elem_00128cac));
        if (p == 0)
            Error_00128cac(DAT_002d176c);
        return p;
    }
    void construct(Elem_00128cac *p, const Elem_00128cac &v) { new (p) Elem_00128cac(v); }
};
struct Cdeque_00128cac;
extern "C" void FUN_001289b8(Cdeque_00128cac *self); /* clear() */
struct Cdeque_00128cac {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00128cac *data_;
    Cdeque_00128cac() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_00128cac()
    {
        if (data_) {
            FUN_001289b8(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const
    {
        if (!DAT_003e47d3) {
            DAT_002d1714 = Alloc_00128cac().max_size();
            --DAT_002d1714;
            DAT_003e47d3 = 1;
        }
        return DAT_002d1714;
    }
    Iter_00128cac begin() { return Iter_00128cac(data_ + start_, data_, data_ + cap_, data_ + start_); }
    Iter_00128cac end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_00128cac(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_00128cac &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_00128cac *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_00128cac(Cdeque_00128cac *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_00128cac(DAT_00381148);
        Cdeque_00128cac tmp;
        Alloc_00128cac a;
        Elem_00128cac *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_00128cac last = self->end();
        for (Iter_00128cac i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
