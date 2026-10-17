/* HSTMATCH module=hstp_trans_main.prx start=0x00129140 end=0x00129384 symbol=FUN_00129140 lang=c++ */
/* Clone of src/eboot/cdeque_push_back_0011d894.cpp (hstclone.py tag u6fr2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin near miss wip/cdeque_push_back_00129140.cpp: Iter has a user-declared copy constructor, begin() returns a named local and operator< reads x.first once); exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: push_back(x). Fast path constructs at (start + size) % cap;
   otherwise grow to the capacity from 0x12a6e4 into a temporary cdeque, copy the elements through the
   wrap-aware iterator operator<, construct x, swap, and let the temporary's destructor clear (0x1289b8) and free
   the old buffer. The user-declared Iter copy constructor plus begin() building a named local is what makes
   the begin pointer the register that holds data + start * 4. Names provisional. */
extern "C" {
struct Reent_00129140 { int pad[3]; void *err; };
Reent_00129140 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002d1734[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_00129140;

struct Cdeque_00129140;
struct Iter_00129140 {
    T_00129140 *ptr;
    T_00129140 *beg;
    T_00129140 *first;
    T_00129140 *end;
    Iter_00129140(T_00129140 *p, T_00129140 *b, T_00129140 *e, T_00129140 *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter_00129140(const Iter_00129140 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_00129140 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_00129140 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_00129140 &x, const Iter_00129140 &y)
{
    T_00129140 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_00129140 {
    T_00129140 *allocate(unsigned n)
    {
        T_00129140 *p = (T_00129140 *)FUN_00000bcc(n * sizeof(T_00129140));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d1734);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(T_00129140 *p) { FUN_00000a00(p); }
    void construct(T_00129140 *p, const T_00129140 &v) { new (p) T_00129140(v); }
};

struct Cdeque_00129140;
extern "C" {
unsigned FUN_0012a614(const Cdeque_00129140 *self, unsigned n); /* grow-to capacity */
void FUN_00129090(Cdeque_00129140 *self);                       /* clear */
}

template <class U> inline void swap_00129140(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_00129140 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_00129140 *data_;
    Cdeque_00129140() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_00129140()
    {
        if (data_) {
            FUN_00129090(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_00129140 begin() { Iter_00129140 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_00129140 end()
    {
        unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0;
        return Iter_00129140(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_00129140 &x)
    {
        if (this != &x) {
            ::swap_00129140(cap_, x.cap_);
            ::swap_00129140(size_, x.size_);
            ::swap_00129140(start_, x.start_);
            ::swap_00129140(data_, x.data_);
        }
    }
    void push_back(const T_00129140 &x);
};

extern "C" void FUN_00129140(Cdeque_00129140 *self, const T_00129140 &x)
{
    Alloc_00129140 a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_0012a614(self, self->size_ + 1);
        Cdeque_00129140 tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_00129140 *p = tmp.data_;
        Iter_00129140 e = self->end();
        for (Iter_00129140 i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
