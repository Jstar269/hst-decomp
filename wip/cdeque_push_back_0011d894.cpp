/* HSTMATCH module=EBOOT.BIN start=0x0011d894 end=0x0011dad8 symbol=FUN_0011d894 lang=c++ */
extern "C" {
struct Reent_0011d894 { int pad[3]; void *err; };
Reent_0011d894 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c138c[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_0011d894;

struct Cdeque_0011d894;
struct Iter_0011d894 {
    T_0011d894 *ptr;
    T_0011d894 *beg;
    T_0011d894 *first;
    T_0011d894 *end;
    Iter_0011d894(const Cdeque_0011d894 *c, unsigned i);
    Iter_0011d894 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_0011d894 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0011d894 &x, const Iter_0011d894 &y)
{
    if (x.ptr >= x.first) {
        if (y.ptr < y.first)
            return true;
    } else {
        if (y.ptr >= y.first)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_0011d894 {
    T_0011d894 *allocate(unsigned n)
    {
        T_0011d894 *p = (T_0011d894 *)FUN_00000bcc(n * sizeof(T_0011d894));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c138c);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(T_0011d894 *p) { FUN_00000a00(p); }
    void construct(T_0011d894 *p, const T_0011d894 &v) { new (p) T_0011d894(v); }
};

struct Cdeque_0011d894;
extern "C" {
unsigned FUN_0011f510(const Cdeque_0011d894 *self, unsigned n); /* grow-to capacity */
void FUN_0011d7e4(Cdeque_0011d894 *self);                       /* clear */
}

template <class U> inline void swap_0011d894(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_0011d894 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0011d894 *data_;
    Cdeque_0011d894() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0011d894()
    {
        if (data_) {
            FUN_0011d7e4(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_0011d894 begin() const { return Iter_0011d894(this, start_); }
    Iter_0011d894 end() const { return Iter_0011d894(this, cap_ != 0 ? (start_ + size_) % cap_ : 0); }
    void swap(Cdeque_0011d894 &x)
    {
        if (this != &x) {
            ::swap_0011d894(cap_, x.cap_);
            ::swap_0011d894(size_, x.size_);
            ::swap_0011d894(start_, x.start_);
            ::swap_0011d894(data_, x.data_);
        }
    }
    void push_back(const T_0011d894 &x);
};

inline Iter_0011d894::Iter_0011d894(const Cdeque_0011d894 *c, unsigned i)
    : ptr(c->data_ + i), beg(c->data_), first(c->data_ + c->start_), end(c->data_ + c->cap_) {}

extern "C" void FUN_0011d894(Cdeque_0011d894 *self, const T_0011d894 &x)
{
    Alloc_0011d894 a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_0011f510(self, self->size_ + 1);
        Cdeque_0011d894 tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_0011d894 *p = tmp.data_;
        Iter_0011d894 e = self->end();
        for (Iter_0011d894 i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
// WIP (2026-10-15, agent fam1-00): 11 words from exact, register allocation only. MSL cdeque<T*>::push_back:
// fast path, else grow into a temporary cdeque (copy loop with the wrap-aware iterator operator<, shared
// final `return x.ptr < y.ptr`), construct x, swap, destroy. Everything else matches. In the copy loop retail
// keeps begin().ptr in the register that holds data+start*4 (t2) and copies it into t1 for `first`; we copy
// the other way (first stays in a3, ptr is the copy), rotating data/end.ptr/first among t0/t1/a3. The same
// loop in reserve 0x11dad8 compiles to OUR allocation, so the loop source is likely right and the difference
// comes from push_back's surroundings. Ruled out: x.first/y.first in each test, begin()/end() order (end must
// be first), 4-pointer / (data,cap,start,i) / (container,index) iterator ctors, ctor-body forms, const_iterator
// copies, by-value range helper, Alloc temporaries, p/tmp declaration order, early return, while form.
