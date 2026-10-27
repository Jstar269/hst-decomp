/* HSTMATCH module=EBOOT.BIN start=0x0025c12c end=0x0025c334 symbol=FUN_0025c12c lang=c++ data=0x002fd864 */
/* Clone of src/sharing_main/cdeque_reserve_0019f044.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fd864-0x002fd881) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/cdeque_reserve_0011dad8.cpp: max_size() is the out-of-line call 0x19f350, Iter has a user-declared copy constructor and begin() returns a named local); exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* MSL-style circular deque (cdeque) of 4-byte elements: reserve(n). When n exceeds capacity (cap - 1),
   check max_size() (out of line here, 0x19f350), build a temporary with an (n + 1)-slot buffer, copy-construct
   the elements from begin() to end() (iterator order compares through the wrap point), swap, and let the
   temporary's destructor clear (0x19d760) and free the old buffer. The iterator constructor takes the buffer
   end before the logical first and ++ goes through a local; the user-declared Iter copy constructor together
   with begin() building a named local is what makes the begin pointer the register that holds
   data + start * 4 (the logical first is the copy). Names provisional. */
extern "C" {
struct Reent_0025c12c { int pad[3]; void *err; };
Reent_0025c12c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002ca7b8[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_0025c12c;
struct Iter_0025c12c {
    Elem_0025c12c *ptr;
    Elem_0025c12c *beg;
    Elem_0025c12c *first;
    Elem_0025c12c *end;
    Iter_0025c12c(Elem_0025c12c *p, Elem_0025c12c *b, Elem_0025c12c *e, Elem_0025c12c *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_0025c12c(const Iter_0025c12c &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0025c12c &operator++()
    {
        Elem_0025c12c *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_0025c12c &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0025c12c &x, const Iter_0025c12c &y)
{
    Elem_0025c12c *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_0025c12c(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_0025c12c {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_0025c12c *allocate(unsigned n)
    {
        Elem_0025c12c *p = (Elem_0025c12c *)FUN_00000bcc(n * sizeof(Elem_0025c12c));
        if (p == 0)
            Error_0025c12c(DAT_002ca7b8);
        return p;
    }
    void construct(Elem_0025c12c *p, const Elem_0025c12c &v) { new (p) Elem_0025c12c(v); }
};
struct Cdeque_0025c12c;
extern "C" void FUN_0025aa90(Cdeque_0025c12c *self); /* clear() */
extern "C" unsigned FUN_0025c438(const Cdeque_0025c12c *self); /* max_size() */
struct Cdeque_0025c12c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0025c12c *data_;
    Cdeque_0025c12c() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0025c12c()
    {
        if (data_) {
            FUN_0025aa90(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const { return FUN_0025c438(this); }
    Iter_0025c12c begin() { Iter_0025c12c it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_0025c12c end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0025c12c(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0025c12c &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_0025c12c *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_0025c12c(Cdeque_0025c12c *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_0025c12c("cdeque::reserve length error");
        Cdeque_0025c12c tmp;
        Alloc_0025c12c a;
        Elem_0025c12c *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_0025c12c last = self->end();
        for (Iter_0025c12c i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
