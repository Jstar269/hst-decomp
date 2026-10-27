/* HSTMATCH module=hstp_trans_main.prx start=0x0019f044 end=0x0019f24c symbol=FUN_0019f044 lang=c++ data=0x00388a90 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/cdeque_reserve_0011dad8.cpp: max_size() is the out-of-line call 0x19f350, Iter has a user-declared copy constructor and begin() returns a named local); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00388a90-0x00388aad) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#pragma inline_depth(8)
/* MSL-style circular deque (cdeque) of 4-byte elements: reserve(n). When n exceeds capacity (cap - 1),
   check max_size() (out of line here, 0x19f350), build a temporary with an (n + 1)-slot buffer, copy-construct
   the elements from begin() to end() (iterator order compares through the wrap point), swap, and let the
   temporary's destructor clear (0x19d760) and free the old buffer. The iterator constructor takes the buffer
   end before the logical first and ++ goes through a local; the user-declared Iter copy constructor together
   with begin() building a named local is what makes the begin pointer the register that holds
   data + start * 4 (the logical first is the copy). Names provisional. */
extern "C" {
struct Reent_0019f044 { int pad[3]; void *err; };
Reent_0019f044 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002d2c88[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_0019f044;
struct Iter_0019f044 {
    Elem_0019f044 *ptr;
    Elem_0019f044 *beg;
    Elem_0019f044 *first;
    Elem_0019f044 *end;
    Iter_0019f044(Elem_0019f044 *p, Elem_0019f044 *b, Elem_0019f044 *e, Elem_0019f044 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_0019f044(const Iter_0019f044 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0019f044 &operator++()
    {
        Elem_0019f044 *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_0019f044 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0019f044 &x, const Iter_0019f044 &y)
{
    Elem_0019f044 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_0019f044(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
struct Alloc_0019f044 {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_0019f044 *allocate(unsigned n)
    {
        Elem_0019f044 *p = (Elem_0019f044 *)FUN_00000bcc(n * sizeof(Elem_0019f044));
        if (p == 0)
            Error_0019f044(DAT_002d2c88);
        return p;
    }
    void construct(Elem_0019f044 *p, const Elem_0019f044 &v) { new (p) Elem_0019f044(v); }
};
struct Cdeque_0019f044;
extern "C" void FUN_0019d760(Cdeque_0019f044 *self); /* clear() */
extern "C" unsigned FUN_0019f350(const Cdeque_0019f044 *self); /* max_size() */
struct Cdeque_0019f044 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0019f044 *data_;
    Cdeque_0019f044() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0019f044()
    {
        if (data_) {
            FUN_0019d760(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const { return FUN_0019f350(this); }
    Iter_0019f044 begin() { Iter_0019f044 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_0019f044 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0019f044(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0019f044 &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_0019f044 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_0019f044(Cdeque_0019f044 *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_0019f044("cdeque::reserve length error");
        Cdeque_0019f044 tmp;
        Alloc_0019f044 a;
        Elem_0019f044 *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_0019f044 last = self->end();
        for (Iter_0019f044 i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
