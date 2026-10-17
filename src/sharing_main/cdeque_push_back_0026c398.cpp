/* HSTMATCH module=hstp_trans_main.prx start=0x0026c398 end=0x0026c5dc symbol=FUN_0026c398 lang=c++ */
/* Clone of src/eboot/cdeque_push_back_0011d894.cpp (hstclone.py tag u6fr2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin near miss wip/cdeque_push_back_0026c398.cpp: Iter has a user-declared copy constructor, begin() returns a named local and operator< reads x.first once); exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: push_back(x). Fast path constructs at (start + size) % cap;
   otherwise grow to the capacity from 0x12a6e4 into a temporary cdeque, copy the elements through the
   wrap-aware iterator operator<, construct x, swap, and let the temporary's destructor clear (0x1289b8) and free
   the old buffer. The user-declared Iter copy constructor plus begin() building a named local is what makes
   the begin pointer the register that holds data + start * 4. Names provisional. */
extern "C" {
struct Reent_0026c398 { int pad[3]; void *err; };
Reent_0026c398 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002dad78[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_0026c398;

struct Cdeque_0026c398;
struct Iter_0026c398 {
    T_0026c398 *ptr;
    T_0026c398 *beg;
    T_0026c398 *first;
    T_0026c398 *end;
    Iter_0026c398(T_0026c398 *p, T_0026c398 *b, T_0026c398 *e, T_0026c398 *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter_0026c398(const Iter_0026c398 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_0026c398 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_0026c398 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_0026c398 &x, const Iter_0026c398 &y)
{
    T_0026c398 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_0026c398 {
    T_0026c398 *allocate(unsigned n)
    {
        T_0026c398 *p = (T_0026c398 *)FUN_00000bcc(n * sizeof(T_0026c398));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002dad78);
            FUN_0000d530();
        }
        return p;
    }
    void deallocate(T_0026c398 *p) { FUN_00000a00(p); }
    void construct(T_0026c398 *p, const T_0026c398 &v) { new (p) T_0026c398(v); }
};

struct Cdeque_0026c398;
extern "C" {
unsigned FUN_0026c7e4(const Cdeque_0026c398 *self, unsigned n); /* grow-to capacity */
void FUN_0026af40(Cdeque_0026c398 *self);                       /* clear */
}

template <class U> inline void swap_0026c398(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_0026c398 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_0026c398 *data_;
    Cdeque_0026c398() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_0026c398()
    {
        if (data_) {
            FUN_0026af40(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_0026c398 begin() { Iter_0026c398 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_0026c398 end()
    {
        unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0;
        return Iter_0026c398(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_0026c398 &x)
    {
        if (this != &x) {
            ::swap_0026c398(cap_, x.cap_);
            ::swap_0026c398(size_, x.size_);
            ::swap_0026c398(start_, x.start_);
            ::swap_0026c398(data_, x.data_);
        }
    }
    void push_back(const T_0026c398 &x);
};

extern "C" void FUN_0026c398(Cdeque_0026c398 *self, const T_0026c398 &x)
{
    Alloc_0026c398 a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_0026c7e4(self, self->size_ + 1);
        Cdeque_0026c398 tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_0026c398 *p = tmp.data_;
        Iter_0026c398 e = self->end();
        for (Iter_0026c398 i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
