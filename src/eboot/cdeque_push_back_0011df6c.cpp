/* HSTMATCH module=EBOOT.BIN start=0x0011df6c end=0x0011e1b0 symbol=FUN_0011df6c lang=c++ */
/* Clone of src/sharing_main/cdeque_push_back_00128a68.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin near miss wip/cdeque_push_back_0011d894.cpp: Iter has a user-declared copy constructor, begin() returns a named local and operator< reads x.first once); exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: push_back(x). Fast path constructs at (start + size) % cap;
   otherwise grow to the capacity from 0x12a6e4 into a temporary cdeque, copy the elements through the
   wrap-aware iterator operator<, construct x, swap, and let the temporary's destructor clear (0x1289b8) and free
   the old buffer. The user-declared Iter copy constructor plus begin() building a named local is what makes
   the begin pointer the register that holds data + start * 4. Names provisional. */
extern "C" {
struct Reent_0011df6c { int pad[3]; void *err; };
Reent_0011df6c *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c1354[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_0011df6c;

struct Cdeque_0011df6c;
struct Iter_0011df6c {
    T_0011df6c *ptr;
    T_0011df6c *beg;
    T_0011df6c *first;
    T_0011df6c *end;
    Iter_0011df6c(T_0011df6c *p, T_0011df6c *b, T_0011df6c *e, T_0011df6c *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter_0011df6c(const Iter_0011df6c &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0011df6c &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_0011df6c &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0011df6c &x, const Iter_0011df6c &y)
{
    T_0011df6c *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_0011df6c {
    T_0011df6c *allocate(unsigned n)
    {
        T_0011df6c *p = (T_0011df6c *)FUN_00000bcc(n * sizeof(T_0011df6c));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c1354);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(T_0011df6c *p) { FUN_00000a00(p); }
    void construct(T_0011df6c *p, const T_0011df6c &v) { new (p) T_0011df6c(v); }
};

struct Cdeque_0011df6c;
extern "C" {
unsigned FUN_0011f440(const Cdeque_0011df6c *self, unsigned n); /* grow-to capacity */
void FUN_0011debc(Cdeque_0011df6c *self);                       /* clear */
}

template <class U> inline void swap_0011df6c(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_0011df6c {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0011df6c *data_;
    Cdeque_0011df6c() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0011df6c()
    {
        if (data_) {
            FUN_0011debc(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_0011df6c begin() { Iter_0011df6c it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_0011df6c end()
    {
        unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0;
        return Iter_0011df6c(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0011df6c &x)
    {
        if (this != &x) {
            ::swap_0011df6c(cap_, x.cap_);
            ::swap_0011df6c(size_, x.size_);
            ::swap_0011df6c(start_, x.start_);
            ::swap_0011df6c(data_, x.data_);
        }
    }
    void push_back(const T_0011df6c &x);
};

extern "C" void FUN_0011df6c(Cdeque_0011df6c *self, const T_0011df6c &x)
{
    Alloc_0011df6c a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_0011f440(self, self->size_ + 1);
        Cdeque_0011df6c tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_0011df6c *p = tmp.data_;
        Iter_0011df6c e = self->end();
        for (Iter_0011df6c i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
