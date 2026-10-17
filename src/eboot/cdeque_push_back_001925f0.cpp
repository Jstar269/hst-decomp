/* HSTMATCH module=EBOOT.BIN start=0x001925f0 end=0x00192834 symbol=FUN_001925f0 lang=c++ */
/* Clone of src/sharing_main/cdeque_push_back_00128a68.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (adapted from the EBOOT twin near miss wip/cdeque_push_back_0011d894.cpp: Iter has a user-declared copy constructor, begin() returns a named local and operator< reads x.first once); exact match verified; names and types await human review. */
/* MSL-style circular deque (cdeque) of 4-byte elements: push_back(x). Fast path constructs at (start + size) % cap;
   otherwise grow to the capacity from 0x12a6e4 into a temporary cdeque, copy the elements through the
   wrap-aware iterator operator<, construct x, swap, and let the temporary's destructor clear (0x1289b8) and free
   the old buffer. The user-declared Iter copy constructor plus begin() building a named local is what makes
   the begin pointer the register that holds data + start * 4. Names provisional. */
extern "C" {
struct Reent_001925f0 { int pad[3]; void *err; };
Reent_001925f0 *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d518(void);
void *FUN_00000bcc(unsigned size);
void FUN_00000a00(void *p);
extern char DAT_002c2788[]; /* "Memory allocation failure" */
}
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

typedef void *T_001925f0;

struct Cdeque_001925f0;
struct Iter_001925f0 {
    T_001925f0 *ptr;
    T_001925f0 *beg;
    T_001925f0 *first;
    T_001925f0 *end;
    Iter_001925f0(T_001925f0 *p, T_001925f0 *b, T_001925f0 *e, T_001925f0 *f) : ptr(p), beg(b), first(f), end(e) {}
    Iter_001925f0(const Iter_001925f0 &o) : ptr(o.ptr), beg(o.beg), first(o.first), end(o.end) {}
    Iter_001925f0 &operator++()
    {
        if (++ptr == end)
            ptr = beg;
        return *this;
    }
    T_001925f0 &operator*() const { return *ptr; }
};
inline bool operator<(const Iter_001925f0 &x, const Iter_001925f0 &y)
{
    T_001925f0 *f = x.first;
    if (x.ptr >= f) {
        if (y.ptr < f)
            return true;
    } else {
        if (y.ptr >= f)
            return false;
    }
    return x.ptr < y.ptr;
}

struct Alloc_001925f0 {
    T_001925f0 *allocate(unsigned n)
    {
        T_001925f0 *p = (T_001925f0 *)FUN_00000bcc(n * sizeof(T_001925f0));
        if (p == 0) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002c2788);
            FUN_0000d518();
        }
        return p;
    }
    void deallocate(T_001925f0 *p) { FUN_00000a00(p); }
    void construct(T_001925f0 *p, const T_001925f0 &v) { new (p) T_001925f0(v); }
};

struct Cdeque_001925f0;
extern "C" {
unsigned FUN_00192a3c(const Cdeque_001925f0 *self, unsigned n); /* grow-to capacity */
void FUN_00190f50(Cdeque_001925f0 *self);                       /* clear */
}

template <class U> inline void swap_001925f0(U &a, U &b)
{
    U t = a;
    a = b;
    b = t;
}

struct Cdeque_001925f0 {
    unsigned cap_;
    unsigned size_;
    unsigned start_;
    T_001925f0 *data_;
    Cdeque_001925f0() : cap_(0), size_(0), start_(0), data_(0) {}
    ~Cdeque_001925f0()
    {
        if (data_) {
            FUN_00190f50(this);
            FUN_00000a00(data_);
        }
    }
    unsigned size() const { return size_; }
    unsigned capacity() const { return cap_ == 0 ? 0 : cap_ - 1; }
    Iter_001925f0 begin() { Iter_001925f0 it(data_ + start_, data_, data_ + cap_, data_ + start_); return it; }
    Iter_001925f0 end()
    {
        unsigned i = cap_ != 0 ? (start_ + size_) % cap_ : 0;
        return Iter_001925f0(data_ + i, data_, data_ + cap_, data_ + start_);
    }
    void swap(Cdeque_001925f0 &x)
    {
        if (this != &x) {
            ::swap_001925f0(cap_, x.cap_);
            ::swap_001925f0(size_, x.size_);
            ::swap_001925f0(start_, x.start_);
            ::swap_001925f0(data_, x.data_);
        }
    }
    void push_back(const T_001925f0 &x);
};

extern "C" void FUN_001925f0(Cdeque_001925f0 *self, const T_001925f0 &x)
{
    Alloc_001925f0 a;
    if (self->size_ < self->capacity()) {
        a.construct(self->data_ + (self->start_ + self->size_) % self->cap_, x);
        ++self->size_;
    } else {
        unsigned n = FUN_00192a3c(self, self->size_ + 1);
        Cdeque_001925f0 tmp;
        tmp.data_ = a.allocate(n + 1);
        tmp.cap_ = n + 1;
        T_001925f0 *p = tmp.data_;
        Iter_001925f0 e = self->end();
        for (Iter_001925f0 i = self->begin(); i < e; ++i, ++p, ++tmp.size_)
            a.construct(p, *i);
        a.construct(p, x);
        ++tmp.size_;
        tmp.swap(*self);
    }
}
