/* HSTMATCH module=hstp_trans_main.prx start=0x0026c5dc end=0x0026c7e4 symbol=FUN_0026c5dc lang=c++ data=0x003a640c */
/* Clone of src/eboot/cdeque_reserve_00192834.cpp (hstclone.py tag u6fr2s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a640c-0x003a6429) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
struct Reent_0026c5dc { int pad[3]; void *err; };
Reent_0026c5dc *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
extern char DAT_002dad78[]; /* "Memory allocation failure" */
}
inline void *operator new(unsigned, void *p) { return p; }
typedef int Elem_0026c5dc;
struct Iter_0026c5dc {
    Elem_0026c5dc *ptr;
    Elem_0026c5dc *beg;
    Elem_0026c5dc *first;
    Elem_0026c5dc *end;
    Iter_0026c5dc(Elem_0026c5dc *p, Elem_0026c5dc *b, Elem_0026c5dc *e, Elem_0026c5dc *f)
        : ptr(p), beg(b), first(f), end(e) {}
    Iter_0026c5dc(const Iter_0026c5dc &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0026c5dc &operator++()
    {
        Elem_0026c5dc *q = ptr + 1;
        if (q == end)
            q = beg;
        ptr = q;
        return *this;
    }
    Elem_0026c5dc &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0026c5dc &x, const Iter_0026c5dc &y)
{
    Elem_0026c5dc *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}
inline void Error_0026c5dc(const char *msg)
{
    FUN_0000f3e8(FUN_0000fe3c()->err, msg);
    FUN_0000d530();
}
struct Alloc_0026c5dc {
    unsigned max_size() const { return 0x3fffffff; }
    Elem_0026c5dc *allocate(unsigned n)
    {
        Elem_0026c5dc *p = (Elem_0026c5dc *)FUN_00000bcc(n * sizeof(Elem_0026c5dc));
        if (p == 0)
            Error_0026c5dc(DAT_002dad78);
        return p;
    }
    void construct(Elem_0026c5dc *p, const Elem_0026c5dc &v) { new (p) Elem_0026c5dc(v); }
};
struct Cdeque_0026c5dc;
extern "C" void FUN_0026af40(Cdeque_0026c5dc *self); /* clear() */
extern "C" unsigned FUN_0026c8e8(const Cdeque_0026c5dc *self); /* max_size() */
struct Cdeque_0026c5dc {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    Elem_0026c5dc *data_;
    Cdeque_0026c5dc() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0026c5dc()
    {
        if (data_) {
            FUN_0026af40(this);
            operator delete(data_);
        }
    }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    unsigned max_size() const { return FUN_0026c8e8(this); }
    Iter_0026c5dc begin() { Iter_0026c5dc it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_0026c5dc end()
    {
        unsigned i = cap_ ? (start_ + size_) % cap_ : 0;
        return Iter_0026c5dc(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0026c5dc &x)
    {
        if (&x != this) {
            unsigned t;
            Elem_0026c5dc *d;
            t = x.cap_; x.cap_ = cap_; cap_ = t;
            t = x.size_; x.size_ = size_; size_ = t;
            t = x.start_; x.start_ = start_; start_ = t;
            d = x.data_; x.data_ = data_; data_ = d;
        }
    }
};
extern "C" void FUN_0026c5dc(Cdeque_0026c5dc *self, unsigned n)
{
    if (n > self->capacity()) {
        if (n > self->max_size())
            Error_0026c5dc("cdeque::reserve length error");
        Cdeque_0026c5dc tmp;
        Alloc_0026c5dc a;
        Elem_0026c5dc *p = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        tmp.data_ = p;
        Iter_0026c5dc last = self->end();
        for (Iter_0026c5dc i = self->begin(); i < last; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        self->swap(tmp);
    }
}
