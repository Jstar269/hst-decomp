/* HSTMATCH module=EBOOT.BIN start=0x00192834 end=0x00192a3c symbol=FUN_00192834 lang=c++ data=0x002e13b4 */
/* Clone of src/sharing_main/cdeque_reserve_0019f044.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002e13b4-0x002e13d1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
struct Reent_00192834 { int pad[3]; void *err; };
Reent_00192834 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002c2788[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_00192834;
struct Iter_00192834 {
    Elem_00192834 *ptr;
    Elem_00192834 *beg;
    Elem_00192834 *first;
    Elem_00192834 *end;
    Iter_00192834(Elem_00192834 *p, Elem_00192834 *b, Elem_00192834 *e, Elem_00192834 *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_00192834(const Iter_00192834 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_00192834 &operator++()
    {
        Elem_00192834 *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_00192834 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_00192834 &x, const Iter_00192834 &y)
{
    Elem_00192834 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_00192834(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d518();
}
struct Alloc_00192834 {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_00192834 *allocate(unsigned n)
    {
        Elem_00192834 *p = (Elem_00192834 *)FUN_00000bcc(n * sizeof(Elem_00192834));
        if (p == 0)
            Error_00192834(DAT_002c2788);
        return p;
    }
    void construct(Elem_00192834 *p, const Elem_00192834 &v) { new (p) Elem_00192834(v); }
};
struct Cdeque_00192834;
extern "C" void FUN_00190f50(Cdeque_00192834 *self); /* clear() */
extern "C" unsigned FUN_00192b40(const Cdeque_00192834 *self); /* max_size() */
struct Cdeque_00192834 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_00192834 *data_;
    Cdeque_00192834() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_00192834()
    {
        if (data_) {
            FUN_00190f50(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const { return FUN_00192b40(this); }
    Iter_00192834 begin() { Iter_00192834 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_00192834 end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_00192834(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_00192834 &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_00192834 *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_00192834(Cdeque_00192834 *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_00192834("cdeque::reserve length error");
        Cdeque_00192834 tmp;
        Alloc_00192834 a;
        Elem_00192834 *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_00192834 last = self->end();
        for (Iter_00192834 i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
