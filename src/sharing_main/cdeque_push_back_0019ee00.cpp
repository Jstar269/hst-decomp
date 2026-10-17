/* HSTMATCH module=hstp_trans_main.prx start=0x0019ee00 end=0x0019f044 symbol=FUN_0019ee00 lang=c++ */
/* Clone of src/eboot/cdeque_push_back_0011d894.cpp (hstclone.py tag u6fr2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin near miss wip/cdeque_push_back_0019ee00.cpp: Iter has a user-declared copy constructor, begin() returns a named local and operator< reads x.first once); exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: push_back(x). Fast path constructs at (start + size) % cap;
   otherwise grow to the capacity from 0x12a6e4 into a temporary cdeque, copy the elements through the
   wrap-aware iterator operator<, construct x, swap, and let the temporary's destructor clear (0x1289b8) and free
   the old buffer. The user-declared Iter copy constructor plus begin() building a named local is what makes
   the begin pointer the register that holds data + start * 4. Names provisional. */
extern "C" {
struct Reent_0019ee00 { int pad[3]; void *err; };
Reent_0019ee00 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d2c88[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_0019ee00;

struct Cdeque_0019ee00;
struct Iter_0019ee00 {
    T_0019ee00 *ptr;
    T_0019ee00 *beg;
    T_0019ee00 *first;
    T_0019ee00 *end;
    Iter_0019ee00(T_0019ee00 *p, T_0019ee00 *b, T_0019ee00 *e, T_0019ee00 *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter_0019ee00(const Iter_0019ee00 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0019ee00 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_0019ee00 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0019ee00 &x, const Iter_0019ee00 &y)
{
    T_0019ee00 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_0019ee00 {
    T_0019ee00 *allocate(unsigned n)
    {
        T_0019ee00 *p = (T_0019ee00 *)FUN_00000bcc(n * sizeof(T_0019ee00));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d2c88);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(T_0019ee00 *p) { FUN_00000a00(p); }
    void construct(T_0019ee00 *p, const T_0019ee00 &v) { new (p) T_0019ee00(v); }
};

struct Cdeque_0019ee00;
extern "C" {
unsigned FUN_0019f24c(const Cdeque_0019ee00 *self, unsigned n); /* grow-to capacity */
void FUN_0019d760(Cdeque_0019ee00 *self);                       /* clear */
}

template <class U> inline void swap_0019ee00(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_0019ee00 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0019ee00 *data_;
    Cdeque_0019ee00() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0019ee00()
    {
        if (data_) {
            FUN_0019d760(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_0019ee00 begin() { Iter_0019ee00 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_0019ee00 end()
    {
        unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0;
        return Iter_0019ee00(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0019ee00 &x)
    {
        if (this != &x) {
            ::swap_0019ee00(cap_, x.cap_);
            ::swap_0019ee00(size_, x.size_);
            ::swap_0019ee00(start_, x.start_);
            ::swap_0019ee00(data_, x.data_);
        }
    }
    void push_back(const T_0019ee00 &x);
};

extern "C" void FUN_0019ee00(Cdeque_0019ee00 *self, const T_0019ee00 &x)
{
    Alloc_0019ee00 a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_0019f24c(self, self->size_ + 1);
        Cdeque_0019ee00 tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_0019ee00 *p = tmp.data_;
        Iter_0019ee00 e = self->end();
        for (Iter_0019ee00 i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
