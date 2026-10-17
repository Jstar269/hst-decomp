/* HSTMATCH module=hstp_trans_main.prx start=0x00128a68 end=0x00128cac symbol=FUN_00128a68 lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin near miss wip/cdeque_push_back_0011d894.cpp: Iter has a user-declared copy constructor, begin() returns a named local and operator< reads x.first once); exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: push_back(x). Fast path constructs at (start + size) % cap;
   otherwise grow to the capacity from 0x12a6e4 into a temporary cdeque, copy the elements through the
   wrap-aware iterator operator<, construct x, swap, and let the temporary's destructor clear (0x1289b8) and free
   the old buffer. The user-declared Iter copy constructor plus begin() building a named local is what makes
   the begin pointer the register that holds data + start * 4. Names provisional. */
extern "C" {
struct Reent_00128a68 { int pad[3]; void *err; };
Reent_00128a68 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d176c[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_00128a68;

struct Cdeque_00128a68;
struct Iter_00128a68 {
    T_00128a68 *ptr;
    T_00128a68 *beg;
    T_00128a68 *first;
    T_00128a68 *end;
    Iter_00128a68(T_00128a68 *p, T_00128a68 *b, T_00128a68 *e, T_00128a68 *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter_00128a68(const Iter_00128a68 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_00128a68 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_00128a68 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_00128a68 &x, const Iter_00128a68 &y)
{
    T_00128a68 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_00128a68 {
    T_00128a68 *allocate(unsigned n)
    {
        T_00128a68 *p = (T_00128a68 *)FUN_00000bcc(n * sizeof(T_00128a68));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d176c);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(T_00128a68 *p) { FUN_00000a00(p); }
    void construct(T_00128a68 *p, const T_00128a68 &v) { new (p) T_00128a68(v); }
};

struct Cdeque_00128a68;
extern "C" {
unsigned FUN_0012a6e4(const Cdeque_00128a68 *self, unsigned n); /* grow-to capacity */
void FUN_001289b8(Cdeque_00128a68 *self);                       /* clear */
}

template <class U> inline void swap_00128a68(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_00128a68 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_00128a68 *data_;
    Cdeque_00128a68() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_00128a68()
    {
        if (data_) {
            FUN_001289b8(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_00128a68 begin() { Iter_00128a68 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_00128a68 end()
    {
        unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0;
        return Iter_00128a68(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_00128a68 &x)
    {
        if (this != &x) {
            ::swap_00128a68(cap_, x.cap_);
            ::swap_00128a68(size_, x.size_);
            ::swap_00128a68(start_, x.start_);
            ::swap_00128a68(data_, x.data_);
        }
    }
    void push_back(const T_00128a68 &x);
};

extern "C" void FUN_00128a68(Cdeque_00128a68 *self, const T_00128a68 &x)
{
    Alloc_00128a68 a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_0012a6e4(self, self->size_ + 1);
        Cdeque_00128a68 tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_00128a68 *p = tmp.data_;
        Iter_00128a68 e = self->end();
        for (Iter_00128a68 i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
